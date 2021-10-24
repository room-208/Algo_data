#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>

int main()
{
    //ファイル削除
    char filename[] = "test_1.csv";
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

    for (int N = 1e1; N < 1e5; N++)
    {
        std::vector<long long> a(N);
        std::vector<long long> order(N);
        int tmp;
        int key;

        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % 10 + 1;
        }
        /*
        for (auto it = a.begin(); it != a.end(); it++)
        {
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;
        */

        clock_t start = clock();

        //コピーO(N)
        auto a_cp = a;

        //コピーソートO(NlogN)
        std::sort(a_cp.begin(), a_cp.end());

        //順位計算O(N)
        for (int i = 0; i < N; i++)
        {
            key = a[i];

            //O(logN)
            auto iter = std::lower_bound(a_cp.begin(), a_cp.end(), key);

            order[i] = iter - a_cp.begin();
        }

        clock_t end = clock();

        /*
        for (int i = 0; i < N; i++)
        {
            std::cout << order[i] << std::endl;
        }
        */

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}