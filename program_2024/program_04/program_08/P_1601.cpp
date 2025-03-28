#include <bits/stdc++.h>
using intt = long long;
using namespace std;

vector<int> a, b;

void add()
{
    vector<int> c;
    int i, j, t = 0;
    for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--)
    {
        t = a[i] + b[j] + t;
        c.push_back(t % 10);
        t /= 10;
    }
    while (i >= 0)
    {
        t = a[i] + t;
        c.push_back(t % 10);
        t /= 10;
        i--;
    }
    while (j >= 0)
    {
        t = b[j] + t;
        c.push_back(t % 10);
        t /= 10;
        j--;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    for (int j = c.size() - 1; j >= 0; j--)
        cout << c[j];
}

int main()
{
    ios::sync_with_stdio(false);    cout.tie(nullptr);
    cin.tie(nullptr);
    string x, y;
    cin >> x >> y;
    for (int i = 0; i < x.length(); i++)   
        a.push_back(x[i] - '0');
    for (int j = 0; j < y.length(); j++)
        b.push_back(y[j] - '0');
    add();
    return 0;
}