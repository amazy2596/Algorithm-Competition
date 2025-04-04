#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
        if (mp[s[i]] >= n)
        {
            cout << "-1\n";
            return;
        }
    }
    
    auto get = [&](int i) -> char
    {
        for (auto ch : vector<char> {'T', 'L', 'I'})
        {
            if (s[i] != ch && s[i + 1] != ch)
                return ch;
        }

        return '$';
    };

    vector<int> ans;
    while (max({mp['L'], mp['T'], mp['I']}) != min({mp['L'], mp['T'], mp['I']}))
    {
        int mn = min({mp['L'], mp['T'], mp['I']});
        int mx = max({mp['L'], mp['T'], mp['I']});

        int f = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            char x = get(i);
            if (s[i] != s[i + 1] && mp[x] == mn)
            {
                mp[x]++;
                f = 1;
                s.insert(s.begin() + i + 1, x);
                ans.push_back(i);
                break;
            }
        }

        if (!f)
        {
            for (int i = 0; i < s.size() - 1; i++)
            {
                char x = get(i);
                if (s[i] != s[i + 1] && mp[x] == mx)
                {
                    mp[x]++;
                    f = 1;
                    s.insert(s.begin() + i + 1, x);
                    ans.push_back(i);
                    break;
                }
            }
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << "\n";
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