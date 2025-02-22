#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> b(m);
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    for (int i = 0; i < b.size(); i++)
    {
        if (s.count(b[i]))
            s.extract(b[i]);
        else 
        {
            if (b[i] == 1)
            {
                cout << "No\n";
                return;
            }

            b.push_back(b[i] / 2);
            b.push_back(ceil(b[i] * 1.0 / 2));
            if (b.size() - i - 1 > s.size())
            {
                cout << "No\n";
                return;
            }
        }
    }
    if (s.size() == 0)
        cout << "Yes\n";
    else 
        cout << "No\n";
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