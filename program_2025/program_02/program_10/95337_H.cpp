#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int mod = 998244353;
const int N = 1e6 + 5;
int fact[N], ifact[N], p[N];

int fast_pow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        
        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

void init()
{
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = (p[i - 1] * 2) % mod;

    fact[0] = fact[1] = 1;
    for (int i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    
    ifact[N - 1] = fast_pow(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
        ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
}

int C(int n, int m)
{
    if (n < m)
        return 0;
    return (fact[n] % mod * ifact[m] % mod * ifact[n - m] % mod) % mod;
}

int A(int n, int m)
{
    if (n < m)
        return 0;
    return (fact[n] % mod * ifact[n - m] % mod) % mod;
}

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    SparseTable st(a);  

    int ans = 0;
    if (k == 1)
    {
        int mx = st.query_mx(1, n), mn = st.query_mn(1, n);
        cout << (1ll * mn * mx) % mod << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int mx = st.query_mx(i, j), mn = st.query_mn(i, j);
            int len = j - i + 1;
            int t = n - len;
            if (t < k - 1)
                continue;
            int x;
            if (i != 1 && j != n)
                x = C(t - 2, k - 3) * mx % mod * mn % mod % mod;
            if (i == 1 || j == n)
                x = C(t - 1, k - 2) * mx % mod * mn % mod % mod;
            
            ans = (ans + x) % mod;
        }
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    init();
    // cin >> T;
    while (T--)
        solve();
    return 0;
}