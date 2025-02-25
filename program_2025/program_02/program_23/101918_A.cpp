#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int id = 0;
    while (n > 500)
    {
        n -= 500;
        id++;
    }

    cout << char('A' + id);
    string s = to_string(n);
    while (s.length() < 3)
        s.insert(s.begin(), '0');
    cout << s;
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