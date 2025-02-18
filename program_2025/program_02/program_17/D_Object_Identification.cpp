#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> x(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        pos[x[i]] = i;
    }
    vector<int> exist(n + 1);
    for (int i = 1; i <= n; i++)
        exist[x[i]] = 1;

    auto ask = [&](int i, int j)
    {
        cout << "? " << i << " " << j << endl;
        int res;
        cin >> res;
        return res;
    };

    for (int i = 1; i <= n; i++)
    {
        if (exist[i] == 0)
        {
            int res = ask(i, x[1]);
            if (res == 0)
                cout << "! A" << endl;
            else 
                cout << "! B" << endl;
            return;
        }
    }

    int res1 = ask(pos[1], pos[n]);
    int res2 = ask(pos[n], pos[1]);

    if (res1 + res2 < 2 * (n - 1))
        cout << "! A" << endl;
    else 
        cout << "! B" << endl;
};

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