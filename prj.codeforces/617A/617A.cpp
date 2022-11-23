#include <iostream>

//using namespace std;

int main() {
    int w = 0, k = 0;
    std::cin >> w;
    int ans = w / 5;
    if (w % 5 != 0)
        ++ans;

    std::cout << ans;



    return 0;
}