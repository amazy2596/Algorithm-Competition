#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> f(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1)
            f[i] = f[i + 1];
        if (s[i] == '1')
            f[i]++;
        else 
            f[i]--;
    }
    f.erase(f.begin());
    sort(f.begin(), f.end(), greater<int>());
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += f[i - 1];
        if (sum >= k)
        {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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