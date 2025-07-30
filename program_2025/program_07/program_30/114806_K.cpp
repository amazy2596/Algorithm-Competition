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
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    stack<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && h[s.top()] < h[i])
        {
            int mid = s.top();
            s.pop();

            if (!s.empty())
            {
                int width = i - s.top() - 1;
                int tmp = min(h[i], h[s.top()]) - h[mid];
                ans += width * tmp;
            }
        }
        s.push(i);
    }

    cout << ans << "\n";
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