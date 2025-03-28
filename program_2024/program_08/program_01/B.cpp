#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k > n / 2)
        k = n - k;
    if (n / 2 == k && n % 2 == 0)
        cout << n << "\n";
    else 
        cout << n * k + 1 << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    solve();
    return 0;
}