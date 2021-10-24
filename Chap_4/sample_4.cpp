#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

int GCD(int m, int n)
{
    //ベースケース
    if (n == 0)
    {
        std::cout << "start" << std::endl;
        return 0;
    }

    //再帰呼び出し
    std::cout << m << "\t" << n << std::endl;
    return GCD(n, m % n);
}

int main()
{
    clock_t start = clock();

    std::cout << GCD(51, 15) << std::endl;

    clock_t end = clock();

    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    std::cout << time << std::endl;

    return 0;
}