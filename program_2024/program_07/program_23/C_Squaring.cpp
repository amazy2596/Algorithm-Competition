#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<intt> a(n);
    bool f = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i && a[i - 1] > a[i])
            f = 0;
    }
    if (f)
        cout << "0\n";
    else 
    {
        intt ans = 0;
        intt last = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] > a[i] && a[i] == 1)
            {
                ans = -1;
                break;
            }
            long double x = log10l(a[i - 1]);
            long double y = log10l(a[i]);
            last += ceil(log2l(x / y));
            last = max(last, 0ll);
            ans += last;
        }
        cout << ans << "\n";
    }
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