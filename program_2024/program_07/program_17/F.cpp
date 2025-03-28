#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    intt ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], ans ^= a[i];
    intt cur = ans;
    for (int i = 0; i < n; i++)
    {
        for (int x = 1; x <= n / (i + 1); x++)
        {
            ans = max({ans, cur ^ a[i] ^ (a[i] * x), cur ^ a[i] ^ (a[i] + x)});
        }
    }
    cout << ans << "\n";
    return 0;
}