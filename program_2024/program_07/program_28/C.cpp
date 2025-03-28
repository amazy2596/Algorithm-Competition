#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x, y, z;
    cin >> x >> y >> z;
    int ans = 0;
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            count++;
        if (s[i] == '0' && count > 0)
            ans++, count--;
    }
    cout << min(ans, y) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    solve();
    return 0;
}