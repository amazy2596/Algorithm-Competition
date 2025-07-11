#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-9;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

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