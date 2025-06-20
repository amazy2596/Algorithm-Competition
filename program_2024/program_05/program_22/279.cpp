#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    const intt mod = 2147483648;
    int n;
    cin >> n;
    vector<intt> f(n + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            f[j] = (f[j] + f[j - i]) % mod;
    cout << (f[n] > 0 ? f[n] - 1 : 2147483647ll);
    return 0;
}