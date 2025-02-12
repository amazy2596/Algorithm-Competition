#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n <= 3)
        cout << 0 << "\n";
    else if (n <= 5)
    {
        cout << 1 << "\n";
        cout << "2 3 4\n";
    }
    else if (n % 6 >= 3)
    {
        cout << n / 3 << "\n";
        cout << "1 3 9\n2 4 5\n6 7 8\n";
        for (int i = 10; i + 5 <= n; i += 6)
        {
            cout << i << " " << i + 3 << " " << i + 4 << "\n" <<
                    i + 1 << " " << i + 2 << " " << i + 5 << "\n";
        }
    }
    else
    {
        cout << n / 3 << "\n";
        for (int i = 1; i + 5 <= n; i += 6)
        {
            cout << i << " " << i + 1 << " " << i + 3 << "\n" << 
                    i + 2 << " " << i + 4 << " " << i + 5 << "\n";
        }
    }
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