// Problem: C. Production of Snowmen
// URL: https://codeforces.com/contest/2182/problem/C
// Author: amazy
// Date: 2025-12-30 17:40:43

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    auto calc = [&](vector<int> &x, vector<int> &y)
    {
        int res = 0;
        for (int dx = 0; dx < n; dx++)
        {
            bool f = 1;
            for (int i = 0; i < n; i++)
            {
                if (!(x[i] < y[(i + dx) % n]))
                {
                    f = 0;
                    break;
                }
            }
            res += f;
        }
        return res;
    };

    cout << 1LL * n * calc(a, b) * calc(b, c) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}