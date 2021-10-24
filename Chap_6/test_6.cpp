#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>

const double INF = (double)(1 << 30);

int main()
{
    double A, B, C;
    double x_r, x_l;
    double x;
    double func;
    double tmp;
    int count;
    int prev;

    srand(1);
    A = (double)(rand() % 10 + 1);
    B = (double)(rand() % 10 + 1);
    C = (double)(rand() % 10 + 1);

    clock_t start = clock();

    x_r = INF;
    x_l = 0;
    while (x_r - x_l > 1e-6)
    {
        x = (x_r + x_l) / 2.;
        //std::cout << x << std::endl;

        func = A * x + B * sin(C * x * M_PI) - 100.;

        if (func > 0.)
        {
            x_r = x;
        }
        else
        {
            x_l = x;
        }
    }

    x = (x_r + x_l) / 2.;
    func = A * x + B * sin(C * x * M_PI) - 100.;
    std::cout << x << "\t" <<x_r - x_l<<"\t" << func << std::endl;

    clock_t end = clock();

    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    std::cout << time << std::endl;

    return 0;
}