#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

class SparseTable 
{
    public:
        int n;
        vector<vector<pair<int,int>>> st;
        vector<int> log_table;

        SparseTable(vector<int>& input) 
        {
            n = input.size() - 1;
            log_table.resize(n + 2, 0);

            for (int i = 2; i <= n + 1; i++)
                log_table[i] = log_table[i / 2] + 1;

            int max_log = log_table[n] + 1;
            st.assign(n + 1, vector<pair<int,int>>(max_log, {0, 0}));

            for (int i = 1; i <= n; i++) 
                st[i][0] = {input[i], input[i]};

            for (int j = 1; j < max_log; j++) {
                for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                    pair<int,int> left = st[i][j - 1];
                    pair<int,int> right = st[i + (1 << (j - 1))][j - 1];
                    st[i][j] = {min(left.first, right.first), max(left.second, right.second)};
                }
            }
        }
        int query_mn(int L, int R) 
        {
            int j = log_table[R - L + 1];
            return min(st[L][j].first, st[R - (1 << j) + 1][j].first);
        }
        int query_mx(int L, int R) 
        {
            int j = log_table[R - L + 1];
            return max(st[L][j].second, st[R - (1 << j) + 1][j].second);
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