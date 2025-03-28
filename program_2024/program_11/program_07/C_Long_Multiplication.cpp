#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    int f = -1;
    for (int i = 0; i < a.length(); i++)
    {
        if (f == -1)
        {
            if (a[i] > b[i])
                f = 1;
            else if (a[i] < b[i])
                f = 2;
        }
        else if (f == 1 && a[i] > b[i])
            swap(a[i], b[i]);
        else if (f == 2 && a[i] < b[i])
            swap(a[i], b[i]);
    }
    cout << a << "\n" << b << "\n";
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