// Problem: L3-2 整理书籍
// URL: https://ac.nowcoder.com/acm/contest/104429/N
// Author: amazy
// Date: 2026-03-06 22:44:05

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct Fenwick
{
    vector<int> f;
    int n;

    Fenwick(int _n) : n(_n), f(_n + 1) {}
    
    int lowbit(int x) { return (x & -x); }

    void add(int p, int k)
    {
        while (p <= n)
        {
            f[p] += k;
            p += lowbit(p);
        }
    }

    int pre (int p)
    {
        int sum = 0;
        while (p > 0)
        {
            sum += f[p];
            p -= lowbit(p);
        }

        return sum;
    }

    int query (int l, int r) { return pre(r) - pre(l - 1); };
};

void solve()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> a(n1), b(n2);
    for (int i = 0; i < n1; i++) cin >> a[i];
    for (int i = 0; i < n2; i++) cin >> b[i];

    vector<int> v(n1 + n2 + 1), pos(n1 + n2 + 1);
    for (int i = 1; i <= n1; i++) v[i] = a[n1 - i];
    for (int i = n1 + 1; i <= n1 + n2; i++) v[i] = b[i - n1 - 1];
    for (int i = 1; i <= n1 + n2; i++) pos[v[i]] = i;
    // 5 4 1 2 6 3

    Fenwick fw(n1 + n2);
    i64 ans = 0, cp = n1;
    for (int num = n1 + n2; num >= 1; num--)
    {
        int tp = pos[num];
        if (cp < tp - 1)
        {
            int hr = fw.query(cp + 1, tp - 1);
            ans += tp - 1 - cp - hr;
            cp = tp - 1;
        }
        else if (cp > tp)
        {
            int hr = fw.query(tp + 1, cp);
            ans += cp - tp - hr;
            cp = tp;
        }
        fw.add(tp, 1);
    }

    cout << ans << "\n";
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