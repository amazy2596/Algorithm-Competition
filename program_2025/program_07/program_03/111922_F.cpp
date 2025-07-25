#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct LinearBasis
{
    int bits;
    vector<int> basis;

    LinearBasis (int _bits) : bits(_bits), basis(vector<int>(bits)) {}

    void insert(int x)
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
                break;
            }
        }
    }

    bool query(int x)
    {
        for (int i = bits - 1; i >= 0; i--)
        {
            if (!(x >> i & 1))
                continue;

            if (basis[i] == 0)
                return false;
            
            x ^= basis[i];
        }

        return x == 0;
    }
};

void solve()
{
    int n;
    cin >> n;
    
    int bit = 60;
    LinearBasis lb(bit);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        lb.insert(x);
    }

    for (int i = 0; i < bit; i++)
    {
        if (!lb.query(1ll << i))
        {
            cout << (1ll << i) << "\n";
            return; 
        }
    }

    cout << (1ll << bit) << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}