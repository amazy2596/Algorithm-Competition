#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1), d(n);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> d[i];

    set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (p[d[i]] == d[i])
            s.insert(d[i]);
        else 
        {
            int idx = d[i];
            while (p[idx] != idx && s.count(p[idx]) == 0)
            {
                s.insert(p[idx]);
                idx = p[idx];
            }
        }
            

        cout << s.size() << " ";
    }

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