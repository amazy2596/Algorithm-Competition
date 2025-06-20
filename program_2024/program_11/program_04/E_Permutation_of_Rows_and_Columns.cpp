#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    vector<vector<int>> aa(m, vector<int>(n)), bb(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j], aa[j][i] = a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j], bb[j][i] = b[i][j];
    for (int i = 0; i < n; i++)
    {
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
    }
    for (int j = 0; j < m; j++)
    {
        sort(aa[j].begin(), aa[j].end());
        sort(bb[j].begin(), bb[j].end());
    }
    sort(a.begin(), a.end(), [&](vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    });
    sort(aa.begin(), aa.end(), [&](vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    });
    sort(b.begin(), b.end(), [&](vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    });
    sort(bb.begin(), bb.end(), [&](vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    });
    bool f1 = 1, f2 = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            f1 = 0;
            break;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (aa[j] != bb[j])
        {
            f2 = 0;
            break;
        }
    }
    cout << (f1 && f2 ? "YES\n" : "NO\n");
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}