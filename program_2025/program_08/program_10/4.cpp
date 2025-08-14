#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        for (int i = 2; i <= n; i += 2)
        {
            cout << i << " " << i - 1 << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}