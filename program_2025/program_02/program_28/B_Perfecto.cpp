#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "-1\n";
        return;
    }
    int x = (n + 1) * n / 2;
    long double y = sqrtl(x);
    if (ceill(y) == y)
    {
        cout << "-1\n";
        return;
    }

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = sum + i;
        long double cnt = sqrtl(temp);
        if (ceill(cnt) == cnt)
        {
            sum += i + i + 1;
            cout << i + 1 << " " << i << " ";
            i++;
        }
        else 
        {
            sum += i;
            cout << i << " ";
        }
    }
    cout << "\n";
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