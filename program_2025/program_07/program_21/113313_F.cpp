#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct LinearSieve 
{
    int n;
    vector<int> minp;
    vector<int> primes;
    vector<int> phi;
    vector<int> mu;

    LinearSieve(int n = 2e6 + 5) : n(n), minp(n + 1), phi(n + 1), mu(n + 1)
    {
        for (int i = 2; i <= n; i++) 
        {
            if (minp[i] == 0) 
            {
                minp[i] = i;
                phi[i] = i - 1;
                mu[i] = -1;
                primes.push_back(i);
            }
            for (int p : primes) 
            {
                if (i * p >= n || p > minp[i])
                    break;

                minp[i * p] = p;
                
                if (p == minp[i])
                {
                    phi[i * p] = p * phi[i];
                    mu[i * p] = 0;
                    break;
                }
                else 
                {
                    phi[i * p] = (p - 1) * phi[i];
                    mu[i * p] = -mu[i];
                }
            }
        }

        phi[1] = 1;
        mu[1] = 1;
    }

    map<int, int> factorize(int x) {
        map<int, int> facts;

        if (x <= n)
        {
            while (x > 1)
            {
                facts[minp[x]]++;
                x /= minp[x];
            }

            return facts;
        }

        for (int p : primes) 
        {
            if (p * p > x) break;

            if (x % p == 0) 
            {
                int count = 0;
                while (x % p == 0) 
                {
                    x /= p;
                    count++;
                }
                facts[p] = count;
            }
        }

        if (x > 1) facts[x] = 1;

        return facts;
    }

    bool is_prime(int x) 
    {
        if (x < 2 || x > n) return false;
        return minp[x] == x;
    }
} LS;

const int mod1 = 1000000007;
const int mod2 = 998244353;
int mod = mod1;
int fast_pow(int a, int b) 
{
    if (a == 0 && b == 0)
        return 1ll;
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
    int base, c0;
    cin >> base >> c0 >> mod;

    vector<int> c(mod + 1), last(mod + 1);
    c[0] = c0;
    int start, end, len;
    for (int i = 1; i <= mod; i++)
    {
        c[i] = fast_pow(base, c[i - 1]) % mod;
        if (last[c[i]] != 0)
        {
            start = last[c[i]];
            end = i - 1;
            len = end - start + 1;
            break;
        }
        last[c[i]] = i;
    }

    c[0] = 0;

    vector<int> pre(mod + 1);
    for (int i = 1; i <= mod; i++) 
        pre[i] = (pre[i - 1] + c[i]) % mod;

    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;

        if (k < start)
        {
            cout << pre[k] % mod << "\n";
            continue;
        }

        int pre_ans = pre[start - 1];
        int total = ((pre[end] - pre[start - 1]) % mod + mod) % mod;
        int middle_ans = (total * (((k - start + 1) / len) % mod)) % mod;
        int rem = k - (start - 1 + (k - start + 1) / len * len);
        int suf_ans = ((pre[start + rem - 1] - pre[start - 1]) % mod + mod) % mod;

        cout << (pre_ans + middle_ans + suf_ans) % mod << "\n";
    }
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