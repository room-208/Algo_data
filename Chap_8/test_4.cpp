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

int main()
{
    //ファイル削除
    char filename[] = "test_4.csv";
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

            a[0] = rand() % 10 + 1;
            //std::cout << a[0] << "\t";
            for (int i = 1; i < N; i++)
            {
                a[i] = a[i - 1] + rand() % 10 + 1;
                //std::cout << a[i] << "\t";
            }
            b[0] = a[0]; //rand() % 10 + 1;
            //std::cout << b[0] << "\t";
            for (int i = 1; i < M; i++)
            {
                b[i] = a[i]; // b[i - 1] + rand() % 10 + 1;
                //std::cout << b[i] << "\t";
            }

            std::unordered_set<int> hash;
            long long counter = 0;

            clock_t start = clock();

            for (int i = 0; i < N; i++)
            {
                hash.insert(a[i]);
            }
            for (int i = 0; i < M; i++)
            {
                if (hash.count(b[i]))
                {
                    counter++;
                }
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