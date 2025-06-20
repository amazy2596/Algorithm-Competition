#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    vector<int> idx(n + 1);
    iota(idx.begin(), idx.end(), 0);
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        a[i].push_back(0);
        for (int j = 1; j < i; j++)
        {
            a[i].push_back(a[j][idx[j]++]);
        }
        while (a[i].size() <= n)
        {
            a[i].push_back(num++);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
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