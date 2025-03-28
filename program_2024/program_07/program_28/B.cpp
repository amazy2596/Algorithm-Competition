#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    if (n % 2 == 1)
    {
        for (int i = n / 2 - 1, j = n / 2 + 1; i >= 0; i--, j++)
        {
            if (s[i] > s[j])
                swap(s[i], s[j]);
            ans += min(s[j] - s[i], s[i] - s[j] + 26);
        }
    }
    else 
    {
        for (int i = n / 2 - 1, j = n / 2; i >= 0; i--, j++)
        {
            if (s[i] > s[j])
                swap(s[i], s[j]);
            ans += min(s[j] - s[i], s[i] - s[j] + 26);
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    solve();
    return 0;
}