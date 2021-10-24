#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <random>

const int INF = 1e5;

int main()
{

    for (int N = 2; N < 3; N++)
    {
        clock_t start = clock();

        std::vector<int> a(N);
        int tmp;
        int min_count = INF;

        //値代入
        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % 100;
            std::cout << a[i] << "\n";
        }

        for (auto A : a)
        {
            tmp = 0;
            while (A % 2 == 0)
            {
                A /= 2;
                tmp++;
            }

            if (tmp < min_count)
            {
                min_count = tmp;
            }
        }

        std::cout << min_count << "\n";
    }

    return 0;
}