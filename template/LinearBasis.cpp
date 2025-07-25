#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct LinearBasis
{
    int bits;
    vector<int> basis;

    LinearBasis (int _bits) : bits(_bits), basis(vector<int>(bits)) {}

    bool insert(int x)
    {
        for (int i = bits - 1; i >= 0; i--)
        {
            if (!(x >> i & 1))
                continue;

            if (basis[i])
                x ^= basis[i];
            else 
            {
                basis[i] = x;
                return true;
            }
        }

        return false;
    }

    bool exist(int x)
    {
        for (int i = bits - 1; i >= 0; i--)
        {
            if (!(x >> i & 1))
                continue;
            
            x ^= basis[i];
        }

        return x == 0;
    }

    int queryMIN()
    {
        for (int i = 0; i < bits; i++)
        {
            if (basis[i] != 0)
                return basis[i];
        }
        
        return 0;
    }

    int queryMAX()
    {
        int res = 0;
        for (int i = bits - 1; i >= 0; i--)
        {
            if (basis[i] == 0)
                continue;

            if (!((res >> i) & 1))
                res ^= basis[i];
        }

        return res;
    }
};

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