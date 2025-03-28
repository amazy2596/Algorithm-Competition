#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> ans;
    int i = 0;
    while (i < s.length())
    {
        int j = s.find('|', i + 1);
        if (j == -1)
            break;
        ans.push_back(j - i - 1);
        i = j;
    }
    for (auto a : ans)
        cout << a << " ";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}