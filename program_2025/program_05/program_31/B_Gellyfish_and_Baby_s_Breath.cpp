#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<int> mxp(n), mxq(n);
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mx1)
        {
            mx1 = a[i];
            mxp[i] = i;
        }
        else if (i)
            mxp[i] = mxp[i - 1];

        if (b[i] > mx2)
        {
            mx2 = b[i];
            mxq[i] = i;
        }
        else if (i)
            mxq[i] = mxq[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        int idx1 = mxp[i], idx2 = mxq[i];
        if (a[idx1] == b[idx2])
        {
            if (b[i - idx1] > a[i - idx2])
            {
                cout << (p[a[idx1]] + p[b[i - idx1]]) % mod << " ";
            }
            else 
            {
                cout << (p[a[i - idx2]] + p[b[idx2]]) % mod << " ";
            }
        }
        else if (a[idx1] > b[idx2])
        {
            cout << (p[a[idx1]] + p[b[i - idx1]]) % mod << " ";
        }
        else 
        {
            cout << (p[a[i - idx2]] + p[b[idx2]]) % mod << " ";
        }
    }
    cout << "\n";
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