#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    vector<int> a(30);
    for (int i = 1; i <= 29; i++)
        cin >> a[i];

    int x;
    cin >> x;
    for (int i = 1; i <= 29; i++)
    {
        if (x > a[i])
        {
            if (i <= 3)
                cout << "1\n";
            else if (i <= 9)
                cout << "2\n";
            else if (i <= 18)
                cout << "3\n";
            else 
                cout << "4\n";
            return;
        }
    }

    cout << "4\n";
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