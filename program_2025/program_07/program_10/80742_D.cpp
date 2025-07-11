#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;

    vector<int> r(n + 1), e(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++)
    {
        r[i] = r[i - 1] + (s[i] == 'r');
        e[i] = e[i - 1] + (s[i] == 'e');
        d[i] = d[i - 1] + (s[i] == 'd');
    }

    while (q--)
    {
        int start, end;
        cin >> start >> end;

        if (end - start + 1 <= 2)
        {
            cout << "0\n";
            continue;
        }

        int len = (end - start + 1) / 3;
        int remain = (end - start + 1) % 3;
        int ans = inf;

        for (int k = 0; k < 8; k++)
        {
            int a = (k >> 2 & 1), b = (k >> 1 & 1), c = (k >> 0 & 1);
            if (a + b + c != remain)
                continue;

            int l1 = start, r1 = l1 + len - 1 + a;
            int l2 = r1 + 1, r2 = l2 + len + b - 1;
            int l3 = r2 + 1, r3 = l3 + len + c - 1;

            int tmp = 0;
            tmp += r[r1] - r[l1 - 1];
            tmp += e[r2] - e[l2 - 1];
            tmp += d[r3] - d[l3 - 1];

            ans = min(ans, (end - start + 1) - tmp);
        }

        cout << ans << "\n";
    }
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