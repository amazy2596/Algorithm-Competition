// Problem: 牛牛的约数
// URL: https://ac.nowcoder.com/acm/contest/116657/E
// Author: amazy
// Date: 2025-09-05 20:07:00

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

i64 lcm(i64 a, i64 b)
{
    i64 res = a / gcd(a, b) * b;
    if (res >= INF)
        return INF;
    return res;
}

template<typename T>
struct SparseTable 
{
    T op(T a, T b) { return lcm(a, b); }
    vector<vector<T>> a;
    int n;

    SparseTable(vector<T>& input) 
    {
        n = input.size();

        int max_log = __lg(n);
        a.assign(n, vector<T>(max_log + 1, 0));

        for (int i = 0; i < n; i++) 
            a[i][0] = input[i];

        for (int j = 1; j <= max_log; j++) 
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++) 
            {
                // [i, i + 2 ^ (j - 1) - 1], [i + 2 ^ (j - 1), i + 2 ^ j - 1];
                a[i][j] = op(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) 
    {
        assert(l <= r && l >= 0 && r < n);

        int j = __lg(r - l + 1);
        // [l, l + 2 ^ j - 1], [r - 2 ^ j + 1, r];
        return op(a[l][j], a[r - (1 << j) + 1][j]);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<pair<i64, i64>> a(n + 1);
    map<i64, i64> id;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first; 
        a[i].second = i;
        id[a[i].first] = a[i].second;
    }

    sort(a.begin() + 1, a.end());
    vector<i64> input(n + 1);
    for (int i = 1; i <= n; i++)
        input[i] = a[i].first;
    SparseTable st(input);
    vector<int> ans(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (i == 1) continue;
        if (a[i].first % st.query(1, i - 1) == 0) continue;
        int l = 1, r = i - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            i64 res = st.query(1, mid);
            if (a[i].first % res != 0)
                r = mid;
            else 
                l = mid + 1;
        }
        ans[a[i].second] = id[a[l].first];
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}