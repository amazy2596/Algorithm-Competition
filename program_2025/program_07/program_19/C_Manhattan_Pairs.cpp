#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct node
{
    int x, y, id;

    // bool operator<(node o)
    // {
        // pair<int, int> a = make_pair(x, y);
        // pair<int, int> b = make_pair(o.x, o.y);
        // return a < b;
    // }
};

void solve()
{
    int n;
    cin >> n;
    vector<node> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }

    sort(a.begin() + 1, a.end(), [&](node &a, node &b) {
        return a.x < b.x;
    });

    sort(a.begin() + 1, a.begin() + n / 2 + 1, [&](node &a, node &b) {
        return a.y > b.y;
    });
    sort(a.begin() + n / 2 + 1, a.end(), [&](node &a, node &b) {
        return a.y < b.y; 
    });

    // int sum = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        int j = i + n / 2;
        cout << a[i].id << " " << a[j].id << "\n";
        // sum += abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
    }

    // cout << sum << "\n";
}

signed main()
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