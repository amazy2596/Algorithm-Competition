#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n + 1), b(n + 1), preA(n + 1), preB(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], preA[i] = (preA[i - 1] ^ a[i]);
    for (int i = 1; i <= n; i++)
        cin >> b[i], preB[i] = preB[i - 1] + b[i];

    vector<i64> c(n + 1);
    
}

int main()
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