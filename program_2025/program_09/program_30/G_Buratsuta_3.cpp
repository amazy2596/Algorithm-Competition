// Problem: G. Buratsuta 3
// URL: https://codeforces.com/contest/2149/problem/G
// Author: amazy
// Date: 2025-09-30 18:41:14

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

struct query
{
    int blk_id, id;
    int l, r;

    bool operator<(const query &o)
    {
        if (blk_id != o.blk_id) return blk_id < o.blk_id;
        if (blk_id & 1) return r < o.r;
        return r > o.r;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> real(n + 1);
    vector<int> all;
    for (int i = 1; i <= n; i++)
    {
        cin >> real[i];
        all.push_back(real[i]);
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    map<int, int> id;
    vector<int> rev(all.size());
    for (int i = 0; i < all.size(); i++)
    {
        id[all[i]] = i;
        rev[i] = all[i];
    }

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = id[real[i]];

    // vector<int> a(n + 1);
    // for (int i = 1; i <= n; i++)
    //     cin >> a[i];

    // auto v = a;
    // sort(v.begin(), v.end());
    // v.erase(unique(v.begin(), v.end()), v.end());

    // for (int i = 1; i <= n; i++)
    //     a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();

    int blk_siz = max(1, (int)sqrt(n));
    vector<query> querys(q);
    for (int i = 0; i < q; i++)
    {
        cin >> querys[i].l >> querys[i].r;
        querys[i].id = i;
        querys[i].blk_id = querys[i].l / blk_siz;
    }
    sort(querys.begin(), querys.end());

    vector<int> freq(n + 1);
    auto add = [&](int idx)
    {
        freq[a[idx]]++;
    };
    auto remove = [&](int idx)
    {
        freq[a[idx]]--;
    };

    int curl = 1, curr = 0;
    vector<array<int, 2>> ans(q, {-1, -1});
    for (auto que : querys)
    {
        int l = que.l, r = que.r;
        while (curl < que.l)
            remove(curl++);
        while (curl > que.l)
            add(--curl);
        while (curr < que.r)
            add(++curr);
        while (curr > que.r)
            remove(curr--);

        int tar = (r - l + 1) / 3;
        // vector<int> tmp;
        // for (int i = 0; i < 40; i++)
        // {
        //     int idx = rnd(l, r);
        //     if (freq[a[idx]] > tar) tmp.push_back(v[a[idx]]);
        // }
        // ranges::sort(tmp);
        // tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        // if (tmp.size() >= 1)
        //     ans[que.id][0] = tmp[0];
        // if (tmp.size() >= 2)
        //     ans[que.id][1] = tmp[1];
        set<int> s;
        for (int i = 0; i < 50; i++)
        {
            int idx = rnd(l, r);
            if (freq[a[idx]] > tar) s.insert(rev[a[idx]]);
        }
        if (s.size() >= 1)
            ans[que.id][0] = *s.begin();
        if (s.size() >= 2)
            ans[que.id][1] = *s.rbegin();
    }

    for (auto [x, y] : ans)
    {
        if (x == -1 && y == -1)
        {
            cout << "-1\n";
            continue;
        }
        if (x != -1) cout << x << " ";
        if (y != -1) cout << y << " ";
        cout << "\n";
    }
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