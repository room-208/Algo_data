#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    //ファイル削除
    char filename[] = "data_2.csv";
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

    for (int N = 1e1; N < 1e4; N++)
    {
        std::vector<std::pair<int, int>> pairs(N);

        srand(1);
        for (int i = 0; i < N; i++)
        {
            pairs[i].first = rand() % 10 + 1;
            pairs[i].second = rand() % 10 + 1;
            //std::cout << pairs[i].first << "\t" << pairs[i].second << "\n";
        }
        //std::cout << "\n";

        clock_t start = clock();

        std::sort(pairs.begin(), pairs.end(), cmp);

        /*
        for (int i = 0; i < N; i++)
        {
            std::cout << pairs[i].first << "\t" << pairs[i].second << "\n";
        }
        std::cout << "\n";
        */

        int res = 0;
        int current_end_time = 0;
        for (int i = 0; i < N; i++)
        {
            if (current_end_time <= pairs[i].first)
            {
                current_end_time = pairs[i].second;
                res++;
            }
        }

        clock_t end = clock();

        std::cout << res << std::endl;
        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}