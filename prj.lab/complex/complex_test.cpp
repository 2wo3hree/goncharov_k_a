
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <complex/complex.h>
#include <doctest/doctest.h>
#include <string>
#include <sstream>


TEST_CASE("prisvaivanie test")
{
    Complex a = Complex(4);
    Complex b = Complex(a);
    CHECK(a.re == b.re);
    CHECK(a.im == b.im);
}

TEST_CASE("Assignment of Complex value to Complex test") {
    Complex a = Complex(4);
    Complex b = a;
    CHECK(b.re == doctest::Approx(a.re));
    CHECK(b.im == doctest::Approx(a.im));
}

TEST_CASE("+ test") {
  
    CHECK(Complex(1,6) + Complex(2,5) == Complex(3, 11));
}

TEST_CASE("- test") {

    CHECK(Complex(1, 6) - Complex(2, 5) == Complex(-1, 1));
}


TEST_CASE("/ test") {
   
    CHECK((Complex(4, 6) / Complex(2, 6) == Complex(1.1, -0.3)));
}

TEST_CASE("/ test") {
    
    CHECK_THROWS(Complex(4, 6) / Complex(0, 0));
    
}

TEST_CASE("* test") {
   
    CHECK(Complex(1, 6) * Complex(2, 6) == Complex(-34, 18));
}

TEST_CASE("+= test") {
    Complex a = Complex();
    Complex b = Complex(1, 5);
    a += b;
    CHECK((a == Complex(1, 5)));
}

TEST_CASE("-= test") {
    Complex a = Complex();
    Complex b = Complex(1, 5);
    a -= b;
    CHECK((a == Complex(-1, -5)));
}

TEST_CASE("*= test") {
    Complex a = Complex(1, 6);
    Complex b = Complex(2, 6);
    a *= b;
    CHECK((a == Complex(-34, 18)));
}

TEST_CASE("/= test") {
    Complex a = Complex(4, 6);
    Complex b = Complex(2, 6);
    a /= b;
    CHECK((a == Complex(1.1, -0.3)));
}

TEST_CASE("!= test") {
    
    CHECK((Complex(1, 3) != Complex(2, 14)));
}

TEST_CASE("== test") {
    
    CHECK(Complex(1, 2) == Complex(1, 2));
}

TEST_CASE("testing complex constructors") {
    CHECK_NOTHROW(Complex(1, 2));
    CHECK_NOTHROW(Complex(1, -2));
    CHECK_NOTHROW(Complex(-1, 2));
    CHECK_NOTHROW(Complex(-1, -2));
    CHECK_NOTHROW(Complex(1.2));
    CHECK_NOTHROW(Complex(-1.2));
    CHECK_NOTHROW(Complex());
    
}



TEST_CASE("input") {
    std::istringstream s;
    Complex a;
    s = std::istringstream{ "{1.2, 3.2}" };
    s >> a;
    CHECK(a == Complex(1.2, 3.2));
    
   
    //s = std::istringstream{ "1/ 2" };
    //CHECK((s >> a).fail());
}

