#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int q;
    cin >> q;
    stack<pair<int, int>> s;
    int num = 0;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
            num++;
        else if (op == 2)
        {
            int t;
            cin >> t;
            s.push({t, num});
            num = 0;
        }
        else if (op == 3)
        {
            int h;
            cin >> h;
            int tall = 0, ans = 0;
            stack<pair<int, int>> temp;
            while (!s.empty())
            {
                auto [t, n] = s.top();
                s.pop();
                tall += t;
                if (tall >= h)
                    ans += n;
                else
                    temp.push({t, n});
            }
            while (!temp.empty())
            {
                s.push(temp.top());
                temp.pop();
            }
            cout << ans << "\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}