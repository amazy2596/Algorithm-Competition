#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b[x]++;
    }
    int ans = 0;
    int cnt_1 = 0;
    for (auto [key, val] : a)
    {
        if (b.find(key) != b.end())
        {
            int temp = min(val, b[key]);
            cnt_1 += (val == 1 && b[key] == 1);
            ans += temp;
            a[key] -= temp;
            b[key] -= temp;
        }
    }
    int cnt_a = 0, cnt_b = 0;
    for (auto [key, val] : a)
        cnt_a += max(0ll, val - 1);
    for (auto [key, val] : b)
        cnt_b += max(0ll, val - 1);
    int diff = max(cnt_a, cnt_b) - min(cnt_a, cnt_b);
    ans += max(cnt_a, cnt_b);
    ans -= min(diff, cnt_1);
    cout << ans << "\n";
}

signed main()
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