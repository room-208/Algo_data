#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>

const int INF = 1 << 30;

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    //ファイル削除
    char filename[] = "test_3.csv";
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
        std::vector<std::pair<int, int>> task(N);
        std::vector<int> s(N + 1);
        int counter;
        int key;
        int num;
        int tmp;
        bool flag;

        for (int i = 0; i < N; i++)
        {
            task[i].first = rand() % (3 * N) + 1;
            task[i].second = rand() % (10 * N) + 1;
        }

        clock_t start = clock();

        /*
        for (int i = 0; i < N; i++)
        {
            std::cout << task[i].first << "\t" << task[i].second << "\n";
        }
        */

        std::sort(task.begin(), task.end(), cmp);

        /*
        for (int i = 0; i < N; i++)
        {
            std::cout << task[i].first << "\t" << task[i].second << "\n";
        }
        */

        s[0] = 0;
        for (int i = 0; i < N; i++)
        {
            s[i + 1] = s[i] + task[i].first;
        }

        flag = true;
        for (int i = 0; i < N; i++)
        {
            if (s[i + 1] > task[i].second)
            {
                flag = false;
            }
        }

        clock_t end = clock();

        //std::cout << flag << std::endl;
        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}