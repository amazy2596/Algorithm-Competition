#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    for (int k = 0; k < b.length(); k++)
    {
        int i = k, j = 0, cur = 0;
        while(j < a.length())
        {
            if (a[j] == b[i])
            {
                i++, j++;
                cur++;
            }
            else
                j++;
        }
        cnt = max(cnt, cur);
    }
    cout << a.length() + b.length() - cnt << "\n";
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