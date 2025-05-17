#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> cnt(10);
    for (int i = 0; i < s.length(); i++)
        cnt[s[i] - '0']++;

    int idx = 9;
    while (idx >= 0)
    {
        for (int i = 0; i <= 9; i++)
        {
            if (i >= idx && cnt[i] > 0)
            {
                cout << i;
                cnt[i]--;
                idx--;
                break;
            }
        }
    }

    cout << "\n";
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