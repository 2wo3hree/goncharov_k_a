#pragma once
#ifndef BITSET
#define BITSET

#include <iosfwd>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <initializer_list>
#include <vector>


class Bitset {
private:
	int64_t size_ = 0;
	std::vector<uint32_t> data_{ 0 };
	int one_size = sizeof(uint32_t) * 8; // 32 bit 
public:
	class BitHolder {
	public:
		friend class Bitset;
		BitHolder& operator=(const bool rhs);	
		~BitHolder()=default;
        operator bool() const;

	private:
		BitHolder(uint32_t& cell, const int position_);// cell - €чейка 
		uint32_t& el_data;
		int position;
	};



	Bitset(const int64_t size = 0, const bool filler = false);// filler-наполнитель
	Bitset(const Bitset& copy)=default;

	Bitset& operator=(const Bitset& rhs);
	Bitset& operator&=(const Bitset& rhs);
	Bitset& operator|=(const Bitset& rhs);
	Bitset& operator^=(const Bitset& rhs);
	Bitset& operator<<=(const int64_t rhs);
	Bitset& operator>>=(const int64_t rhs);

	~Bitset()=default;
	

	bool operator==(Bitset& rhs) ;
	bool operator!=(Bitset& rhs) ; 

	Bitset operator~() const; //не мен€ет экземпл€р класса
	
	BitHolder operator[](const int64_t position);
	bool operator[](const int64_t position) const;

    int64_t size() const;
	void resize(const int64_t size, const bool filler = false);

	std::ostream& WriteTo(std::ostream& ostrm);
	std::istream& ReadFrom(std::istream& istrm);

};

Bitset operator&(const Bitset& lhs, const Bitset& rhs);
Bitset operator|(const Bitset& lhs, const Bitset& rhs);
Bitset operator^(const Bitset& lhs, const Bitset& rhs);
Bitset operator>>(const Bitset& lhs, const int64_t rhs);
Bitset operator<<(const Bitset& lhs, const int64_t rhs);



#endif 
