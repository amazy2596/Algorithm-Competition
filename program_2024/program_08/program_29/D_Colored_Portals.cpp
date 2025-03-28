#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<string> vars = {"BG", "BR", "BY", "GR", "GY", "RY"};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        a[i] = find(vars.begin(), vars.end(), s) - vars.begin();
    }

    vector<vector<int>> l(n + 1), r(n + 1);
    vector<int> last(6, INT32_MAX);
    for (int i = 1; i <= n; i++)
    {
        last[a[i]] = i;
        l[i] = last;
    }
    last.assign(6, INT32_MAX);
    for (int i = n; i >= 1; i--)
    {
        last[a[i]] = i;
        r[i] = last;
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int ans = INT32_MAX;
        for (int j = 0; j < 6; j++)
        {
            if (a[x] + j != 5 && a[y] + j != 5)
            {
                ans = min({ans, abs(x - l[x][j]) + abs(y - l[x][j]), abs(x - l[y][j]) + abs(y - l[y][j])});
                ans = min({ans, abs(x - r[x][j]) + abs(y - r[x][j]), abs(x - r[y][j]) + abs(y - r[y][j])});
            }
        }
        cout << (ans == INT32_MAX ? -1 : ans) << "\n";
    }
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