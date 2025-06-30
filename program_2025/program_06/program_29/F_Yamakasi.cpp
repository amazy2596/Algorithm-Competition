#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct SparseTable 
{
    int n;
    vector<vector<int>> st_min;  
    vector<vector<int>> st_max;  
    vector<int> log_table;

    SparseTable(vector<int>& input) {
        n = input.size();
        log_table.resize(n + 2, 0);

        for (int i = 2; i <= n + 1; i++)
            log_table[i] = log_table[i / 2] + 1;

        int max_log = log_table[n] + 1;
        st_min.assign(n + 1, vector<int>(max_log, inf));
        st_max.assign(n + 1, vector<int>(max_log, -inf));

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
    int n, s, x;
    cin >> n >> s >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    SparseTable st(a);

    vector<int> L(n + 1), R(n + 1);
    int last_pre = -1, last_x = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > x)
            last_pre = i;
        if (a[i] == x)
            last_x = i;
        L[i] = last_pre;
        R[i] = last_x;
    }

    int ans = 0;
    map<int, vector<int>> mp;
    int sum = 0;
    mp[0].push_back(0);
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        int tar = sum - s;
        if (mp.find(tar) != mp.end())
        {
            // for (auto l : mp[tar])
            // {
                // int mx = st.query_mx(l + 1, i);
                // if (mx == x)
                    // ans++;
            // }

            auto &v = mp[tar];
            int l = L[i], r = R[i];

            if (r > l)
            {
                auto it_l = lower_bound(v.begin(), v.end(), l);
                auto it_r = lower_bound(v.begin(), v.end(), r);
                ans += distance(it_l, it_r);
            }
        }

        mp[sum].push_back(i);
    }

    cout << ans << "\n";
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