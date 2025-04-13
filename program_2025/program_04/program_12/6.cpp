#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    auto get = [&](int n)
    {   
        return n * (n + 1) * (2 * n + 1) / 6;
    };

    auto f = [&](int l, int r)
    {
        return get(r) - get(l - 1);
    };

    int l = n * (n * 2 + 1);
    int mid = l + n;
    int r = mid + n;
    if (f(l, mid) == f(mid + 1, r))
    {
        for (int i = l; i <= mid; i++)
        {
            if (i == mid)
                cout << i << "^2 =\n";
            else 
                cout << i << "^2 + ";
        }
        for (int i = mid + 1; i <= r; i++)
        {
            if (i == r)
                cout << i << "^2";
            else 
                cout << i << "^2 + ";
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