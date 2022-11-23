#ifndef RATIONAL
#define RATIONAL

#include <cstdint>
#include <iosfwd>
#include <stdexcept>


class Rational {
private:

    int chis = 0;
    int znam = 1;
    static const char Comma{ '/' };

public:


    Rational operator++(int);
    Rational operator--(int);

    Rational& operator++();
    Rational& operator--();

    ~Rational() = default;

    Rational(int chis, int znam);
    Rational(int chis);
    Rational();

    bool isZero() const;
    void reduce();
    int get_chis() const;
    int get_znam() const;
    void set_chis(int& number);
    void set_znam(int& number);

    bool operator<(const Rational& drob_1)const;
    bool operator<=(const Rational& drob_1)const;
    bool operator==(const Rational& drob_1)const;
    bool operator>(const Rational& drob_1)const;
    bool operator>=(const Rational& drob_1)const;
    bool operator!=(const Rational& drob_1)const;

    Rational& operator=(const Rational& znach);
    Rational& operator+=(const Rational& znach);
    Rational& operator-=(const Rational& znach);
    Rational& operator*=(const Rational& znach);
    Rational& operator/=(const Rational& znach);

    Rational operator-() const;
    Rational operator+() const;

    Rational operator+(const Rational& rhs) const;
    Rational operator-(const Rational& rhs) const;
    Rational operator/(const Rational& rhs) const;
    Rational operator*(const Rational& rhs) const;

    friend std::ostream& operator<<(std::ostream& ostream, const Rational& data);
    friend std::istream& operator>>(std::istream& istream, Rational& data);

};




#endif