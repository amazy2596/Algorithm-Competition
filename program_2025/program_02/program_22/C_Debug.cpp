#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == 'W' && s[i] == 'A')
        {
            s[i - 1] = 'A';
            s[i] = 'C';
            int j = i - 1;
            while (j >= 1 && s[j - 1] == 'W' && s[j] == 'A')
            {
                s[j - 1] = 'A';
                s[j] = 'C';
                j--;
            }
        }
    }

    cout << s << "\n";
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