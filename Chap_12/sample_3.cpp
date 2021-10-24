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

/*
list<int> lst;
lst.push_front(i);
lst.push_back(i);
lst.pop_front();
lst.pop_back();
for(auto itr = lst.begin(); itr != lst.end(); ++itr) {
    std::cout << *itr << "\n";
}
*/

/*
struct UnionFind
{
    vector<int> par, siz;

    //初期化
    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    //根を求める
    int root(int x)
    {
        if (par[x] == -1)
        {
            return x;
        }
        else
        {
            return par[x] = root(par[x]);
        }
    }

    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }

    bool unite(int x, int y)
    {
        x = root(x);
        y = root(y);

        if (issame(x, y))
        {
            return false;
        }

        if (siz[x] < siz[y])
        {
            swap(x, y);
        }

        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x)
    {
        return siz[root(x)];
    }
};

struct Edge
{
    int to;
    long long w;
    Edge(int to, long long w) : to(to), w(w) {}
};
*/

using namespace std;

void QuickSort(vector<int> &a, int left, int right)
{
    //ベースライン
    if (right - left <= 1)
    {
        return;
    }

    int pivot_index = (left + right) / 2;
    int pivot = a[pivot_index];

    swap(a[pivot_index], a[right - 1]);

    int i = left;
    for (int j = left; j < right - 1; j++)
    {
        if (a[j] < pivot)
        {
            swap(a[i], a[j]);
            i++;
        }
    }

    swap(a[i], a[right - 1]);

    QuickSort(a, left, i);
    QuickSort(a, i + 1, right);
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    QuickSort(a, 0, N);
    for (int i = 0; i < N; i++)
    {
        cout << a[i];
    }
}
