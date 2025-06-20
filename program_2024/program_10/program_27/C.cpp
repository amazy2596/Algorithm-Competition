#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    swap(v[0], v[v.size() - 1]);
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            b += v[i];
        else
            a += v[i];
    }
    if (a == b)
        cout << "draw\n";
    else
        cout << (b > a ? "yukari\n" : "kou\n");
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