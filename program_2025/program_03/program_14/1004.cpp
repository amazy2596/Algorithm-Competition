#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s, k;
    cin >> s >> k;
    int num = 0;
    if (k.length() <= 2)
    {
        for (int i = 0; i < k.length(); i++)
            num = (num * 10 + k[i] - '0');
    }
    else 
        num = 30;
    string temp = "";
    for (int i = 0; i < min(30ll, num); i++)
        temp += s;
    s = temp;
    
    vector<int> dp(26);
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (s[j] < s[i])
                dp[s[i] - 'a'] = max(dp[s[i] - 'a'], dp[s[j] - 'a'] + 1);
        }
        dp[s[i] - 'a'] = max(dp[s[i] - 'a'], 1ll);
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";
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