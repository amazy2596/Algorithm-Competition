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

template<typename T>
struct Fenwick
{
    int n;
    vector<T> a;

    Fenwick(int _n) : n(_n), a(_n + 1) {}

    int lowbit(int x)
    {
        return x & -x;
    }

    void update(int x, T k)
    {
        while (x >= 1 && x <= n)
        {
            a[x] += k;
            x += lowbit(x);
        }
    }

    T pre(int r)
    {
        T res = 0;   

        while (r > 0)
        {
            res += a[r];
            r -= lowbit(r);
        }

        return res;
    }

    T query(int l, int r)
    {
        return pre(r) - pre(l - 1);
    }

    int kth(int k)
    {
        int ans = 0;
        for (int p = __lg(n); p >= 0; p--)
        {
            int step = 1ll << p;
            if (ans + step <= n && a[ans + step] < k)
            {
                k -= a[ans + step];
                ans += step;
            }
        }

        return ans + 1;
    }
};

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    reverse(b.begin(), b.end());
    string s = " " + b + a;
    n = s.length() - 1;
    int m = b.length();
    vector<i64> pre0(n + 1), pre1(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre0[i] = pre0[i - 1] + (s[i] == '0');
        pre1[i] = pre1[i - 1] + (s[i] == '1');
        p[i] = pre1[i] - pre0[i];
    }

    Fenwick<i64> fw1(2 * n + 1), fw2(2 * n + 1), fw3(2 * n + 1);
    int offset = n + 1;
    i64 ans = 0, sum_i = 0, sum_p = 0;
    for (int j = 1; j <= n; j++)
    {
        if (j > m)
        {
            int idx = p[j] + offset;
            i64 count1 = fw1.query(1, idx);
            i64 sum_i_1 = fw2.query(1, idx);
            i64 sum_p_1 = fw3.query(1, idx);

            i64 count2 = m - count1;
            i64 sum_i_2 = sum_i - sum_i_1;
            i64 sum_p_2 = sum_p - sum_p_1;

            i64 tmp = count1 * pre0[j] - (sum_i_1 - sum_p_1) / 2 + count2 * pre1[j] - (sum_i_2 + sum_p_2) / 2;
            ans += tmp;
        }

        if (j <= m)
        {
            fw1.update(p[j - 1] + offset, 1);
            fw2.update(p[j - 1] + offset, j - 1);
            fw3.update(p[j - 1] + offset, p[j - 1]);
            sum_i += j - 1;
            sum_p += p[j - 1];
        }
    }

    cout << ans << "\n";
}

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}