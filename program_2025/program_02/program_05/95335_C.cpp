#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e6 + 5;
int trie[N][26];

void solve()
{
    int n, m;
    cin >> n >> m;
    int edges = 0;
    int tot = 0;
    int mx = 0;

    auto insert = [&](string s)
    {
        int p = 0;
        for (auto ch : s)
        {
            int idx = ch - 'a';
            if (trie[p][idx] == 0)
            {
                trie[p][idx] = ++tot;
                edges++;
            }
            p = trie[p][idx];
        }
    };

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mx = max(mx, (int)(s.length()));
        insert(s);
    }

    cout << 2 * edges - mx << "\n";
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