#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int i = 0;
    int n = s.length();
    while (i < n / 2 && s[i] == s[n - i - 1])
        i++;
    n -= 2 * i;
    s = s.substr(i, n);
    if (s == "")
    {
        cout << "0\n";
        return;
    }

    auto check = [&](int x)
    {
        vector<int> cnt(26);
        for (int i = 0; i < x; i++)
            cnt[s[i] - 'a']++;

        for (int i = 0; i < min(n / 2, n - x); i++)
        {
            char ch = s[n - i - 1];
            
            if (i < x)
            {
                if (cnt[ch - 'a'] > 0)
                    cnt[ch - 'a']--;
                else 
                    return false;
            }
            else if (s[i] != ch)
                return false;
        }

        for (int i = 0; i < 26; i++)        
            if (cnt[i] % 2 != 0)
                return false;

        return true;
    };

    // for (int i = 1; i <= n; i++)
        // cout << check(i) << " ";
    // cout << "\n";

    int ans = 1e9;
    for (int z = 0; z < 2; z++)
    {
        int l = 1, r = s.length();
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid))
                r = mid;
            else 
                l = mid + 1;
        }

        ans = min(ans, l);
        reverse(s.begin(), s.end());
    }

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