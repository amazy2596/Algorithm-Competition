#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        int l, a;
        cin >> l >> a;
        cnt[l] += a;
    }
    vector<int> v;
    for (auto [key, val] : cnt)
    {
        if (val >= 2)
            v.push_back(key);
    }

    auto calc = [&](int a, int b, int c)
    {
        long double p = (a + b + c) * 1.0 / 2;
        long double s = sqrt(p * (p - a) * (p - b) * (p - c));
        return s;
    };

    long double ans = -1;
    sort(v.begin(), v.end(), greater<int>());
    for (auto &[key, val] : cnt) 
    {
        val--;
        for (auto len : v)
        {
            if (cnt[len] >= 2 && 2 * len > key)
            {
                ans = max(ans, calc(len, len, key));
                break;
            }
            if (2 * len <= key)
                break;
        }
        val++;
    }
    cout << fixed << setprecision(10) << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}