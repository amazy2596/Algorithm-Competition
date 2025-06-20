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
    vector<int> has_pre(n), has_suf(n);
    vector<int> pre(26, -1), suf(26, -1);
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (suf[s[i] - 'a'] != -1)
            has_suf[i] = 1;
        
        suf[s[i] - 'a'] = i;
    }

    for (int i = 0; i < n; i++)
    {
        if (pre[s[i] - 'a'] != -1)
            has_pre[i] = 1;
        
        pre[s[i] - 'a'] = i;
    }

    auto check = [&](int k)
    {
        for (int i = k - 1; i < n; i++)
        {
            if (has_suf[i])
                return true;
        }
        for (int i = n - k; i >= 0; i--)
        {
            if (has_pre[i])
                return true;
        }

        return false;
    };

    int l = 0, r = n;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else 
            r = mid - 1;
    }

    cout << l << "\n";
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