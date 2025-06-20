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
    vector<int> a(n), b(m);
    vector<pair<int, bool>> c;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        c.push_back({a[i], 1});
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        c.push_back({b[i], 0});
    }
    sort(c.begin(), c.end());
    bool f = 0;
    for (int i = 1; i < n + m; i++)
    {
        if (c[i - 1].second && c[i].second)
        {
            f = 1;
            break;
        }
    }
    cout << (f ? "Yes\n" : "No\n");
    return 0;
}