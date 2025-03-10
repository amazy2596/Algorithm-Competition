#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int m, k;
    cin >> m >> k;

    vector<string> tar(k), op(k);
    for (int i = 0; i < k; i++)
        cin >> tar[i] >> op[i];
    
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i].length() != m)
            continue;
        bool ok = 1;
        for (int j = 0; j < k; j++)
        {
            map<char, int> mp;
            string check(m, 'B');

            for (int l = 0; l < m; l++)
            {
                if (s[i][l] == tar[j][l])
                    check[l] = 'G';
                else 
                    mp[s[i][l]]++;
            }

            for (int l = 0; l < m; l++)
            {
                if (check[l] == 'G')
                    continue;
                if (mp[tar[j][l]] > 0)
                {
                    check[l] = 'Y';
                    mp[tar[j][l]]--;
                }
            }

            if (check != op[j])
            {
                ok = 0;
                break;
            }
        }

        if (ok)
            ans.push_back(s[i]);
    }

    ranges::sort(ans);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}