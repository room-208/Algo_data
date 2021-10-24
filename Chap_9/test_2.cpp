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

using namespace std;
const int MAX = 3;

int main()
{
    int N;
    cin >> N;
    vector<char> s(N);
    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
    }

    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        if (s[i] == '(')
        {
            a[i] = 1;
        }
        if (s[i] == ')')
        {
            a[i] = -1;
        }
    }

    bool flag = true;
    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == '(')
        {
            counter++;
        }
        else if (s[i] == ')')
        {
            counter--;
        }

        if (counter < 0)
        {
            flag = false;
        }
    }
    if (counter != 0)
    {
        flag = false;
    }

    cout << boolalpha << flag << endl;

    list<int> lst;

    if (flag)
    {
        for (int i = 0; i < N; i++)
        {
            if (s[i] == '(')
            {
                lst.push_back(i);
            }
            else if (s[i] == ')')
            {
                auto itr = lst.end();
                itr--;
                cout << *itr << "\t" << i << endl;
                lst.pop_front();
            }
        }
    }
}