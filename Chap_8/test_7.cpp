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
    char filename[] = "test_7.csv";
    std::ofstream fout;
    fout.open(filename, std::ios::trunc);
    fout.close();

    //ヘッダー指定
    fout.open(filename, std::ios_base::app);
    fout << "N"
         << ","
         << "time[ms]"
         << "\n";
    fout.close();

    for (int N = 1e1; N < 1e3; N++)
    {
        std::vector<long long> a(N), b(N);
        int K = rand() % 10 + 1;

        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % 10 + 1;
            b[i] = rand() % 10 + 1;
        }

        std::unordered_set<int> hash;
        bool flag = false;

        clock_t start = clock();

        for (int i = 0; i < N; i++)
        {
            hash.insert(a[i]);
        }

        for (int i = 0; i < N; i++)
        {
            if (hash.count(K - b[i]))
            {
                flag = true;
                break;
            }
        }

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << std::endl;
        std::cout << flag << std::endl;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}