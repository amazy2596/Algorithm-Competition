#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1), apre(n + 1), bpre(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    for (int i = 1; i <= n; i++)
        apre[i] = apre[i - 1] + (a[n - i + 1] - a[i]);
    for (int i = 1; i <= m; i++)
        bpre[i] = bpre[i - 1] + (b[m - i + 1] - b[i]);
    
    vector<int> ans{0};
    for (int x = 1; 2 * x - m <= n - x; x++)
    {
        int l = max(0ll, 2 * x - m), r = min(x, n - x);
        if (l > r)
            break;
        
        auto f = [&](int k)
        {
            return apre[k] + bpre[x - k];
        };

        while (r - l > 3)
        {
            int ml = (l * 2 + r) / 3, mr = (l + r * 2) / 3;
            if (f(ml) > f(mr))
                r = mr;
            else 
                l = ml;
        }

        int mans = 0;
        for (int i = l; i <= r; i++)
            mans = max(mans, f(i));
        ans.push_back(mans);
    }
    cout << ans.size() - 1 << "\n";
    for (int i = 1; i < ans.size(); i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}