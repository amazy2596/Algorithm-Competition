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

const int N = 1e6 + 5;
vector<int> minp(N), prime;

void init()
{
    for (int i = 2; i < N; i++)
    {
        if (minp[i] == 0)
        {
            minp[i] = i;
            prime.push_back(i);
        }

        for (auto p : prime)
        {
            if (i * p >= N)
                break;

            minp[i * p] = p;

            if (minp[i] == p)
                break;
        }
    }
}

void solve()
{
    
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}