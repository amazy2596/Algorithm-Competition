// Problem: 小月的前缀
// URL: https://ac.nowcoder.com/acm/contest/125084/D
// Author: amazy
// Date: 2026-03-10 10:45:11

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct Fenwick
{
    i64 n;
    vector<i64> a;

    Fenwick() {}
    Fenwick(i64 _n) : n(_n), a(_n + 1) {}

    i64 lowbit(i64 x)
    {
        return x & -x;
    }

    void update(i64 x, i64 k)
    {
        while (x >= 1 && x <= n)
        {
            a[x] += k;
            x += lowbit(x);
        }
    }

    i64 pre(i64 r)
    {
        i64 res = 0;   

        while (r > 0)
        {
            res += a[r];
            r -= lowbit(r);
        }

        return res;
    }

    i64 query(i64 l, i64 r)
    {
        return pre(r) - pre(l - 1);
    }

    i64 kth(i64 k)
    {
        i64 ans = 0;
        for (i64 p = __lg(n); p >= 0; p--)
        {
            i64 step = 1ll << p;
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
    vector<i64> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    i64 T = pre[n];

    vector<i64> v = pre;
    for (int i = 1; i <= n; i++) v.push_back(pre[i] - T);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    v.insert(v.begin(), 0);

    int m = v.size() - 1;
    unordered_map<i64, int> id;
    for (int i = 1; i <= m; i++) id[v[i]] = i;
    Fenwick bitL(m), bitR(m);

    // for (auto [key, val] : id) cout << key << " " << val << "\n";

    // a1, a2 ... an
    // ar+1 ar+2 ... an a1 a2 ... ar
    // s[r + k] - s[r] > 0 -> s[r + k] > s[r]
    // T - s[r] + s[k - (n - r)] > 0 -> s[k - (n - r)] > s[r] - T;
    for (int i = 1; i <= n; i++) bitR.update(id[pre[i]], 1);

    int ans = n + 1, score = 0;
    for (int r = 0; r < n; r++)
    {
        // cout << "r: " << r << "\n";
        // for (int i = 1; i <= m; i++) cout << bitL.query(i, i) << " \n"[i == m];
        // for (int i = 1; i <= m; i++) cout << bitR.query(i, i) << " \n"[i == m];
        int cntR = bitR.query(id[pre[r]] + 1, m);
        int cntL = bitL.query(id[pre[r] - T] + 1, m);
        bitR.update(id[pre[r + 1]], -1);
        bitL.update(id[pre[r + 1]], 1);
        if (cntL + cntR > score)
        {
            score = cntL + cntR;
            ans = r;
        }
        else if (cntL + cntR == score) 
        {
            ans = min(ans, r);
        }
    }

    cout << ans << " " << score << "\n";
}

int main()
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