// Problem: L1-3 往日种种
// URL: https://ac.nowcoder.com/acm/contest/130247/C
// Author: amazy
// Date: 2026-03-14 14:03:21

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int a = 0, b = 0;
    string x = "talent", y = "hard";
    for (int i = 0; i < n && i + x.size() - 1 < n; i++)
    {
        int f = 1;
        for (int j = 0; j < x.size(); j++)
        {
            if (s[i + j] != x[j])
            {
                f = 0;
                break;
            }
        }
        a += f;
    }

    for (int i = 0; i < n && i + y.size() - 1 < n; i++)
    {
        int f = 1;
        for (int j = 0; j < y.size(); j++)
        {
            if (s[i + j] != y[j])
            {
                f = 0;
                break;
            }
        }
        b += f;
    }

    if (b > a) cout << y << "\n";
    else if (b < a) cout << x << "\n";
    else cout << "every\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}