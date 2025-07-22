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

    map<int, int> factorize(int x) 
    {
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
} LS(5e6 + 5);

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        auto tmp = LS.factorize(a[i]);
        for (auto [key, val] : tmp)
            mp[key] += val;
    }

    if (n & 1 == 1)
    {
        cout << "YES\n";
        return;
    }

    if (n == 2)
    {
        if (a[1] != a[2])
            cout << "NO\n";
        else 
            cout << "YES\n";
        return;
    }

    for (auto [key, val] : mp)
    {
        if (n % 2 == 0 && val % 2 != 0)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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