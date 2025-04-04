#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string d;
    cin >> d;

    reverse(d.begin(), d.end());
    while (n--)
    {
        int t = 0;
        for (int i = 0; i < d.length(); i++)
        {
            if (d[i] == '.')
                continue;
            int x = (d[i] - '0') * 2 + t;
            d[i] = (char)(x % 10 + '0');
            t = x / 10;
        }

        if (t)
            d.push_back('1');

        // for (int i = d.length() - 1; i >= 0; i--)
        //     cout << d[i];
        // cout << "\n";
    }
    
    int point = d.find('.');
    if (point != -1)
    {
        if (d[point - 1] >= '5')
        {
            int t = 1;
            for (int i = point + 1; i < d.length(); i++)
            {
                int x = (t + d[i] - '0');
                d[i] = (char)(x % 10 + '0');
                t = x / 10;
            }
        }
    }

    reverse(d.begin(), d.end());
    cout << d.substr(0, d.find('.')) << "\n";
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