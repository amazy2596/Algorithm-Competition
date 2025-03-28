#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
        // cin >> a[i];
    // sort(a.begin(), a.end());
    intt ans = 0;
    bool f = 1;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        // auto it = lower_bound(a.begin(), a.end(), b[i]);
        auto it = mp.lower_bound(b[i]);
        if (it->first < b[i])
        {
            f = 0;
            break;
        }
        ans += it->first;
        it->second--;
        if (it.operator->()->second == 0)
            mp.erase(it);
    }
    cout << (f ? ans : -1) << "\n";
    return 0;
}