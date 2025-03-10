#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int m, k;
    cin >> m >> k;
    vector<string> w(m), op(m);
    for (int i = 0; i < k; i++)
        cin >> w[i] >> op[i];

    set<string> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i].length() != m)
            continue;
        
        set<char> count;
        for (int j = 0; j < m; j++)
            count.insert(s[i][j]);

        bool ok = 1;
        string col('B', m);
        for (int idx = 0; idx < k; idx++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s[i][j] == w[idx][j])
                    col[idx] = 'G';
                else if (count.contains(w[idx][j]))
                    col[idx] = 'Y';
                else if (!count.contains(w[idx][j]))
                    col[idx] = 'B';
            }
        }

        
    }

    cout << st.size() << "\n";
    for (auto cur : st)
        cout << cur << "\n";
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