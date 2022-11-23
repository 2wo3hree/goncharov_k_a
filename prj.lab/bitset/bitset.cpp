#include <iostream>
#include <vector>
#include <stdint.h>
#include "bitset.h"


Bitset::BitHolder::BitHolder(uint32_t& cell, const int position_) : el_data(cell), position(position_) {}// инициализация полей

typename Bitset::BitHolder Bitset::operator[](const int64_t position) {
	int k = position / one_size;
	return BitHolder(data_[k], position - one_size * k);
}
Bitset::BitHolder& Bitset::BitHolder::operator=(const bool rhs) {
	uint32_t mask = 1;
	mask <<= position;
	if (rhs) {
        el_data|=mask;
	}
	else { 
		el_data &= ~mask;
	}

	return *this;
}
Bitset::BitHolder::operator bool() const { // должно работать
	uint32_t mask = 1;
	mask <<= position;
	uint32_t el_data_2 = el_data | mask;
	if (el_data_2 == el_data)
		return true;
	else
		return false;
}
Bitset::Bitset(const int64_t size, const bool filler) {
	if(size<0)
		throw std::invalid_argument("Bitset error: Bitset size can not be negative");
	else {
		size_ = size;
		int cell = size_ % one_size == 0 ? (size / one_size) : (1 + size / one_size);
		std::vector<uint32_t> vector_temp(cell);
		uint32_t temp = 0;
		if (filler)
			temp = ~temp;
		for (int i = 0; i < cell; i++)
		{
			vector_temp[i] = temp;
		}

		data_ = vector_temp;
	}
}
int64_t Bitset::size() const {
	return size_;
 }
void Bitset::resize(const int64_t size, const bool filler) {
	if (size < 0)
		throw std::invalid_argument("Bitset error: Bitset size can not be negative");

	if (size < size_) {
		 *this <<= (size_ - size);
		 size_ = size;
	}

	else  {
		for (int i = 0; i < size - size_; i++)
			data_.push_back(0);

		*this >>= (size - size_);

		for (int i = 0; i < size - size_; i++)
			this[i] = filler;

		size_ = size;
	}
}
Bitset& Bitset::operator=(const Bitset& rhs) {
	size_ = rhs.size_;
	data_ = rhs.data_;

	return *this;
}
Bitset& Bitset::operator&=(const Bitset& rhs) {
	if (size_ == rhs.size_)
		for (int i = 0; i <= size_/one_size; i++)
			data_[i] &= rhs.data_[i];

	else
		throw std::logic_error("Bitset error: sizes of operands do not match");

	return *this;
}
Bitset& Bitset::operator|=(const Bitset& rhs) {
	if (size_ == rhs.size_)
		for (int i = 0; i <= size_/one_size; i++)
			data_[i] |= rhs.data_[i];

	else
		throw std::logic_error("Bitset error: sizes of operands do not match");

	return *this;
}
Bitset& Bitset::operator^=(const Bitset& rhs) {
	if (size_ == rhs.size_)
		for (int i = 0; i <= size_ / one_size; i++)
			data_[i] ^= rhs.data_[i];

	else
		throw std::logic_error("Bitset error: sizes of operands do not match");

	return *this;
}
Bitset Bitset:: operator~() const {
	Bitset result(*this);

	for (int i = 0; i <= size_ / one_size; i++)
		result.data_[i] = ~result.data_[i];

	return result;
}
Bitset operator&(const Bitset& lhs, const Bitset& rhs) {
	Bitset result = lhs;
	result &= rhs;

	return result;
}

Bitset operator|(const Bitset& lhs, const Bitset& rhs) {
	Bitset result = lhs;
	result |= rhs;

	return result;
}

Bitset operator^(const Bitset& lhs, const Bitset& rhs) {
	Bitset result = lhs;
	result ^= rhs;

	return result;
}
bool Bitset::operator==(Bitset& rhs) {
	if (size_ != rhs.size())
		return false;

	for (int i = 0; i < size_; i++)
		if ((*this)[i] != rhs[i])
			return false;

	return true;
}

bool Bitset::operator!=(Bitset& rhs)  {
	return !(operator==(rhs));
}
Bitset& Bitset::operator<<=(const int64_t rhs) {
	if (rhs < 0)
		throw std::invalid_argument("Bitset error: bitwise shift by negative count is undefined");

	else if (rhs==0)
		return *this;

	else
		for (int64_t j = 0; j < rhs; j++) {
			for (int64_t i = 0; i < size_ - 1; i++)
				(*this)[i] = (*this)[i + 1].operator bool();

		(* this)[size_ - 1] = 0;
		}

	return *this;
}
Bitset& Bitset::operator>>=(const int64_t rhs) {
	if (rhs < 0)
		throw std::invalid_argument("Bitset error: bitwise shift by negative count is undefined");

	else if (!rhs)
		return *this;

	else
		for (int64_t j = 0; j < rhs; j++) {
			for (int64_t i = size_ - 1; i > 0; i--)
				(* this)[i] = (*this)[i - 1].operator bool();
			(*this)[0] = 0;
		}

	return *this;
}
Bitset operator<<(const Bitset& lhs, const int64_t rhs) {
	Bitset result = lhs;
	result <<= rhs;

	return result;
}
Bitset operator>>(const Bitset& lhs, const int64_t rhs) {
	Bitset result = lhs;
	result >>= rhs;

	return result;
}
std::ostream& Bitset::WriteTo(std::ostream& ostream)  {
	for (int64_t i = 0; i < size_; i++) {
		uint32_t mask = 1 << (i % one_size);
		ostream << ((data_[i / one_size] & mask) != 0 ? 1 : 0);
	}

	return ostream;
}

std::istream& Bitset::ReadFrom(std::istream& istream) {
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
}
bool Bitset::operator[](const int64_t position) const {
	if (position >= size_ || position < 0) 
		throw std::out_of_range("Bitset error: index out of range");
	uint32_t a = data_[position / one_size];
	return (a & (uint32_t(1) << position % one_size));
};