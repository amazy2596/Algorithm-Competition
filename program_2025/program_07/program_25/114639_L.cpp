#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

struct LinearSieve 
{
    int n;
    vector<int> minp;
    vector<int> primes;
    vector<int> phi;
    vector<int> mu;

    LinearSieve(int _n = 2e6 + 5, bool enable_phi = false, bool enable_mu = false)
    {
        n = _n;
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

    vector<pair<int, int>> factorize(int x) 
    {
        vector<pair<int, int>> facts;

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
                facts.push_back({p, count});
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
                facts.push_back({p, count});
            }
        }

        if (x > 1) facts.push_back({x, 1});

        return facts;
    }

    bool is_prime(int x) 
    {
        if (x < 2 || x > n) 
            return false;
        return minp[x] == x;
    }
} LS(2e6 + 5, false, false);

void solve()
{
    // for (int i = 1; i <= 10000; i++)
    // {
    //     int tmp = sqrt(i);
    //     if (tmp * tmp != i)
    //         continue;

    //     map<int, int> cnt;
    //     for (int j = 1; j <= i; j++)
    //     {
    //         if (i % j == 0)
    //             cnt[j]++;
    //     }

    //     if (cnt.size() != 2 && LS.is_prime(cnt.size()))
    //     {
    //         cout << "YES\n";
    //         cout << i << ": ";
    //         cout << tmp << ": ";
    //         int c = LS.factorize(tmp).size();
    //         cout << c << "\n";
    //     }
    // }

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        int tmp = sqrtl(x);
        if (tmp * tmp != x)
            continue;

        auto vec = LS.factorize(tmp);

        if (vec.size() == 1)
        {
            int val = vec.begin()->second * 2 + 1;
            // cout << "x: " << x << "\n";
            // cout << d << " " << val << "\n";
            if (LS.is_prime(val) && val != 2)
                ans += x;
        }
    }

    cout << ans << "\n";
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