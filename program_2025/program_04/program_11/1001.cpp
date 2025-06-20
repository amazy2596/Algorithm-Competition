#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int k, a, b, c;
    cin >> k >> a >> b >> c;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(a + b);
    v.push_back(a + c);
    v.push_back(b + c);
    v.push_back(a + b + c);
    int ans = k;
    for (auto val : v)
        if (k - val >= 0)
            ans = min(ans, k - val);

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