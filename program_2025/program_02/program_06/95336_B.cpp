#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    vector<string> temp;
    auto dfs = [&](auto dfs, int idx) -> void
    {
        if (idx == s.length())
        {
            for (auto &ch : s)
            {
                if (ch == '0')
                    ch = '1';
                else 
                    ch = '0';

                int cnt1 = 0, cnt2 = 0;
                for (int i = 0; i < s.length() - 1; i++)
                {
                    cnt1 += (s.substr(i, 2) == "01");
                    cnt2 += (s.substr(i, 2) == "10");
                }
                if (cnt1 == cnt2)
                    temp.push_back(s);
                ans += (cnt1 == cnt2);
                
                if (ch == '0')
                    ch = '1';
                else 
                    ch = '0';
            }
            return;
        }
        if (s[idx] == '?')
        {
            s[idx] = '0';
            dfs(dfs, idx + 1);
            s[idx] = '1';
            dfs(dfs, idx + 1);
            s[idx] = '?';
        }
        else 
            dfs(dfs, idx + 1);
    };
    dfs(dfs, 0);
    sort(temp.begin(), temp.end());
    // temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for (int i = 0; i < temp.size(); i++)
        cout << temp[i] << "\n";
    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}