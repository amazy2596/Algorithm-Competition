#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

int gcd(int a, int b)
{
    return b ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

struct node
{
    int lm, xr, mn;
};

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    int ans = 0;
    for (auto [key, val] : mp)
    {
        if (val % 2 == 0)
            ans += 2;
        else 
            ans += 1;
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