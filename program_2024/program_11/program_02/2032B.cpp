#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    int pre = k - 1, sub = n - k;
    int diff = abs(pre - sub);
    if (diff % 2 != 0 || (pre == 0 && sub != 0) || (pre != 0 && sub == 0))
    {
        cout << -1 << "\n";
        return;
    }
    if (n == 1 && k == 1)
        ans.push_back(1);
    else if (pre % 2 == 0)
    {
        ans.push_back(1);
        ans.push_back(k - 1);
        ans.push_back(k);
        ans.push_back(k + 1);
        ans.push_back(n);
    }
    else
    {
        ans.push_back(1);
        ans.push_back(k);
        ans.push_back(k + 1);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
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