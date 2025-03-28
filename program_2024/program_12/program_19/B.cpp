#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> cnt;
    int len = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i - 1] != s[i])
            len++;
        else
        {
            cnt.push_back(len);
            len = 1;
        }
    }
    if (len > 1)
        cnt.push_back(len);
    auto get = [&](int l, int r)
    {
        return (l + r) * (r - l + 1) / 2;
    };
    int ans = 0;
    for (int len : cnt)
    {
        // 1 ... len - 1
        ans += get(1, len - 1);
    }
    cout << ans;
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