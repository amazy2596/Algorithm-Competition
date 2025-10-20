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

string tmps = "UDLR";
vector<pair<int, int>> tmpv = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0}
};

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<pair<int, int>> p;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }

    

}

int main()
{
    ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}