#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> sta;
    for (int i = 0; i < n; i++)
    {
        if (!sta.empty() && sta.top() == s[i])
            sta.pop();
        else 
            sta.push(s[i]);
    }

    // string t = "";
    // while (!sta.empty())
        // t += sta.top(), sta.pop();
    // reverse(t.begin(), t.end());
    // cout << t << "\n";
    
    cout << sta.size() / 2 << "\n";
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