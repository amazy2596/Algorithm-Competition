#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    unordered_map<int, int> position;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        position[a[i]] = i;
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != i)
        {
            ans.push_back({i, position[i]});
            swap(a[i], a[position[i]]);
            swap(position[a[i]], position[a[position[i]]]);
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
    return 0;
}