#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    auto f = [&](int x)
    {
        return x * (x + 1) * (2 * x + 1) / 6;
    };

    auto get = [&](int l, int r, int k)
    {
        return f(r) - f(l - 1) + (k - l + 1) * (l + r) * (r - l + 1) / 2;
    };

    vector<int> a(n + 1);
    auto dfs = [&](auto dfs, int idx) -> bool
    {
        if (idx == n + 1)
            return k == 0;

        for (int i = a[idx - 1] + 1; ; i++)
        {
            int sum = i * idx;
            if (k < sum)
                break;
            if (k - sum < get(idx + 1, n, i))
                break;
            k -= sum;
            a[idx] = i;
            if (dfs(dfs, idx + 1))
                return true;
            k += sum;
        }

        return false;
    };

    if (dfs(dfs, 1))
    {
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
    }
    else 
        cout << "-1\n";
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