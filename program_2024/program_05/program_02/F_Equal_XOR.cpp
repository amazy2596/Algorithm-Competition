#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1, 0);
        vector<int> prefixxor(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            prefixxor[i] = prefixxor[i - 1] ^ a[i];
        }
        map<int, vector<int>> mp;
        mp[0].push_back(0);
        for (int i = 1; i <= n; i++)
            mp[prefixxor[i]].push_back(i);
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            if ((prefixxor[l - 1] ^ prefixxor[r]) == 0)
            {
                cout << "YES\n";
                continue;
            }
            auto x = lower_bound(mp[prefixxor[l - 1]].begin(), mp[prefixxor[l - 1]].end(), r);
            auto y = lower_bound(mp[prefixxor[r]].begin(), mp[prefixxor[r]].end(), l);
            x--;
            if (y == mp[prefixxor[r]].end() || *x <= *y)
                cout << "NO\n";
            else 
                cout << "YES\n";
        }
        cout << "\n";
    }
    return 0;
}