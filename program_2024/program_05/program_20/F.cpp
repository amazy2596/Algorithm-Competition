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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(ans.begin(), ans.end(), a[i]);
        if (it == ans.end())
            ans.push_back(a[i]);
        else 
            *it = a[i];
    }
    cout << ans.size() << "\n";
    return 0;
}