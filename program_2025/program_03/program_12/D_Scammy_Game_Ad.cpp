#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int l = 1, r = 1, add = 0;
    for (int i = 0; i < n; i++)
    {
        char op1, op2;
        int x1, x2;
        cin >> op1 >> x1 >> op2 >> x2;
        if (op1 == op2)
        {
            if (op1 == '+')
                add += x1 + x2;
            else if (x1 == x2)
                add += (l + r + add) * (x1 - 1);
            else if (x1 > x2)
            {
                l += add;
                add = l * (x1 - 1) + r * (x2 - 1);
            }
            else 
            {
                r += add;
                add = l * (x1 - 1) + r * (x2 - 1);
            }
        }
        else if (op1 == '+')
        {
            r += add;
            add = x1 + r * (x2 - 1);
        }
        else 
        {
            l += add;
            add = l * (x1 - 1) + x2;
        }
    }

    cout << l + r + add << "\n";
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