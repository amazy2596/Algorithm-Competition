#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, d;
    cin >> n >> d;
    // int temp = 1;
    // while (temp < 1e18l)
    // {
    //     if (temp % 3 == 0)
    //         cout << to_string(temp).size() << " " << temp << "\n";
    //     temp = temp * 10 + 1;
    // }
    vector<int> ans;
    ans.push_back(1);

    if (d % 3 == 0 || n >= 3)
        ans.push_back(3);

    if (d == 5)
        ans.push_back(5);
    
    if (d == 7 || n >= 3)
        ans.push_back(7);
    
    if (d == 9 || (d % 3 == 0 && n >= 3) || n >= 6)
        ans.push_back(9);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
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