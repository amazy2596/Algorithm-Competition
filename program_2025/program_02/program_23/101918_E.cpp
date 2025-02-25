#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    if (k == 1)
    {
        cout << "Yes\n";
        return;
    }

    vector<int> b = a;
    sort(b.begin() + 1, b.end());

    map<int, int> last;
    for (int i = 1; i <= n; i++)
    {
        if (last.count(b[i] - k))
            last[b[i]] = last[b[i] - k];
        else 
            last[b[i]] = b[i];
    }

    map<int, vector<int>> mp1, mp2;
    for (int i = 1; i <= n; i++)
    {
        mp1[last[a[i]]].push_back(i % k);
        mp2[last[b[i]]].push_back(i % k);
    }

    for (auto &[key, va] : mp1)
    {
        if (mp2.find(key) == mp2.end())
        {
            cout << "No\n";
            return;
        }

        auto &vb = mp2[key];

        if (va.size() != vb.size())
        {
            cout << "No\n";
            return;
        }

        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());

        if (va != vb)
        {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
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