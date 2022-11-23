#include <iostream>
#include <vector>
#include <stdint.h>
#include "bitsetd.h"

Interval::Interval(int a, int b) {
	this->a = a;
	this->b = b;
	int size_ = abs(b - a);
}
Interval::Interval() {
	this->a = 0;
	this->b = 0;
}
int Interval::size() const {
	return size_;
}
bool Interval::operator==(const Interval& a_b) const {
	if (a_b.size() == size_)
		return true;
	else
		return false;
}
bool Interval::operator!=(const Interval& a_b) const {
    return !(operator==(a_b));
}
Interval& Interval::operator=(const Interval& a_b) {
	a = a_b.a;
	b = a_b.b;
	return *this;
}
Interval& Interval::operator*=(const int k) {
	if (size_ % 2 != 0) {
		if (k % 2 != 0) {
			a -= (k * size_ - size_) / 2;
			b -= (k * size_ - size_) / 2 + 1;
		else
		{
			a -= (k * size_ - size_) / 2;
			b -= (k * size_ - size_) / 2;
		}}

	}
	else {
		a -= (k * size_ - size_) / 2;
		b -= (k * size_ - size_) / 2;
	}
	return *this;
}
Interval& Interval::operator/=(const int k) {


	return *this;

}