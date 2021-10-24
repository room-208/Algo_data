#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>
using namespace std;

// 区間を pair<int,int> で表す
typedef pair<int, int> Interval;

// 区間を終端時刻で大小比較する関数
bool cmp(const Interval &a, const Interval &b)
{
    return a.second < b.second;
}

int main()
{
    // 入力
    int N = 100;
    vector<Interval> inter(N);

    srand(1);
    for (int i = 0; i < N; i++)
    {
        inter[i].first = rand() % 10 + 1;
        inter[i].second = rand() % 10 + 1;
        //std::cout << pairs[i].first << "\t" << pairs[i].second << "\n";
    }
    //std::cout << "\n";

    // 終端時刻が早い順にソートする
    sort(inter.begin(), inter.end(), cmp);

    // 貪欲に選ぶ
    int res = 0;
    int current_end_time = 0;
    for (int i = 0; i < N; ++i)
    {
        // 最後に選んだ区間と被るのは除く
        if (inter[i].first < current_end_time)
            continue;

        ++res;
        current_end_time = inter[i].second;
    }
    cout << res << endl;
}