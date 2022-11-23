#pragma once
#ifndef BITSETT
#define BITSETT

#include <iosfwd>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <initializer_list>
#include <vector>

template <typename T>
class Bitsett {
private:
	int64_t size_ = 0;
	std::vector<T> data_{ 0 };
	int one_size = sizeof(T) * 8;
public:
	class BitHolder {
	public:
		friend class Bitsett;
		BitHolder& operator=(const bool rhs) {
			T mask = 1;
			mask <<= position;
			if (rhs) {
				el_data |= mask;
			}
			else {
				el_data &= ~mask;
			}

			return *this;
		};
		~BitHolder() = default;
		operator bool() const {
			T mask = 1;
			mask <<= position;
			T el_data_2 = el_data | mask;
			if (el_data_2 == el_data)
				return true;
			else
				return false;
		};

	private:
		BitHolder(T& cell, const int64_t position_) : el_data(cell), position(position_) {};
		T& el_data;
		int position;
	};



	Bitsett<T>(const int64_t size = 0, const bool filler = false) {
		if (size < 0)
			throw std::invalid_argument("Bitset error: Bitset size can not be negative");
		else {
			size_ = size;
			int cell = size_ % one_size == 0 ? (size / one_size) : (1 + size / one_size);
			std::vector<T> vector_temp(cell);
			T temp = 0;
			if (filler)
				temp = ~temp;
			for (int i = 0; i < cell; i++)
			{
				vector_temp[i] = temp;
			}

			data_ = vector_temp;
		}
	};
	Bitsett<T>(const Bitsett<T>& copy) = default;

	Bitsett<T>& operator=(const Bitsett<T>& rhs) {
		size_ = rhs.size_;
		data_ = rhs.data_;

		return *this;
	};
	Bitsett<T>& operator&=(const Bitsett<T>& rhs) {
		if (size_ == rhs.size_)
			for (int i = 0; i <= size_ / one_size; i++)
				data_[i] &= rhs.data_[i];

		else
			throw std::logic_error("Bitset error: sizes of operands do not match");

		return *this;
	};
	Bitsett<T>& operator|=(const Bitsett<T>& rhs) {
		if (size_ == rhs.size_)
			for (int i = 0; i <= size_ / one_size; i++)
				data_[i] |= rhs.data_[i];

		else
			throw std::logic_error("Bitset error: sizes of operands do not match");

		return *this;
	};
	Bitsett<T>& operator^=(const Bitsett<T>& rhs) {
		if (size_ == rhs.size_)
			for (int i = 0; i <= size_ / one_size; i++)
				data_[i] ^= rhs.data_[i];

		else
			throw std::logic_error("Bitset error: sizes of operands do not match");

		return *this;
	};
	Bitsett<T>& operator<<=(const int64_t rhs) {
		if (rhs < 0)
			throw std::invalid_argument("Bitset error: bitwise shift by negative count is undefined");

		else if (rhs == 0)
			return *this;

		else
			for (int64_t j = 0; j < rhs; j++) {
				for (int64_t i = 0; i < size_ - 1; i++)
					(*this)[i] = (*this)[i + 1].operator bool();

				(*this)[size_ - 1] = 0;
			}

		return *this;
	};
	Bitsett<T>& operator>>=(const int64_t rhs) {
		if (rhs < 0)
			throw std::invalid_argument("Bitset error: bitwise shift by negative count is undefined");

		else if (!rhs)
			return *this;

		else
			for (int64_t j = 0; j < rhs; j++) {
				for (int64_t i = size_ - 1; i > 0; i--)
					(*this)[i] = (*this)[i - 1].operator bool();
				(*this)[0] = 0;
			}

		return *this;
	};

	~Bitsett<T>() = default;


	bool operator==(Bitsett<T>& rhs) {
		if (size_ != rhs.size())
			return false;

		for (int i = 0; i < size_; i++)
			if ((*this)[i] != rhs[i])
				return false;

		return true;
	};
	bool operator!=(Bitsett<T>& rhs) {
		return !(operator==(rhs));
	};

	Bitsett<T> operator~() const {
		Bitsett<T> result(*this);

		for (int i = 0; i <= size_ / one_size; i++)
			result.data_[i] = ~result.data_[i];

		return result;
	};

	BitHolder operator[](const int64_t position) {
		int k = position / one_size;
		return BitHolder(data_[k], position - one_size * k);
	};

	int64_t size() const {
		return size_;
	};
	void resize(const int64_t size, const bool filler = false) {
		if (size < 0)
			throw std::invalid_argument("Bitset error: Bitset size can not be negative");

		if (size < size_) {
			*this <<= (size_ - size);
			size_ = size;
		}

		else {
			for (int i = 0; i < size - size_; i++)
				data_.push_back(0);

			*this >>= (size - size_);

			for (int i = 0; i < size - size_; i++)
				this[i] = filler;

			size_ = size;
		}
	};

	std::ostream& WriteTo(std::ostream& ostrm) {
		for (int64_t i = 0; i < size_; i++) {
			uint32_t mask = 1 << (i % one_size);
			ostream << ((data_[i / one_size] & mask) != 0 ? 1 : 0);
		}

		return ostream;
	};
	std::istream& ReadFrom(std::istream& istrm) {
		int c = 1;
		int64_t i = 0;

		while (istream.good()) {

			if (i % sizeof(uint32_t) * 8 == 0) {
				(*this).resize(one_size * c);
				++c;
			}

			char a = istream.peek();

			if (a == '1' || a == '0')
				(*this)[i] = istream.get();

			else
				break;

			i++;
		}

		size_ = i;
		return istream;
	};

};

template <typename T>
Bitsett<T> operator&(const Bitsett<T>& lhs, const Bitsett<T>& rhs) {
	Bitsett<T> result = lhs;
	result &= rhs;

	return result;
};
template <typename T>
Bitsett<T> operator|(const Bitsett<T>& lhs, const Bitsett<T>& rhs) {
	Bitsett<T> result = lhs;
	result |= rhs;

	return result;
};
template <typename T>
Bitsett<T> operator^(const Bitsett<T>& lhs, const Bitsett<T>& rhs) {
	Bitsett<T> result = lhs;
	result ^= rhs;

	return result;
};
template <typename T>
Bitsett<T> operator>>(const Bitsett<T>& lhs, const int64_t rhs) {
	Bitsett<T> result = lhs;
	result >>= rhs;

	return result;
};
template <typename T>
Bitsett<T> operator<<(const Bitsett<T>& lhs, const int64_t rhs) {
	Bitsett<T> result = lhs;
	result <<= rhs;

	return result;
};



#endif 
