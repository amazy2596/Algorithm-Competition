#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    string x, y;
    cin >> x >> y;
    vector<int> a, b, c(1e7);
    for (int i = 0; i < x.length(); i++)
        a.push_back(x[i] - '0');
    for (int i = 0; i < y.length(); i++)
        b.push_back(y[i] - '0');
    if (a.size() < b.size())
        swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int idx = 0, n = a.size() + b.size();
    for (int i = 0; i < b.size(); i++)
    {
        int t = 0;
        for (int j = 0; j < a.size(); j++)
        {
            t += a[j] * b[i];
            c[i + j] += t % 10;
            t /= 10;
            if (c[i + j] >= 10)
            {
                c[i + j + 1] += c[i + j] / 10;
                c[i + j] %= 10;
            }
            if (j == a.size() - 1 && t != 0)
                c[i + j + 1] += t;
        }
    }
    // for (int i = 0; i <= a.size() + b.size(); i++)
    // {
        // if (c[i] >= 10)
        // {
            // c[i + 1] += c[i] / 10;
            // c[i] = c[i] % 10;
        // }
    // }
    while (c[n] == 0 && n)
        n--;
    for (int i = n; i >= 0; i--)
        cout << c[i];
    return 0;
}