#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int, int>> block;
    block.push_back({-1, -1});
    int cnt = 0;
    int l = 0, r = 0;
    while (l < n && r < n)
    {
        while (l < s.length() && s[l] == '0')
            l++;
        r = l;
        while (r < s.length() && s[r] == '1')
            r++;
        block.push_back({l, r});
        l = r;
    }
    for (int i = 0; i < block[k - 1].second; i++)
        cout << s[i];
    for (int i = block[k].first; i < block[k].second; i++)
        cout << s[i];
    for (int i = block[k - 1].second; i < block[k].first; i++)
        cout << s[i];
    for (int i = block[k].second; i < n; i++)
        cout << s[i];
}

signed main()
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