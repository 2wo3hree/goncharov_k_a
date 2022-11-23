#include <iostream>
#include "Complex.h"



Complex::Complex(double re, double im)
{
   this-> re = re;
   this-> im = im;

}

Complex::Complex(double re)
{
    this->re = re;
    this->im = 0;
}

Complex::Complex()
{
    this->re = 0;
    this->im = 0;
}

bool Complex::isZero() const
{
    return re == 0 && im == 0;
}




Complex& Complex::operator=(const Complex& other)
{
    re = other.re;
    im = other.im;
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re * rhs.re - lhs.im * rhs.im, lhs.im * rhs.re + lhs.re * rhs.im);
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{

    if (rhs.isZero())
    {
        throw  "Division error by zero!";
    }
    
    else
    {
        return Complex((lhs.re * rhs.re + lhs.im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im), (lhs.im * rhs.re - lhs.re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im));
    }
}



Complex& Complex::operator+=(const Complex& other)
{
    re += other.re;
    im += other.im;
    return *this;
}



Complex& Complex::operator-=(const Complex& chis)
{
    re -= chis.re;
    im -= chis.im;
    return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
    double real_temp;
    double image_temp;
    real_temp = (re * other.re) - (im * other.im);
    image_temp = (im * other.re) + (re * other.im);
    re = real_temp;
    im = image_temp;
    return *this;
}

Complex& Complex::operator/=(const Complex& other)
{
    if (isZero())
    {
        throw  "Division error by zero!";
    }
    

    double re_temp;
    double im_temp;
    re_temp = (re * other.re + im * other.im) / (other.re * other.re + other.im * other.im);
    im_temp = (im * other.re - re * other.im) / (other.re * other.re + other.im * other.im);
    re = re_temp;
    im = im_temp;
    return *this;
}

bool Complex::operator==(const Complex& other) const
{
    return std::abs(re - other.re) < k2Eps && std::abs(im - other.im) < k2Eps;
}

bool Complex::operator!=(const Complex& other) const
{
    return !(operator==(other));
}

Complex Complex::operator-() const
{
    return Complex( - re, -im );
}

Complex Complex::operator+() const
{
    return *this;
}

std::ostream& operator<<(std::ostream& ostream, const Complex& data) {
    ostream << data.LeftBracket << data.re << data.Comma <<
        data.im << data.RightBracket;
    return ostream;
}

std::istream& operator>>(std::istream& istream, Complex& data) {
    char left_bracket;
    double re;
    char comma;
    double im;
    char right_bracket;
    istream >> left_bracket >> re >> comma >> im >> right_bracket;
    if (istream.good()) {
        if (left_bracket == Complex::LeftBracket && comma == Complex::Comma && right_bracket == Complex::RightBracket)
        {
            data.re = re;
            data.im = im;
        }
        else
        {
            istream.setstate(std::ios_base::failbit);
        }
    }
    return istream;
}