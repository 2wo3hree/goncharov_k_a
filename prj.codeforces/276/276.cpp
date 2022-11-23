
#include <iostream>
#include <array>
#include <cmath>




int main() {

    setlocale(LC_ALL, "RU");

    int year,k,f,t,m,f1,t1,n;
   
    std::cin >> n >> k;
    std::cin >> f1 >> t1;
    if (t1 > k)
        year = f1 - (t1 - k);
    else
        year = f1;
    for(int i=0;i<n-1;i++)

    {
        std::cin >> f >> t;
       
        if (t > k && ((f - (t - k)) >= year))
        
            year = f - (t - k);
        

        

        
            if ( t<=k && f >= year)
                year = f;
        
        
    }
    std::cout << year;
    
    
}