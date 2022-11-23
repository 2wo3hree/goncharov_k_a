#include <iostream>
//#include <array>



int main() {

    int year = 0;
    std::cin >> year;

    for (int i = ++year; i < 10000; ++i) {
        int t = i / 1000;
        int s = i / 100 % 10;
        int d = i % 100 / 10;
        int e = i % 10;
        if ((t != s) && (t != d) && (t != e) && (s != d) && (s != e) && (d != e)) {
            std::cout << i;
            break;
        }
    }
    return 0;
}