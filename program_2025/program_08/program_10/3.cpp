#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const i64 mod = 998244353;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    auto dfs = [&](auto dfs, int r) -> i64
    {
        if (r == 1)
            return 1LL;
        int l = r;
        while (l - 1 >= 1)
        {
            if (s[l - 1] + s[l] == 0)
                l--;
            else 
                break;
        }
        l++;
        int ll = l;
        while (ll - 1 >= 1)
        {
            if (s[ll - 1] + s[l] == 0)
                ll--;
            else 
                break;
        }

        i64 tmp = dfs(dfs, ll);
        if (l == r)
            return ((r - ll + (ll == 1)) * tmp % mod + (ll != 1)) % mod;
        else 
        {
            i64 res = ((l - ll + (ll == 1)) * tmp % mod + (ll != 1)) % mod;
            vector<i64> f(r - l + 1);
            f[0] = 1, f[1] = 2;
            for (int i = 2; i < r - l + 1; i++)
                f[i] = f[i - 2] + f[i - 1];

            i64 tmp1 = f.back();
            res = (res + tmp1 * tmp) % mod;
            return res % mod;
        }
    };

    int r = n;
    while (r >= 1)
    {
        if (s[r] == s[n])
            r--;
        else 
            break;
    }

    r++;

    cout << dfs(dfs, r) % mod << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}