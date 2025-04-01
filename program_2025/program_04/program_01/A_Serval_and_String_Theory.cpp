#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = n - 1; i >= 0 && k > 0; i--)
    {
        int idx = i;
        for (int j = 0; j < i && k > 0; j++)
        {
            if ((idx == -1 || s[j] > s[idx]))
                idx = j, k--;
        }

        if (idx != i)
            swap(s[i], s[idx]), k--;
    }

    string t = s;
    reverse(s.begin(), s.end());

    cout << (t < s ? "YES\n" : "NO\n");
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