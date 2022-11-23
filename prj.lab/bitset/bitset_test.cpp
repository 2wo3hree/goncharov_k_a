
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <bitset/bitset.h>
#include <iostream>



TEST_CASE("Bitset::Bitset(size)") {
    Bitset b(16);   // Bitset<000000000000000>
    for (int i = 0; i < 16; i++)
        CHECK_FALSE(b[i]);

    Bitset b2(1);   // Bitset<0>
    for (int i = 0; i < 1; i++)
        CHECK_FALSE(b2[i]);
}
TEST_CASE("Bitset::operator==()") {
    Bitset b(16, true);     // Bitset<1111111111111111>
    for (int i = 0; i < 16; i++)
        CHECK(b[i]);

    b <<= 6;                          // Bitset<1111111111000000>

    Bitset b2(16, true);    // Bitset<1111111111111111>
    for (int i = 0; i < 16; i++)
        CHECK(b2[i]);


    b2 >>= 10;                        // Bitset<0000000000111111>
    b = ~b;                           // Bitset<0000000000111111>

    CHECK((b2 == b));
}


