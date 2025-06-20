#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    char king;
    cin >> king;
    vector<string> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), [&](string a, string b)
    {
        if (a[1] == king && b[1] == king)
            return a[0] <= b[0];
        else if (a[1] == king)
            return false;
        else if (b[1] == king)
            return true;

        if (a[1] == b[1])
            return a[0] <= b[0];
        return a[1] <= b[1];
    });
    stack<string> s;
    while (a.size() && a.back()[1] == king)
    {
        s.push(a.back());
        a.pop_back();
    }
    vector<pair<string, string>> ans;
    int i = 0;
    while (i + 1 < a.size())
    {
        if (a[i][1] != a[i + 1][1])
        {
            if (!s.empty())
            {
                ans.push_back({a[i], s.top()});
                s.pop();
                i++;
            }
            else
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
        else
        {
            ans.push_back({a[i], a[i + 1]});
            i += 2;
        }
    }
    if (i == a.size() - 1 && !s.empty())
    {
        ans.push_back({a[i], s.top()});
        s.pop();
    }
    if (s.size() % 2 == 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    while (!s.empty())
    {
        auto x = s.top();
        s.pop();
        auto y = s.top();
        s.pop();
        ans.push_back({x, y});
    }
    for (auto p : ans)
        cout << p.first << " " << p.second << "\n";
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