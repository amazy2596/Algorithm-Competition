#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int evens = 0, mx = 0;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2)
            b.push_back(x);
        else 
            a.push_back(x);
    }
    if (a.empty() || b.empty())
    {
        cout << 0 << "\n";
        return;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int mx_a = a[a.size() - 1], mx_b = b[b.size() - 1];
    bool f = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < mx_b)
            mx_b = max(mx_b, mx_b + a[i]);
        if (mx_b > mx_a)
        {
            f = 1;
            break;
        }
    }
    cout << (f ? a.size() : a.size() + 1) << "\n";
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