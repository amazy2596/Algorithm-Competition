#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e6 + 5;
const int mod = 998244353;
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

class Fenwick
{
    public:
        int n;
        vector<int> a;

        Fenwick(int size)
        {
            n = size;
            a.resize(n, 0);
        }

        int lowbit(int x)
        {
            return x & -x;
        }

        void update(int x, int k)
        {
            while (x > 0 && x <= n)
            {
                a[x] += k;
                x += lowbit(x);
            }
        }

        int query(int r)
        {
            int res = 0;
            while (r > 0)
            {
                res += a[r];
                r -= lowbit(r);
            }
            return res;
        }

        int query(int l, int r)
        {
            return query(r) - query(l - 1);
        }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> pre(n);
    for (int i = 0; i < n; i++)
        cin >> pre[i];

    if (pre.back() != 1)
    {
        cout << "0\n";
        return;
    }

    for (int i = 1; i < n; i++)
    {
        if (pre[i - 1] < pre[i])
        {
            cout << "0\n";
            return;
        }
    }

    Fenwick fw(n + 1);
    int ans = 1, num = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || pre[i - 1] != pre[i])
            fw.update(pre[i], 1);
        else 
        {
            int cnt = (n - pre[i] + 1) - fw.query(pre[i], n);
            ans = (ans * (cnt - num)) % mod;
            num++;
        }
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}