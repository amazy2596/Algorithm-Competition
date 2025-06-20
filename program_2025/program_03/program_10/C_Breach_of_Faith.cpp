#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> b(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
        cin >> b[i];

    sort(b.begin() + 1, b.end());
    int a1 = b.back();
    int sum = 0;
    vector<int> odd, even;
    for (int i = 1; i <= n - 1; i++)
    {
        sum += b[i];
        odd.emplace_back(b[i]);
    }
    for (int i = n; i < 2 * n; i++)
    {
        sum -= b[i];
        even.emplace_back(b[i]);
    }

    odd.emplace_back(a1 - sum);
    cout << a1 << " ";
    int j = 0, k = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i % 2 == 1)
            cout << odd[j++] << " ";
        else 
            cout << even[k++] << " ";
    }

    cout << "\n";
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