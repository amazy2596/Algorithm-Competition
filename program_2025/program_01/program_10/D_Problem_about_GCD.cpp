#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void solve()
{
    int l, r, g;
    cin >> l >> r >> g;
    int ll = l + (l % g == 0 ? 0 : g - (l % g));
    int rr = r - r % g;
    
    for (int i = 0; i <= (rr - ll) / g; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (gcd(ll + j * g, rr - (i - j) * g) == g)
            {
                cout << ll + j * g << " " << rr - (i - j) * g << "\n";
                return;
            }
        }
    }
    cout << -1 << " " << -1 << "\n";
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