#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 inf = 1e18; 

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](u64 l, u64 r) { return (l <= r ? uniform_int_distribution<u64>(l, r)(rng) : 0); };

struct Chtholly
{
    map<int, pair<int, int>> internals;
    unordered_map<int, int> cnt;

    Chtholly() {}

    void add(int l, int r, int val)
    {
        internals[l] = {r, val};
        cnt[val] = r - l + 1;
    }

    void split(int pos)
    {
        auto it = internals.lower_bound(pos);

        if (it == internals.begin())
            return ;

        it--;

        int L = it->first;
        auto [R, val] = it->second;

        if (L == pos)
            return ;

        if (R < pos)
            return ;

        internals[L] = {pos - 1, val};
        internals[pos] = {R, val};
    }

    void assign(int l, int r, int val)
    {
        split(l);
        split(r + 1);

        unordered_set<int> toerase;
        for (auto it = internals.lower_bound(l); it != internals.end(); it++)
        {
            int L = it->first;
            auto [R, x] = it->second;

            if (r < L)
                break;

            toerase.insert(L);
            cnt[x] -= (R - L + 1);
        }

        for (auto temp : toerase)
            internals.erase(temp);

        cnt[val] += (r - l + 1);
        internals[l] = {r, val};
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