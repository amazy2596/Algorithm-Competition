#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 0, last = -1, num = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 && i - last > 1)
            cnt++;
        if (a[i] == 0)
            num++, last = i;
    }
    cnt += n - last > 1;
    if (num == n)
        cout << "0\n";
    else 
        cout << (cnt > 2 ? 2 : cnt) << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}