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

    LinearSieve(int n = 2e6 + 5, bool enable_phi = false, bool enable_mu = false)
    {
        minp.resize(n + 1);
        if (enable_phi) phi.resize(n + 1);
        if (enable_mu) mu.resize(n + 1);
        
        for (int i = 2; i <= n; i++) 
        {
            if (minp[i] == 0) 
            {
                minp[i] = i;
                primes.push_back(i);

                if (enable_phi) phi[i] = i - 1;
                if (enable_mu) mu[i] = -1;
            }
            for (int p : primes) 
            {
                if (1LL * i * p >= n || p > minp[i])
                    break;

                minp[i * p] = p;
                
                if (p == minp[i])
                {
                    if (enable_phi) phi[i * p] = 1LL * p * phi[i];
                    if (enable_mu) mu[i * p] = 0;
                    break;
                }
                else 
                {
                    if (enable_phi) phi[i * p] = 1LL * (p - 1) * phi[i];
                    if (enable_mu) mu[i * p] = -mu[i];
                }
            }
        }

        if (enable_phi) phi[1] = 1;
        if (enable_mu) mu[1] = 1;
    }

    map<int, int> factorize(int x) 
    {
        map<int, int> facts;

        if (x <= n)
        {
            while (x > 1)
            {
                int p = minp[x];
                int count = 0;
                while (x % p == 0)
                {
                    x /= p;
                    count++;
                }
                facts[p] = count;
            }

            return facts;
        }

        for (int p : primes) 
        {
            if (1LL * p * p > x) break;

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
} LS(2e6 + 5, false, false);

void solve()
{
    int x, y;
    cin >> x >> y;

    auto a = LS.factorize(x);
    auto b = LS.factorize(y);

    for (auto [key, val] : b)
        a[key] += val;

    vector<int> v;
    for (auto [key, val] : a)
    {
        if (val % 2 == 0)
            continue;
        v.push_back(key);
    }

    int ans = inf;
    for (int i = 0; i <= (1ll << v.size()); i++)
    {
        x = 1, y = 1;
        for (int k = 0; k < v.size(); k++)
        {
            if ((i >> k) & 1)
                x *= v[k];
            else 
                y *= v[k];
        }

        ans = min(ans, x + y);
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