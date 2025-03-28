#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt n, q;
    cin >> n >> q;
    vector<intt> a(n);
    intt sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum1 += a[i], sum2 += a[i] * a[i];
    while (q--)
    {
        intt x;
        cin >> x;
        intt ans = sum2;
        ans += n * x * x;
        ans -= 2ll * x * sum1;
        cout << ans << "\n";
    }
    return 0;
}