#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int q;
    cin >> q;
    deque<pair<int, int>> a;
    int sum = 0;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int len;
            cin >> len;
            if (a.empty())
                a.push_back({0, len});
            else 
                a.push_back({a.back().first + a.back().second, len});
        }
        else if (op == 2)
        {
            sum += a.front().second;
            a.pop_front();
        }
        else if (op == 3)
        {
            int k;
            cin >> k;
            cout << a[k - 1].first - sum << "\n";
        }
    }
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