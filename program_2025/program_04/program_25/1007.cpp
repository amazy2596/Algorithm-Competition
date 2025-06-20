#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n1, n2;
    cin >> n1 >> n2;
    int ans = 1;
    map<pair<int, int>, int> mp;
    int p = 0, q = 1;
    for (int i = 0; i < n1; i++)
    {
        int x, y;
        cin >> x >> y;

        if (i == n1 - 1)
            continue;

        p = x * q + y * p;
        q = q * y;
        int g = __gcd(p, q);
        p /= g;
        q /= g;
        mp[{p, q}]++;
    }

    p = 0, q = 1;
    for (int i = 0; i < n2; i++)
    {
        int x, y;
        cin >> x >> y;

        if (i == n2 - 1)
            continue;

        p = x * q + y * p;
        q = q * y;
        int g = __gcd(p, q);
        p /= g;
        q /= g;
        if (mp.find({p, q}) != mp.end())
            ans++;
    }

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