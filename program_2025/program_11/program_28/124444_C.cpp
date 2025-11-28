// Problem: 假树人
// URL: https://ac.nowcoder.com/acm/contest/124444/C
// Author: amazy
// Date: 2025-11-28 22:21:29

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        mp[a[i]]++;
    }

    while (m--)
    {
        int i;
        cin >> i;
        if (mp.rbegin()->first == a[i]) continue;
        mp[a[i]]--;
        a[i] = mp.rbegin()->first + 1;
        mp[a[i]]++;
    }

    cout << mp.rbegin()->first << "\n";
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