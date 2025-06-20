#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1, 1);
    while (q--)
    {
        int idx;
        cin >> idx;
        a[idx] ^= 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i];
    cout << ans;
    return 0;
}