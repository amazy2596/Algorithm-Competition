#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int p, v;
        cin >> p >> v;
        if (v == 1)
            a.push_back(p);
        else 
            b.push_back(p);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int mx = 0, j = 0;
    for (int i = 0; i < a.size(); i++)
    {
        while (j < b.size() && a[i] >= b[j])
            j++;
        mx += b.size() - j;
    }

    if (mx < k)
    {
        cout << "No\n";
        return;
    }

    auto get = [&](int d)
    {
        int sum = 0;
        int l = 0, r = 0;
        for (int i = 0; i < a.size(); i++)
        {
            while (l < b.size() && b[l] <= a[i])
                l++;
            while (r < b.size() && b[r] <= a[i] + d)
                r++;
            
            sum += (r - l);
        }

        return sum;
    };

    int l = 1, r = 1e9;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (get(mid) >= k)
            r = mid;
        else 
            l = mid + 1;
    }

    cout << "Yes\n";
    cout << fixed << setprecision(6) << (long double)(l / 2.0) << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}