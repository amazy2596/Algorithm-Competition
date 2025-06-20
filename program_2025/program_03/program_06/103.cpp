#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    int mx = 0;
    map<int, vector<int>> mp;
    for (int i = a; i <= b; i++)
    {
        int x = i;
        int cnt = 0;
        while (x >= 10)
        {
            cnt++;
            int temp = 1;
            while (x)
            {
                temp *= x % 10;
                x /= 10;
            }
            x = temp;
        }

        if (cnt >= mx)
        {
            mx = cnt;
            mp[cnt].push_back(i);
        }
    }

    cout << mx << "\n";
    for (int i = 0; i < mp[mx].size(); i++)
        cout << mp[mx][i] << " \n"[i == mp[mx].size() - 1];
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