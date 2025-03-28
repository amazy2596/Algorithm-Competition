#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> ans;
        ans.push_back({1, 1});
        if (n > 2)
            ans.push_back({n, n});
        ans.push_back({2, 1});
        for (int j = 3; j < n; j++)
            ans.push_back({1, j});
        // set<int> s;
        // for (int i = 0; i < ans.size(); i++)
            // for (int j = 0; j < ans.size(); j++)
                // s.insert(abs(ans[i].first - ans[j].first) + abs(ans[i].second - ans[j].second));
        // if (2 * n - 1 == s.size())
            // cout << "YES\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].first << " " << ans[i].second << "\n";
        cout << "\n";
    }
    return 0;
}