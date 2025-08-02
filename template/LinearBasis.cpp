#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

const long double eps = 1e-12;
const i64 inf = 1e18; 

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };

struct LinearBasis
{
    int bits;
    vector<int> basis;

    LinearBasis (int _bits) : bits(_bits), basis(vector<int>(bits)) {}

    bool insert(i64 x)
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

    bool exist(i64 x)
    {
        for (int i = bits - 1; i >= 0; i--)
        {
            if (!(x >> i & 1))
                continue;
            
            x ^= basis[i];
        }

        return x == 0;
    }

    i64 queryMIN()
    {
        for (int i = 0; i < bits; i++)
        {
            if (basis[i] != 0)
                return basis[i];
        }
        
        return 0;
    }

    i64 queryMAX()
    {
        i64 res = 0;
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