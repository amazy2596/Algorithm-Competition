#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int g = a[0];
    for (int i = 0; i < n; i++)
        g = __gcd(g, a[i]);

    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += (a[i] == g);

    if (cnt)
    {
        cout << n - cnt << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
        a[i] /= g;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int mx = *max_element(a.begin(), a.end());

    queue<pair<int, int>> q;
    vector<int> dp(mx + 1, inf);
    for (int i = 0; i < n; i++)
    {
        dp[a[i]] = 1;
        q.push({a[i], 1});
    }

    while (!q.empty())
    {
        auto [cur, cnt] = q.front();
        q.pop();

        for (int j = 0; j < n; j++)
        {
            int ncur = __gcd(cur, a[j]);
            if (dp[ncur] > cnt + 1)
            {
                dp[ncur] = cnt + 1;
                q.push({ncur, cnt + 1});
            }

            if (ncur == 1)
                break;
        }
    }

    cout << n + dp[1] - 2 << "\n";
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