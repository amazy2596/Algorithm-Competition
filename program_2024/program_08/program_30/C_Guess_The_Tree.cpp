#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a, in_tree(n + 1, 0);
    for (int i = 2; i <= n; i++)
        a.push_back(i);
    in_tree[1] = 1;
    auto query = [&](int u, int v)
    {
        cout << "? " << u << " " << v << endl;
        fflush(stdout);
        int res;
        cin >> res;
        return res;
    };
    vector<pair<int, int>> ans;
    while (!a.empty())
    {
        int n = a.back();
        a.pop_back();
        int l = 1, r = n;
        if (in_tree[r])
            continue;
        while (true)
        {
            int x = query(l, r);
            if (l == x)
            {
                in_tree[r] = 1;
                ans.push_back({l, r});
                break;
            }
            if (in_tree[x])
                l = x;
            else 
                r = x;
        }
        a.push_back(n);
    }
    cout << "! ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << ' ' << ans[i].second << ' ';
    cout << endl;
}

int main()
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