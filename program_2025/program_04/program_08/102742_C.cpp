#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, string>> cnt;
    int cur = 0, ans = 0;
    string last = "";
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (last == "" || last == s)
            cur++;
        else 
            cnt.push_back({cur, last}), cur = 1;

        last = s;

        if (cnt.size())
            ans = max(ans, cnt.back().first);
    }

    cnt.push_back({cur, last});
    if (cnt.size())
        ans = max(ans, cnt.back().first);

    for (int i = 1; i < cnt.size() - 1; i++)
    {
        if (cnt[i].first == 1 && cnt[i - 1].second == cnt[i + 1].second)
            ans = max(ans, cnt[i - 1].first + cnt[i + 1].first);
    }

    cout << ans << "\n";
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