#include <iostream>
#include <array>
#include <vector>
#include <cmath>




int main() {

    setlocale(LC_ALL, "RU");








    int n;
    std::cin >> n;
    //std::array<int, N> a;
    std::vector<int> mv(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> mv[i];
    }



    for (int k = 0; k < n; k++)

    {
        for (int i = 0; i < n; i++)
        {
            if (mv[i] == mv[k] && mv[i] % 2 == 0) { mv[i]--; }
            if (mv[i] == mv[k] && mv[i] % 2 != 0) { mv[i]++; }


        }

    }



    for (int i = 0; i < n; i++)
        std::cout << " " << mv[i] - 1;


}