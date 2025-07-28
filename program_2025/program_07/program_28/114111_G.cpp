#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

int N = 2e5 + 5;
int siz;
struct node
{
    int l, r, id;
    int blk_id;

    bool operator<(node o)
    {
        int blk_o = o.l / siz;
        if (blk_id != blk_o)
            return blk_id < blk_o;

        if (blk_id % 2 == 1)
            return r < o.r;
        else 
            return r > o.r;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    siz = sqrt(n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> freq(N + 1);
    int cnt2 = 0, sum = 0;
    auto add = [&](int val)
    {
        if (freq[val] == 2)
            cnt2--;
        sum += val;
        freq[val]++;
        if (freq[val] == 2)
            cnt2++;
    };

    auto remove = [&](int val)
    {
        if (freq[val] == 2)
            cnt2--;
        sum -= val;
        freq[val]--;
        if (freq[val] == 2)
            cnt2++;
    };

    vector<node> query(q);
    for (int i = 0; i < q; i++)
    {
        cin >> query[i].l >> query[i].r;
        query[i].id = i;
        query[i].blk_id = query[i].l / siz;
    }

    sort(query.begin(), query.end());
    vector<int> ans(q);
    int cur_l = 1, cur_r = 0;
    for (auto [l, r, id, blk_id] : query)
    {
        while (cur_l < l)
            remove(a[cur_l++]);
        while (cur_l > l)
            add(a[--cur_l]);
        while (cur_r < r)
            add(a[++cur_r]);
        while (cur_r > r)
            remove(a[cur_r--]);

        int m = r - l + 1;
        if (m % 2 == 0 && cnt2 == m / 2 && sum == m / 2 * (m / 2 + 1))
            ans[id] = 1;
    }

    for (int i = 0; i < q; i++)
        cout << (ans[i] ? "Yes\n" : "No\n");
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