#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

class ST
{
    public:
        int n;
        vector<vector<int>> st_max;
        vector<int> log_table;

        ST(vector<int> &input)
        {
            n = input.size();
            log_table.resize(n + 1, 0);

            for (int i = 2; i <= n + 1; i++)
                log_table[i] = log_table[i / 2] + 1;

            int max_log = log_table[n] + 1;
            st_max.resize(n + 1, vector<int>(max_log, 0));

            for (int i = 1; i <= n; i++)
                st_max[i][0] = input[i];

            for (int j = 1; j < max_log; j++)
                for (int i = 1; i + (1ll << j) - 1 <= n; i++)
                    st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1ll << (j - 1))][j - 1]);
        }

        int query(int l, int r)
        {
            int j = log_table[r - l + 1];
            return max(st_max[l][j], st_max[r - (1ll << j) + 1][j]);
        }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ST st(a);
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}