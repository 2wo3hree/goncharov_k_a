
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <rational/rational.h>
#include <doctest/doctest.h>
#include <sstream>
#include <vector>

void Equal(const Rational& drob, int chis, int znam) {
    CHECK(drob.get_chis() == chis);
    CHECK(drob.get_znam() == znam);
}

TEST_CASE("testing rational constructor") {
    Equal(Rational(4), 4, 1);

    Equal(Rational(0, 20), 0, 1);

    Equal(Rational(20, -1), -20, 1);

    Equal(Rational(-16, -6), 8, 3);

    Equal(Rational(-62), -62, 1);

    Equal(Rational(25, -5), -5, 1);

    Equal(Rational(6, 3), 2, 1);
}

TEST_CASE("exceptions")
{
    CHECK_THROWS(Rational(2, 44) / Rational(0, 17));
    CHECK_THROWS(Rational(99, 0));
}

TEST_CASE("= test")
{
    Rational a = Rational(2);
    Rational b = Rational(a);
    CHECK(a.get_chis() == b.get_chis());
    CHECK(a.get_chis() == b.get_chis());
}

TEST_CASE("Assignment of Rational value to Rational test") {
    Rational a = Rational(2);
    Rational b = a;
    CHECK(b.get_chis() == doctest::Approx(a.get_chis()));
    CHECK(b.get_znam() == doctest::Approx(a.get_znam()));
}

TEST_CASE("+ test") {
    
    CHECK((Rational(1, 6)+ Rational(1, 6) == Rational(1, 3)));
}

TEST_CASE("++ test") {
    Rational a = Rational(1, 6);
    a++;
    CHECK((a == Rational(7, 6)));
}

TEST_CASE("-- test") {
    Rational a = Rational(1, 6);
    a--;
    CHECK((a == Rational(-5, 6)));
}

TEST_CASE("+= test") {
    Rational a = Rational();
    Rational b = Rational(1, 5);
    a += b;
    CHECK((a == Rational(1, 5)));
}

TEST_CASE("-= test") {
    Rational a = Rational();
    Rational b = Rational(1, 5);
    a -= b;
    CHECK((a == Rational(-1, 5)));
}

TEST_CASE("- test") {
    
    CHECK((Rational(4, 6) - Rational(1, 6) == Rational(1, 2)));
}

TEST_CASE("/ test") {
    Rational a = Rational(4, 6);
    Rational b = Rational(1, 6);
    Rational c = Rational(1, 6);
    Rational final;
    final = a / b / c;
    CHECK((final == Rational(24, 1)));
}

TEST_CASE("* test") {
    Rational a = Rational(1, 6);
    Rational b = Rational(2, 6);
    Rational c = Rational(3, 6);
    Rational final;
    final = a * b * c;
    CHECK((final == Rational(1, 36)));
}

TEST_CASE("*= test") {
    Rational a = Rational(2, 6);
    Rational b = Rational(1, 5);
    a *= b;
    CHECK((a == Rational(1, 15)));
}

TEST_CASE("/= test") {
    Rational a = Rational(1, 6);
    Rational b = Rational(1, 5);
    a /= b;
    CHECK((a == Rational(5, 6)));
}

TEST_CASE("!= test") {
    Rational a = Rational();
    Rational b = Rational(2, 14);
    CHECK((a != b));
}

TEST_CASE("== test") {
    Rational a = Rational();
    Rational b = Rational(a);
    CHECK((a == b));
}

TEST_CASE("< test")
{
    Rational a = Rational(1, 5);
    Rational b = Rational(4, 10);
    CHECK((a < b));
}

TEST_CASE("> test")
{
    Rational a = Rational(1, 5);
    Rational b = Rational(1, 10);
    CHECK((a > b));
}

TEST_CASE("<= test")
{
    Rational a = Rational(1, 5);
    Rational b = Rational(2, 10);
    CHECK((a <= b));
}

TEST_CASE(">= test")
{
    Rational a = Rational(1, 5);
    Rational b = Rational(2, 10);
    CHECK((a >= b));
}

TEST_CASE("out") {
    std::stringstream stream;
    Rational drob = Rational(3, -19);
    stream << drob;
    std::string str;
    stream >> str;
    CHECK(str == "-3/19");
}

TEST_CASE("in") {
    std::stringstream potok("1/9  -5/5  19/1 0/100 -12/6 10/0 10/-0;");
    Rational test;
    potok >> test;
    CHECK((test == Rational(1, 9)));
    potok >> test;
    CHECK((test == Rational(-1, 1)));
    potok >> test;
    CHECK((test == Rational(19, 1)));
    potok >> test;
    CHECK((test == Rational(0, 100)));
    potok >> test;
    CHECK((test == Rational(-2, 1)));
    CHECK_THROWS((potok >> test));
    CHECK_THROWS((potok >> test));
}