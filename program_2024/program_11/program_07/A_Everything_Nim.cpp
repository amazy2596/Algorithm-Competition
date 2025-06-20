#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a[0] > 1)
    {
        cout << "Alice\n";
        return;
    }
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i - 1] + 1 != a[i])
        {
            if (i % 2 == 0)
                cout << "Alice\n";
            else
                cout << "Bob\n";
            return;
        }
    }
    cout << (a.size() % 2 == 0 ? "Bob\n" : "Alice\n");
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