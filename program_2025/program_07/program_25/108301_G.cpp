#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int mod1 = 1000000007;
const int mod2 = 998244353;
const int mod = mod2;
int fast_pow(int a, int b) 
{
    int res = 1;
    a %= mod;
    while (b) 
    {
        if (b & 1)
            res = (res * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int inv(int x) 
{
    return fast_pow(x, mod - 2);
}

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    s = " " + s;

    vector<int> sum(n + 1), pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
        pre[i] = pre[i - 1] + (s[i] == '(');
    }

    for (int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] + (s[i] == ')');

    int ans = 0, last = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sum[i] == 1)
        {
            ans = (ans + (fast_pow(2, pre[i]) - fast_pow(2, pre[last]) + mod) % mod * fast_pow(2, suf[i + 1])) % mod;
            last = i;
        }
    }
    ans = (ans + fast_pow(2, n / 2)) % mod;

    ans = (ans * inv(fast_pow(2, n))) % mod;
    cout << ans % mod << "\n";
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