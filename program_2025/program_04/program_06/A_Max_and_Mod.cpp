#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 2 == 0)
        cout << "-1\n";
    else 
    {
        cout << n << " ";
        for (int i = 1; i < n; i++)
            cout << i << " ";
        cout << "\n";
    }

    // vector<int> a(n);
    // iota(a.begin(), a.end(), 1);
    // do 
    // {
    //     bool f = 1;
    //     for (int i = 2; i <= n; i++)
    //     {
    //         int idx = i - 1;
    //         if (max(a[idx - 1], a[idx]) % i != i - 1)
    //             f = 0;
    //     }

    //     if (f)
    //     {
    //         for (int i = 0; i < n; i++)
    //             cout << a[i] << " \n"[i == n - 1];
    //     }
    // } while (next_permutation(a.begin(), a.end()));
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