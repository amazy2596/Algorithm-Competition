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

    LinearSieve(int n = 2e6 + 5) : n(n), minp(n + 1)
    {
        for (int i = 2; i <= n; i++) 
        {
            if (minp[i] == 0) 
            {
                minp[i] = i;
                primes.push_back(i);
            }
            for (int p : primes) 
            {
                if (i * p >= n)
                    break;

                minp[i * p] = p;

                if (minp[i] == p)
                    break;
            }
        }
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

void solve()
{
    for (int i = 1; i <= 100; i++)
    {
        auto fact = LS.factorize(i);
        for (auto [key, val] : fact)
        {
            int x = i + key;
            int y = sqrt(x);
            if (y * y == x)
            {
                cout << i << " " << key << "\n";
                break;
            }
        }
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