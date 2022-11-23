#ifndef COMPLEX
#define COMPLEX

#include <iosfwd>
#include <stdexcept>
#include <limits>

class Complex
{
private:

    

public:

    double re;
    double im;

    static constexpr double k2Eps{ 2.0 * std::numeric_limits<double>::epsilon() };

    static const char LeftBracket{ '{' };
    static const char Comma{ ',' };
    static const char RightBracket{ '}' };

    bool operator==(const Complex& drob_1) const;
    bool operator!=(const Complex& drob_1) const;

    Complex(double real, double image);
    Complex(double real);
    Complex();

    bool isZero() const;

    //изменяет существующие
    Complex& operator=(const Complex& value);
    Complex& operator+=(const Complex& value);
    Complex& operator-=(const Complex& value);
    Complex& operator*=(const Complex& value);
    Complex& operator/=(const Complex& value);
    

    Complex operator+() const;
    Complex operator-() const;

    ~Complex() = default;
};


Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

std::ostream& operator<<(std::ostream& ostream, const Complex& data);
std::istream& operator>>(std::istream& istream,  Complex& data);

#endif