#include "rational.h"
#include <locale>
#include <iostream>

//конструкторы
Rational::Rational(int chis, int znam)
{
    if (znam == 0)
    {
        throw "Error division by zero!";

    }
    else
    {
        if (chis * znam > 0)
        {
            this->chis = abs(chis);
            this->znam = abs(znam);
        }
        else
        {
            this->chis = -abs(chis);
            this->znam = abs(znam);
        }
        reduce();
    }
}

Rational::Rational(int chis) {
    this->chis = chis;
    this->znam = 1;
}

Rational::Rational() {
    this->chis = 0;
    this->znam = 1;
}
//методы
bool Rational::isZero() const
{
    if (chis == 0)
    {
        return true;
    }
    else
    {
        return false;
    };
}

void Rational::reduce()
{
    if (chis > 0)
    {
        int temp_chis = chis;
        int temp_znam = znam;
        while ((temp_chis) != (temp_znam))
        {
            if (temp_chis > temp_znam) {
                temp_chis = temp_chis - temp_znam;
            }
            else {
                temp_znam = temp_znam - temp_chis;
            }
        }
        chis /= temp_chis;
        znam /= temp_chis;
    }
    else
    {
        if (chis == 0)
        {
            znam = 1;
        }
        else
        {
            int temp_chis = -chis, temp_znam = znam;
            while ((temp_chis) != (temp_znam))
            {
                if (temp_chis > temp_znam) {
                    temp_chis = temp_chis - temp_znam;
                }
                else {
                    temp_znam = temp_znam - temp_chis;
                }
            }
            chis /= temp_chis;
            znam /= temp_chis;
                ;
        }
    }
}

int Rational::get_chis()const
{
    return chis;
}

int Rational::get_znam()const
{
    return znam;
}

void Rational::set_chis(int& num)
{
    chis = num;
}

void Rational::set_znam(int& num)
{
    znam = num;
}
//сокращенная арифметика
Rational Rational::operator-() const {
    return Rational{ -chis, znam };
}

Rational Rational::operator+() const {
    return *this;
}

Rational& Rational::operator++()
{
    chis += znam;
    return *this;
}

Rational& Rational::operator--() {
    chis -= znam;
    reduce();
    return *this;
}
//префмксный
Rational Rational::operator++(int) {
    Rational copy(*this);
    operator++();
    return copy;
}

Rational Rational::operator--(int) {
    Rational copy(*this);
    operator--();
    return copy;
}

std::ostream& operator<<(std::ostream& ostream, const Rational& data) {
    ostream << data.chis << data.Comma << data.znam;
    return ostream;
}

std::istream& operator >> (std::istream& istream, Rational& drob) {
    istream >> drob.chis;
    char comma('  '); 
    istream >> std::noskipws;
    if (istream.peek() != '/') {
        istream.setstate(std::ios_base::failbit);
    }
    istream >> comma;
    if (istream.peek() == '-' || istream.peek() == ' ') {
        istream.setstate(std::ios_base::failbit);
    }
    istream >> drob.znam >> std::skipws;
    if (drob.znam == 0)
    {
        throw(std::exception("Division error by zero!"));
    }
    drob.reduce();
    return istream;
}

Rational& Rational::operator=(const Rational& drob)
{
    chis = drob.chis;
    znam = drob.znam;
    return *this;
}

Rational& Rational::operator+=(const Rational& drob)
{
    chis = (chis * drob.znam) + (drob.chis * znam);
    znam = znam * drob.znam;
    reduce();
    return *this;
}

Rational& Rational:: operator*=(const Rational& drob)
{
    chis = chis * drob.chis;
    znam = znam * drob.znam;
    reduce();
    return *this;
}

Rational& Rational:: operator/=(const Rational& drob)
{
    

    if (drob.chis == 0) {
        throw  "Division error by zero!";
    }
    
    else
    {
        if (drob.chis * drob.znam > 0)
        {
            chis = chis * drob.znam;
            znam = znam * drob.chis;
        }
        else
        {
            chis = -(chis * abs(drob.znam));
            znam = znam * abs(drob.chis);
        }
        reduce();
    }
    return *this;

}

Rational& Rational:: operator-=(const Rational& drob)
{
    chis = (chis * drob.znam) - (drob.chis * znam);
    znam = znam * drob.znam;
    reduce();
    return *this;
}

Rational Rational::operator+(const Rational& drob) const
{
   
    return Rational(chis * drob.get_znam() + (znam * drob.get_chis()), znam * drob.get_znam());
}

Rational Rational:: operator-(const Rational& drob) const
{
    return Rational(chis * drob.get_znam() - znam * drob.get_chis(), znam * drob.get_znam());
}

Rational Rational:: operator*(const Rational& drob) const
{
    return Rational(chis * drob.get_chis(), znam * drob.get_znam());
}

Rational Rational::operator / (const Rational& copy) const {
    Rational temp(*this);
    return temp /= copy;
}

bool Rational::operator==(const Rational& other_drob) const
{
    return ((chis == other_drob.get_chis()) && (other_drob.get_znam() == znam));
}

bool Rational::operator!=(const Rational& other_drob) const
{
    return !(operator==(other_drob));
}

bool Rational::operator<(const Rational& other_drob) const
{
    return ((chis * other_drob.get_znam()) < (other_drob.get_chis() * znam));
}

bool Rational::operator>(const Rational& other_drob) const
{
    return ((chis * other_drob.get_znam()) > (other_drob.get_chis() * znam));
}

bool Rational::operator<=(const Rational& other_drob) const
{
    return ((chis * other_drob.get_znam()) <= (other_drob.get_chis() * znam));
}

bool Rational::operator>=(const Rational& other_drob) const
{
    return ((chis * other_drob.get_znam()) >= (other_drob.get_chis() * znam));
}