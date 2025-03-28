#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int fact[N], ifact[N], p[N];

int fast_pow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        
        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

void init()
{
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = (p[i - 1] * 2) % mod;

    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    
    ifact[N - 1] = fast_pow(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
        ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
}

int C(int n, int m)
{
    if (n < m)
        return 0;
    return (fact[n] % mod * ifact[m] % mod * ifact[n - m] % mod) % mod;
}

int A(int n, int m)
{
    if (n < m)
        return 0;
    return (fact[n] % mod * ifact[n - m] % mod) % mod;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i].first >> p[i].second;
    
    auto sum = [&](int l, int r) -> int {
        int len = ( (r - l + 1) % mod + mod ) % mod;
        int sum_lr = ((l % mod + mod) % mod + (r % mod + mod) % mod) % mod;
        int inv2 = fast_pow(2, mod - 2);
        return ((sum_lr * len) % mod * inv2) % mod;
    };

    auto sum_2 = [&](int l, int r) -> int {
        auto f = [&](int n) -> int {
            n %= mod; 
            if(n < 0) n += mod;
            int res = n;
            res = (res * ((n + 1) % mod)) % mod;
            res = (res * ((2 * n + 1) % mod)) % mod;
            int inv6 = fast_pow(6, mod - 2);
            res = (res * inv6) % mod;
            return res;
        };
        int fr = f(r), fl_1 = f(l - 1);
        int res = (fr - fl_1) % mod;
        if (res < 0) res += mod;
        return res;
    };


    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        auto [a, b] = p[i - 1];
        auto [c, d] = p[i];
        int l1 = b - a + 1, l2 = d - c + 1;
        int inv = fast_pow(l1 * l2 % mod, mod - 2);
        int temp = 0;

        int sumY = sum(c, d);

        if (a < c)
        {
            int x1 = a, x2 = min(b, c - 1);
            if (x1 <= x2)
            {
                int cnt = (x2 - x1 + 1) % mod;
                int sumX = sum(x1, x2);
                int seg1 = ((cnt * sumY) % mod - ((l2 * sumX) % mod) + mod) % mod;
                temp = (temp + seg1) % mod;
            }
        }

        if (b > d)
        {
            int x1 = max(a, d + 1), x2 = b;
            if (x1 <= x2)
            {
                int cnt = (x2 - x1 + 1) % mod;
                int sumX = sum(x1, x2);
                int seg2 = (l2 * sumX % mod - cnt * sumY % mod + mod) % mod;
                temp = (temp + seg2) % mod;
            }
        }

        int x1 = max(a, c), x2 = min(b, d);
        if (x1 <= x2)
        {
            int lt= x1 - c, rt = x2 - c;
            int cnt = (rt - lt + 1) % mod;
            int L = d - c;

            int sumT2 = sum_2(lt, rt);
            int sumT = sum(lt, rt);
            int term = ((L % mod * L % mod) + L) % mod;
            term = term * fast_pow(2, mod - 2) % mod;
            int seg3 = (sumT2 - (L * sumT % mod) + (term * cnt % mod) + mod) % mod;
            temp = (temp + seg3) % mod;
        }

        temp = temp * inv % mod;
        ans = (ans + temp) % mod;
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