#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string target[4] = {"https://ac.nowcoder.com", "https://www.nowcoder.com", "ac.nowcoder.com", "www.nowcoder.com"};
    while (n--)
    {
        string s;
        cin >> s;
        bool f = 1;
        for (int i = 0; i < 4; i++)
        {
            int j = 0, l = 0;
            while (j < target[i].length() && l < s.length())
            {
                if (target[i][j] == s[l])
                    j++, l++;
                else
                    break;
            }
            if (j == target[i].length())
            {
                cout << (i % 2 == 0 ? "Ac\n" : "Nowcoder\n");
                f = 0;
                break;
            }
        }
        if (f)
            cout << "No\n";
    }
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