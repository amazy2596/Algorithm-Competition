// Problem: 小红的树构造
// URL: https://ac.nowcoder.com/acm/contest/123787/F
// Author: amazy
// Date: 2025-11-28 20:16:35

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 1) 
    {
        if (n < 5) 
        {
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        int m;
        vector<int> tar;

        if (n % 2 != 0) 
        {
            m = 2;
            tar = {0, 2, n - 2};
        } 
        else 
        {
            m = 3;
            tar = {0, 2, 3, n - 4};
        }

        vector<int> cur(n + 1, 0);
        for (int i = 1; i < m; i++) 
        {
            cout << i << " " << i + 1 << "\n";
            cur[i]++;
            cur[i + 1]++;
        }
        
        int idx = m + 1;
        for (int i = 1; i <= m; i++) 
        {
            while (cur[i] < tar[i]) 
            {
                cout << i << " " << idx << "\n";
                cur[i]++;
                idx++;
            }
        }
        return;
    }
    int m_max = (n - 2) / (k - 1);
    int r = ((2 - n) % k + k) % k;
    int cur_mod = m_max % k;
    int diff = (cur_mod - r + k) % k;
    int best_m = m_max - diff;

    if (best_m < 1) 
    {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    i64 sum_deg = n + best_m - 2;
    int d1 = sum_deg - (i64)(best_m - 1) * k;

    vector<int> tar(best_m + 1);
    tar[1] = d1;
    for (int i = 2; i <= best_m; i++) tar[i] = k;

    vector<int> cur(n + 1, 0);
    if (best_m > 1) 
    {
        for (int i = 1; i < best_m; i++) 
        {
            cout << i << " " << i + 1 << "\n";
            cur[i]++;
            cur[i+1]++;
        }
    }

    int idx = best_m + 1;
    for (int i = 1; i <= best_m; i++) 
    {
        while (cur[i] < tar[i]) 
        {
            cout << i << " " << idx << "\n";
            cur[i]++;
            idx++;
        }
    }
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