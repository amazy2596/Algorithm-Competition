#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 1;
    set<int> s;
    s.insert(1);
    for (int i = 0; i < n; i++)
    {
        set<int> temp;
        bool f = 0;
        for (auto p : s)
        {
            if (a[i] * p == x)
            {
                f = 1;
                break;
            }
            else
            {
                temp.insert(p);
                if (x % (a[i] * p) == 0)
                    temp.insert(a[i] * p);
            }
        }
        if (f)
        {
            ans++;
            s.clear();
            s.insert(1);
            s.insert(a[i]);
        }
        else 
            s = temp;
    }
    cout << ans << "\n";
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