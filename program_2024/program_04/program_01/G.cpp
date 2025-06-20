#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, a, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        ans += a != 0;
    }
    cout << ans;
    return 0;
}