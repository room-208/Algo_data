#include <bits/stdc++.h>
#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main()
{
    long long N = 10;
    long long M = 34;
    vector<long long> P(N);

    srand(1);
    for (int i = 0; i < N; i++)
    {
        P[i] = rand() % (6 * N) + 1;
    }
    vector<long long> S;
    for (int i = 0; i < P.size(); ++i)
        for (int j = 0; j < P.size(); ++j)
            S.push_back(P[i] + P[j]);
    sort(S.begin(), S.end());
    long long res = 0;
    for (long long a : S)
    {
        auto it = upper_bound(S.begin(), S.end(), M - a);
        if (it == S.begin())
            continue;
        --it;
        res = max(res, a + *it);
    }
    cout << res << endl;
}