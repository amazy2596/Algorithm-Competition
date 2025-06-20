#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans1 = 0, ans2 = 0;
    map<int, int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (a.find(x) == a.end())
            a[x]++;
        else
            ans1++;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (b.find(x) == b.end())
            b[x]++;
        else
            ans2++;
    }
    map<int, int> cnt;
    for (auto m : a)
        cnt[m.first]++;
    for (auto m : b)
        cnt[m.first]++;
    int ans = 0;
    for (auto [key, val] : cnt)
    {
        if (val == 2)
        {
            if (ans1 > ans2)
                ans2++;
            else if (ans1 < ans2)
                ans1++;
            else
                ans++;
        }
    }
    ans = (ans + 1) / 2;
    cout << (ans == 0 ? max(ans1, ans2) : ans1 + ans) << "\n";
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