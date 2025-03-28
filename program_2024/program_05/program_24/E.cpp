#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), [&](pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    });
    for (int s = 2000; s >= 0; s--)
    {
        int temp = 0xffffff;
        for (auto [v, w] : a)
        {
            if ((s & w) == s)
                temp &= v;
        }
        if (temp <= k)
        {
            cout << s;
            return 0;
        }
    }
    cout << 0;
    return 0;
}