#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        intt n, tot = 0;
        cin >> n;
        vector<vector<intt>> v(3, vector<intt>(n + 1));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> v[i][j];
                if (i == 0)
                    tot += v[i][j];
                v[i][j] += v[i][j - 1];
            }
        }        
        bool f = 0;
        tot = ceil(tot * 1.0 / 3);
        vector<int> p(3);
        iota(p.begin(), p.end(), 0);
        do 
        {
            int l = lower_bound(v[p[0]].begin() + 1, v[p[0]].end(), tot) - v[p[0]].begin();
            int r = lower_bound(v[p[1]].begin() + l + 1, v[p[1]].end(), tot + v[p[1]][l]) - v[p[1]].begin();
            if (r >= n || v[p[2]][n] - v[p[2]][r] < tot)
                continue;
            else 
            {
                f = 1;
                vector<pair<int, int>> ans = {{1, l}, {l + 1, r}, {r + 1, n}};
                for (int i = 0; i < 3; i++)
                {
                    if (p[i] == 0)
                        cout << ans[i].first << " " << ans[i].second << " ";
                }
                for (int i = 0; i < 3; i++)
                {
                    if (p[i] == 1)
                        cout << ans[i].first << " " << ans[i].second << " ";
                }
                for (int i = 0; i < 3; i++)
                {
                    if (p[i] == 2)
                        cout << ans[i].first << " " << ans[i].second << " \n";
                }
                break;
            }
        } while (next_permutation(p.begin(), p.end()));
        if (!f)
            cout << -1 << "\n";
    }
    return 0;
}