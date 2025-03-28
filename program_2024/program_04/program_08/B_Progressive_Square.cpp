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
        int n, c, d;
        cin >> n >> c >> d;
        vector<vector<int>> ans(n, vector<int>(n));
        vector<int> a(n * n);
        unordered_map<int, int> count;
        bool ok = 1;
        for (int i = 0; i < n * n; i++)
        {
            cin >> a[i];
            count[a[i]]++;
        }
        sort(a.begin(), a.end());
        ans[0][0] = a[0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i + 1 < n)
                    ans[i + 1][j] = ans[i][j] + c;
                if (j + 1 < n)
                    ans[i][j + 1] = ans[i][j] + d;
                if (count.find(ans[i][j]) == count.end() || count[ans[i][j]]-- == 0)
                {
                    ok = 0;
                    break;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}