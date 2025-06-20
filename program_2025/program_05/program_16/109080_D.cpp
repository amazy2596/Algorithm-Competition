#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += (s[i] == s[0]);

    if (cnt == n)
    {
        cout << "1\n";
        return;
    }

    int idx = 1;
    while (idx < n && s[idx] == s[0])
        idx++;
    if (idx == cnt)
        cout << 1 + min(3ll, n - cnt) << "\n";
    else 
        cout << 2 << "\n";
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