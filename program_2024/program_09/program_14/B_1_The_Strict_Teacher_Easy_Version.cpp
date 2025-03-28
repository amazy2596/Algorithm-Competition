#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(b.begin(), b.end());
    while (q--)
    {
        int a;
        cin >> a;
        if (b[0] < a && a < b[1])
            cout << (b[1] - b[0]) / 2 << "\n";
        else if (a < b[0])
            cout << b[0] - 1 << "\n";
        else 
            cout << n - b[1] << "\n";
    }       
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