#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>

const int INF = 1 << 30;

int main()
{
    //ファイル削除
    char filename[] = "data_4.csv";
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
        std::vector<int> a(N), b(N);
        int K = 100;
        int min_value = INF;
        int tmp;
        int left, mid, right;

        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % K + 1;
            b[i] = rand() % K + 1;
            //std::cout << a[i] << "\t" << b[i] << std::endl;
        }

        clock_t start = clock();

        std::sort(b.begin(), b.end());

        //b.begin,b.endはアドレスを指定
        //std::cout << *(b.begin()) << "\t" << *(b.end() - 1) << std::endl;

        //b.endのアドレスに追加→b.end-1にINFが入る(配列のサイズが一つ上がる)
        //ソートで絶対超える値を代入
        b.push_back(INF);

        for (int i = 0; i < N; i++)
        {
            auto iter = std::lower_bound(b.begin(), b.end(), K - a[i]);

            tmp = a[i] + *iter;

            if (min_value > tmp)
            {
                min_value = tmp;
            }
        }

        clock_t end = clock();

        std::cout << min_value << std::endl;
        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}