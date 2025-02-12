#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

class SparseTable_gcd 
{
    public:
        int n;                      
        vector<vector<int>> st;     
        vector<int> log_table;      

        SparseTable_gcd(vector<int> &input) 
        {
            n = input.size() - 1;
            log_table.resize(n + 2, 0);
            
            for (int i = 2; i <= n + 1; i++)
                log_table[i] = log_table[i / 2] + 1;

            int max_log = log_table[n] + 1;
            st.assign(n + 1, vector<int>(max_log, 0));

            for (int i = 1; i <= n; i++)
                st[i][0] = input[i];

            for (int j = 1; j < max_log; j++) 
                for (int i = 1; i + (1LL << j) - 1 <= n; i++)
                    st[i][j] = __gcd(st[i][j - 1], st[i + (1LL << (j - 1))][j - 1]);
        }
        
        int query(int L, int R) 
        {
            int len = R - L + 1;
            int j = log_table[len];
            return __gcd(st[L][j], st[R - (1LL << j) + 1][j]);
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