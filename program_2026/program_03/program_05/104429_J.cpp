// Problem: L2-2 WordleGame
// URL: https://ac.nowcoder.com/acm/contest/104429/J
// Author: amazy
// Date: 2026-03-05 18:04:22

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;



void solve()
{
    int n;
    cin >> n;
    vector<string> tar(n);
    for (int i = 0; i < n; i++) cin >> tar[i];
    
    int m, k;
    cin >> m >> k;
    vector<string> guess(k), op(k);
    for (int i = 0; i < k; i++) cin >> guess[i] >> op[i];

    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        if (tar[i].length() != m) continue;

        bool ok = 1;
        for (int l = 0; l < k; l++)
        {
            string cur(m, 'B');
            vector<int> cnt(26);
            for (int j = 0; j < m; j++) cnt[tar[i][j] - 'a']++;

            for (int j = 0; j < m; j++)
            {
                if (tar[i][j] == guess[l][j]) 
                {
                    cur[j] = 'G';
                    cnt[guess[l][j] - 'a']--;
                }
            }

            for (int j = 0; j < m; j++)
            {
                if (tar[i][j] != guess[l][j] && cnt[guess[l][j] - 'a'] > 0) 
                {
                    cur[j] = 'Y';
                    cnt[guess[l][j] - 'a']--;
                }
            }

            if (cur != op[l])
            {
                ok = 0;
                break;
            }
        }

        if (ok) ans.push_back(tar[i]);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto &s : ans) cout << s << "\n";
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