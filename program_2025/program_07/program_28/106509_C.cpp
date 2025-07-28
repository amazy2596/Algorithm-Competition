#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> a(n + 1), add(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<pair<int, int>> v;
    int ch = s[1], cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ch != s[i])
        {
            v.push_back({ch, cnt});
            ch = s[i];
            cnt = 1;
        }
        else 
            cnt++;
    }
    v.push_back({ch, cnt});

    int pre = 1;
    for (int i = 0; i + 1 < v.size(); i++)
    {
        auto [c1, cnt1] = v[i];
        auto [c2, cnt2] = v[i + 1];

        if (c1 < c2)
        {
            sort(a.begin() + pre, a.begin() + pre + cnt1);
            for (int j = pre; j < pre + cnt1; j++)
            {
                if (a[j] <= m)
                {
                    m -= a[j];
                    add[j] = 1;
                }
                else 
                    break;
            }
        }

        pre += cnt1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (add[i])
            cout << s[i];
        cout << s[i];
    }

    cout << "\n";
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