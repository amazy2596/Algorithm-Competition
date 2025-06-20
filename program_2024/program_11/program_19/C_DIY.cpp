#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    for (auto [key, val] : mp)
    {
        for (int i = 0; i < val / 2; i++)
            b.emplace_back(key);
    }
    sort(b.begin(), b.end());
    if (b.size() < 4)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << b[0] << " " << b[1] << " " << b[0] << " " << b[b.size() - 1] << " " << b[b.size() - 2] << " " << b[1] << " " << b[b.size() - 2] << " " << b[b.size() - 1] << "\n";
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