#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    if (n % 3 != 0 && n <= 36)
    {
        cout << "Baka!\n";
        return;
    }

    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);

    for (int i = 3; i <= n; i += 3)
    {
        swap(a[i - 1], a[i]);
    }

    if (n % 3 != 0)
        swap(a[37], a[n]);

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
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