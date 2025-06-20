#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    const int N = 2e5 + 5;
    intt n, m;
    cin >> n >> m;
    map<intt, intt> f;
    vector<intt> val;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!f[x])
            val.push_back(x);
        f[x]++;
    }
    sort(val.begin(), val.end());
    intt ans = 0;
    for (int i = 0; i < val.size(); i++)
    {
        intt x = val[i];
        intt max_x = min(f[x], m / x);
        for (int k = 0; k <= max_x; k++)
        {
            ans = max(ans, 1ll * k * x);
            if (i < val.size() - 1 && x + 1 == val[i + 1])
            {
                intt y = val[i + 1];
                intt max_y = min(f[y], (m - k * x) / y);
                ans = max(ans, k * x + max_y * y);
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}