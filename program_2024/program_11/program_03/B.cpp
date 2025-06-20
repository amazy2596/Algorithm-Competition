#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    int high = n, low = 1;
    int l = 1, r = n;
    while (l <= r)
    {
        p[l++] = high--;
        p[r--] = low++;
    }
    for (int i = 1; i <= n; i++)
        cout << p[i] << " \n"[i == n];
    // for (int i = 1; i <= n; i++)
    //     cout << p[i] + p[p[i]] << " ";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}