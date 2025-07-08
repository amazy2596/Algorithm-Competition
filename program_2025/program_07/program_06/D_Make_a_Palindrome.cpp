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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], cnt[a[i]]++;

    if (k == 1)
    {
        cout << "YES\n";
        return;
    }

    int sum = 0, mx = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += cnt[i];
        if (sum >= k - 1)
        {
            mx = i;
            break;
        }
    }

    vector<int> tmp;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < mx)
            tmp.push_back(a[i]);
    }

    if (tmp.empty())
    {
        cout << "YES\n";
        return;
    }

    auto rtmp = tmp;
    reverse(rtmp.begin(), rtmp.end());

    if (tmp != rtmp)
    {
        cout << "NO\n";
        return;
    }

    if (tmp.size() >= k - 1)
    {
        cout << "YES\n";
        return;
    }

    vector<int> idx;
    idx.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < mx)
            idx.push_back(i);
    }

    idx.push_back(n + 1);

    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + (a[i] == mx);

    int add = 0;
    for (int i = 0; i < (idx.size() - 1) / 2; i++)
    {
        int ni = idx.size() - i - 1;
        int L = pre[idx[i + 1] - 1] - pre[idx[i]];
        int R = pre[idx[ni] - 1] - pre[idx[ni - 1]];
        add += 2 * min(L, R);
    }

    if (idx.size() % 2 == 0)
    {
        int mid = (idx.size() - 1) / 2;
        add += pre[idx[mid + 1] - 1] - pre[idx[mid]];
    }

    if (tmp.size() + add >= k - 1)
    {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}