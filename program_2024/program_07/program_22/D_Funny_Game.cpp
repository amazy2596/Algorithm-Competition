#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), position(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<pair<int, int>> ans;
    iota(position.begin(), position.end(), 1);
    for (int i = n - 1; i >= 1; i--)
    {
        vector<int> same_mod(i, -1);
        for (auto p : position)
        {
            if (same_mod[a[p] % i] != -1)
            {
                ans.push_back({p, same_mod[a[p] % i]});
                position.erase(find(position.begin(), position.end(), p));
                break;
            }
            same_mod[a[p] % i] = p;
        }
    }
    cout << "YES\n";
    reverse(ans.begin(), ans.end());
    for (auto [u, v] : ans)
        cout << u << " " << v << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}