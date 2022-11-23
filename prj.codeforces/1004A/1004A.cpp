#include <iostream>
#include <array>
#include <vector>
#include <cmath>




int main() {

    setlocale(LC_ALL, "RU");



    int n, d, k = 2;
    std::cin >> n >> d;

    //std::array<int, N> a;
    std::vector<int> mv(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> mv[i];
    }



    for (int i = 0; i < n - 1; i++)

    {
        if (mv[i + 1] - mv[i] == 2 * d) k++;
        if (mv[i + 1] - mv[i] > 2 * d) k += 2;


    }




    std::cout << k;


}