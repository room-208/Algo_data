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

int N = 10;

/*
vector<int> a(N);
vector<vector<int>> a(N, vector<int>(N));
auto itr = a.begin();
for (auto itr = a.begin(); itr != a.end(); itr++)
{
    cout << itr - a.begin() << endl; = 0,1,...,N-1
}
sort(a.begin(), a.end());
reverse(a.begin(), a.end());
*/

const int MAX = 3;

int main()
{
    /*
    std::list<int> lst;

    lst.push_front(10);
    lst.push_back(1);
    {
        auto itr = lst.begin();
        itr++;
        itr = lst.insert(itr, 0);
    }

    for (auto itr = lst.begin(); itr != lst.end(); itr++)
    {
        cout << *itr << endl;
    }
    */

    vector<int> a(N);
    for (auto itr = a.begin(); itr != a.end(); itr++)
    {
        cout << itr - a.begin() << endl;
    }
    reverse(a.begin(), a.end());
    return 0;
}