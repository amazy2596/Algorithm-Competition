#include <bits/stdc++.h>
#define int long long
using namespace std;

int query(int l, int r)
{
    int res;
    cout << "? " << l << " " << r << endl;
    cout << endl;
    cin >> res;
    return res;
}

void solve()
{
    int n;
    cin >> n;
    string s = " ";
    for (int i = 0; i < n; i++)
        s.push_back('0');
    int last = query(1, n);
    if (last)
    {
        int idx = -1;
        for (int i = n - 1; i >= 2; i--)
        {
            int cur = query(1, i);
            if (cur != last)
                s[i + 1] = '1';
            last = cur;
            if (last == 0)
            {
                idx = i + 1;
                break;
            }
        }
        if (last)
        {
            s[1] = '0';
            s[2] = '1';
        }
        else
        {
            last = 1;
            for (int i = idx - 2; i >= 1; i--)
            {
                int cur = query(i, idx);
                if (cur == last)
                    s[i] = '1';
                last = cur;
            }
        }
        cout << "!" << s << "\n";
    }
    else
        cout << "! IMPOSSIBLE\n";
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