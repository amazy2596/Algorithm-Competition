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
    reverse(s.begin(), s.end());
    while (s.size() && s.back() == '0')
        s.pop_back();
    if (s.empty())
    {
        cout << 0 << "\n";
        return;
    }
    int ans = 1;
    char last = s[0];
    for (auto ch : s)
    {
        if (ch != last)
        {
            last = ch;
            ans++;
        }
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