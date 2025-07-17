#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

struct SparseTable 
{
    int n;
    vector<vector<int>> st_min;  
    vector<vector<int>> st_max;  
    vector<int> log_table;

    SparseTable(vector<int>& input) {
        n = input.size();
        log_table.resize(n, 0);

        for (int i = 2; i <= n + 1; i++)
            log_table[i] = log_table[i / 2] + 1;

        int max_log = log_table[n] + 1;
        st_min.assign(n, vector<int>(max_log, 0));
        st_max.assign(n, vector<int>(max_log, 0));

        for (int i = 1; i <= n; i++) 
        {
            st_min[i][0] = input[i];
            st_max[i][0] = input[i];
        }

        for (int j = 1; j < max_log; j++) 
        {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) 
            {
                // [i + 2 ^ (j - 1) - 1, i + 2 ^ j - 1], [i + 2 ^ (j - 1), i + 2 ^ j - 1];
                st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query_mn(int l, int r) 
    {
        int j = log_table[r - l + 1];
        // [l, l + 2 ^ j - 1], [r - 2 ^ j + 1, r];
        return min(st_min[l][j], st_min[r - (1 << j) + 1][j]);
    }

    int query_mx(int l, int r) 
    {
        int j = log_table[r - l + 1];
        return max(st_max[l][j], st_max[r - (1 << j) + 1][j]);
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