#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), r, b;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
            r.push_back(v[i]);
        else 
            b.push_back(v[i]);
    }

    sort(r.rbegin(), r.rend());
    sort(b.rbegin(), b.rend());

    int ans = 0;
    int i = 0;
    while (i < r.size() && i < b.size())
        ans += r[i] + b[i], i++;

    if (r.size() > b.size())
        ans += r[i];
    
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}