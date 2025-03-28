#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    n <<= 1;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> ans(n / 2 + 1);
    int rank = n / 2, idx = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(')
        {
            rank--;
            ans[idx++] = rank;
        }
        else
            rank++;
        if (rank < 0 || rank > n / 2)
        {
            cout << -1 << "\n";
            return;
        }
    }
    for (int i = 1; i <= n / 2; i++)
        cout << ans[i] << " ";
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