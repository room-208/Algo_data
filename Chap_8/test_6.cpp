#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>

int main()
{
    //ファイル削除
    char filename[] = "test_6.csv";
    std::ofstream fout;
    fout.open(filename, std::ios::trunc);
    fout.close();

    //ヘッダー指定
    fout.open(filename, std::ios_base::app);
    fout << "N"
         << ","
         << "M"
         << ","
         << "time[ms]"
         << "\n";
    fout.close();

    for (int N = 1e1; N < 1e3; N++)
    {
        for (int M = 1e1; M < 1e3; M++)
        {
            std::vector<int> a(N), b(M);

            a[0] = 1;
            for (int i = 1; i < N; i++)
            {
                a[i] = 1;
            }
            b[0] = 1;
            for (int i = 1; i < M; i++)
            {
                b[i] = 1;
            }

            std::unordered_multiset<int> hash;
            long long counter = 0;

            clock_t start = clock();

            for (int i = 0; i < N; i++)
            {
                hash.insert(a[i]);
            }
            for (int i = 0; i < M; i++)
            {
                counter += hash.count(b[i]);
            }

            clock_t end = clock();

            const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
            //std::cout << std::endl;
            //std::cout << counter << std::endl;
            //std::cout << time << std::endl;

            fout.open(filename, std::ios_base::app);
            fout << N << "," << M << "," << std::fixed << std::setprecision(5) << time << "\n";
            fout.close();
        }
    }

    return 0;
}