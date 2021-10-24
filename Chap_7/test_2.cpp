#define _GLIBCXX_DEBUG
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
#include <bits/stdc++.h>
#include <deque>
#include <queue>
#include <list>

using namespace std;
const int INF = 1 << 30;

int main()
{
    //ファイル削除
    char filename[] = "test_2.csv";
    ofstream fout;
    fout.open(filename, ios::trunc);
    fout.close();

    //ヘッダー指定
    fout.open(filename, ios_base::app);
    fout << "N"
         << ","
         << "time[ms]"
         << "\n";
    fout.close();

    for (int N = 100; N < 100 + 1; N++)
    {
        vector<pair<int, int>> red(N), blue(N);
        int key;
        int num;
        int tmp;

        srand(3);
        for (int i = 0; i < N; i++)
        {
            red[i].first = rand() % (3 * N) + 1;
            red[i].second = rand() % (3 * N) + 1;
            blue[i].first = rand() % (3 * N) + 1;
            blue[i].second = rand() % (3 * N) + 1;
        }

        for (int i = 0; i < N; i++)
        {
            cout << red[i].first << "\t" << red[i].second << "\t" << blue[i].first << "\t" << blue[i].second << endl;
        }
        std::cout << "\n";

        clock_t start = clock();

        clock_t end = clock();

        const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
        std::cout << time << std::endl;

        fout.open(filename, std::ios_base::app);
        fout << N << "," << std::fixed << std::setprecision(5) << time << "\n";
        fout.close();
    }

    return 0;
}