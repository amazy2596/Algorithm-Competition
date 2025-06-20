#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<char> a = {'a', 'e', 'i', 'o', 'u'};
    vector<int> ans(5);
    for (int i = 0; i < n; i++)
        ans[i % 5]++;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < ans[i]; j++)
            cout << a[i];
    }
    cout << "\n";
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