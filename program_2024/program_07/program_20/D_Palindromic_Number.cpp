#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    // intt n;
    // cin >> n;
    int ans = 0;
    for (int i = 1e6; i < 1e7; i++)
    {
        string s = to_string(i);
        int l = 0, r = s.length() - 1;
        bool f = 1;
        while (l < r)
        {
            if (s[l++] != s[r--])
            {                f = 0;
                break;
            }
        }
        ans += f;
    }
    cout << ans << '\n';
    return 0;
}