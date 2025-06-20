#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> mp;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i] % k].push_back(a[i] / k);
    }
    int ans = 0, cnt = 0;
    for (auto [key, v] : mp)
    {
        if (v.size() % 2 == 1)
        {
            cnt++;
            if (cnt >= 2)
                break;
        }
        sort(v.begin(), v.end());
        if (v.size() % 2 == 0)
        {
            for (int i = 1; i < v.size(); i += 2)
                ans += v[i] - v[i - 1];
        }
        else
        {
            vector<int> evens(v.size()), odds(v.size());
            for (int i = 0; i < v.size(); i++)
            {
                evens[i] = (i == 0 ? v[0] : evens[i - 1] + (i % 2 == 0 ? v[i] : 0));
                odds[i] = (i == 0 ? 0 : odds[i - 1] + (i % 2 == 1 ? v[i] : 0));
            }
            int temp = 1e18;
            for (int i = 0; i < v.size(); i++)
            {
                int x = (i == 0 ? 0 : odds[i - 1]) + (evens[v.size() - 1] - evens[i]);
                int y = (i == 0 ? 0 : evens[i - 1]) + (odds[v.size() - 1] - odds[i]);
                temp = min(temp, x - y);
            }
            ans += temp;
        }
    }
    cout << (cnt < 2 ? ans : -1) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}