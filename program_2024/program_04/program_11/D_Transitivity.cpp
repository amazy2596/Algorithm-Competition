#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt n, m;
    cin >> n >> m;
    set<pair<int, int>> s;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        s.insert({u, v});
    }
    cout << n * (n - 1) / 2 - s.size();
    return 0;
}