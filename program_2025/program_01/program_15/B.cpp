#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> num;
    for (int i = 0; i < s.length(); i++)
        num.push_back(s[i] - '0');

    sort(num.begin(), num.end());
    do
    {
        int cnt = 0;
        for (int i = 0; i < num.size(); i++)
            cnt = cnt * 10 + num[i];
        
        if (cnt % 4 == 0)
        {
            cout << "YES\n";
            return;
        }
    } while (next_permutation(num.begin(), num.end()));

    cout << "NO\n";
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