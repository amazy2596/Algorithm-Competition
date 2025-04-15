#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(2 * n + 1);
    set<int> s;
    for (int i = 1; i <= 2 * n; i++)
        s.insert(i);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int g;
            cin >> g;
            p[i + j] = g;
            s.erase(g);
        }
    }
    p[1] = *s.begin();

    for (int i = 1; i <= 2 * n; i++)
        cout << p[i] << " ";
    cout << "\n";
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