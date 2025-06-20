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
    string t = "0";
    for (int i = 0; i < n; i++)
    {
        if (t.empty() || t.back() != s[i])
            t += s[i];
    }
    t.erase(t.begin());

    if (t.length() >= 3)
        cout << n + t.length() - 2 << "\n";
    else if (t.length() == 2)
        cout << n + t.length() - 1 << "\n";
    else 
        cout << n + t.length() << "\n";
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