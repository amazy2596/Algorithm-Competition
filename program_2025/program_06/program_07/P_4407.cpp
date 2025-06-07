#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r){ return uniform_int_distribution<uint>(l, r)(rng); };

const uint mod = (1ull << 61) - 1;
const uint base = rnd(mod / 2, mod - 1);
const int N = 2e5 + 5;
vector<uint> p(N);

uint add(uint a, uint b)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

uint mul(uint a, uint b)
{
    __uint128_t c = __uint128_t(a) * b;
    return add(c >> 61, c & mod);
}

uint query(const vector<uint> &h, int l, int r)
{
    if (r < l)
        return 0ull;
    return add(h[r], mod - mul(h[l - 1], p[r - l + 1]));
}

void init()
{
    p[0] = 1;
    for (int i = 1; i < N; i++)
        p[i] = mul(p[i - 1], base);
}

template<typename T>
vector<uint> build(vector<T> &s)
{
    vector<uint> hashed(s.size(), 0);
    for (int i = 1; i < s.size(); i++)
        hashed[i] = add(mul(hashed[i - 1], base), s[i]);
    return hashed;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    unordered_map<uint, int> mp;
    mp.reserve(n * 2);
    mp.max_load_factor(0.5);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        s = " " + s;
        vector<int> temp;
        for (auto c : s)
            temp.emplace_back(c - 'a' + 1);
        mp[build(temp).back()]++;
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        s = " " + s;
        vector<int> temp;
        for (auto c : s)
            temp.emplace_back(c - 'a' + 1);

        auto h = build(temp);

        if (mp.contains(h.back()))
        {
            cout << "-1\n";
            continue;
        }

        unordered_set<uint> vis;
        int len = s.length() - 1;
        int ans = 0;
        vis.clear();
        vis.reserve((len + 1) * 26 + len);
        vis.max_load_factor(0.5);

        for (int i = 1; i <= len; i++)
        {
            uint l = query(h, 1, i - 1);
            uint r = query(h, i + 1, len);

            uint nh = add(r, mul(l, p[len - i]));
            auto [it_vis, ins] = vis.insert(nh);
            if (!ins) continue;             // 已经算过，跳过
            auto it_mp = mp.find(nh);
            if (it_mp != mp.end())
                ans += it_mp->second;
        }

        for (int i = 1; i <= len + 1; i++)
        {
            uint l = query(h, 1, i - 1);
            uint r = query(h, i, len);
            uint baseH = add(r, mul(l, p[len - i + 2]));
            
            for (int k = 1; k <= 26; k++)
            {
                uint nh = add(baseH, mul(k, p[len - i + 1]));

                auto [it_vis, ins] = vis.insert(nh);
                if (!ins) continue;             // 已经算过，跳过
                auto it_mp = mp.find(nh);
                if (it_mp != mp.end())
                    ans += it_mp->second;
            }
        }

        for (int i = 1; i <= len; i++)
        {
            uint l = query(h, 1, i - 1);
            uint r = query(h, i + 1, len);
            uint baseH = add(r, mul(l, p[len - i + 1]));

            for (int k = 1; k <= 26; k++)
            {
                uint nh = add(baseH, mul(k, p[len - i]));

                auto [it_vis, ins] = vis.insert(nh);
                if (!ins) continue;             // 已经算过，跳过
                auto it_mp = mp.find(nh);
                if (it_mp != mp.end())
                    ans += it_mp->second;
            }
        }

        cout << ans << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}