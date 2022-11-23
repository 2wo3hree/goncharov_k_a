#pragma once
#ifndef interval
#define interval

#include <iosfwd>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <initializer_list>
#include <vector>

class Interval {
private:
public: 
	int a;
	int b;

	Interval(int a_, int b_);
	Interval();

	int size() const;

	bool operator==(const Interval& a_b) const;
	bool operator!=(const Interval& a_b) const;
	Interval& operator=(const Interval& a_b);
	Interval& operator*=(const int k);
	Interval& operator/=(const int k);
};



#endif 
