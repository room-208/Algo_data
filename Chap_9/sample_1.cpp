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

using namespace std;

const int MAX = 100000;

int st[MAX];
int top = 0;

void init()
{
    top = 0;
}

bool isEmpty()
{
    return (top == 0);
}

bool isFull()
{
    return (top == MAX);
}

void push(int x)
{
    if (isFull())
    {
        cout << "error" << endl;
        return;
    }

    st[top] = x;
    ++top;
}

int pop()
{
    if (isEmpty())
    {
        cout << "error" << endl;
        return -1;
    }

    --top;
    return st[top];
}

int main()
{

    push(5);
    push(7);

    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    
    return 0;
}