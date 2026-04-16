// Problem: L1-8 逆
// URL: https://ac.nowcoder.com/acm/contest/130247/H
// Author: amazy
// Date: 2026-03-14 14:19:22

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    i64 ans = 0;
    do
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                    ans++;
                }
            }
        }
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << "\n";
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