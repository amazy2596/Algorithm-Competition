#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n <= 2)
    {
        cout << "-1\n";
        return;
    }
    cout << "1 ";
    for (int i = n; i > 1; i--)
        cout << i << " ";
    // vector<int> a(n + 1);
    // iota(a.begin(), a.end(), 0);
    // do
    // {
    //     vector<int> temp, cur;
    //     cur = a;
    //     cur.erase(cur.begin());
    //     while (cur.size() != 1)
    //     {
    //         for (int i = 0; i < cur.size() - 1; i++)
    //             temp.push_back(abs(cur[i] - cur[i + 1]));
    //         cur = temp;
    //         temp.clear();
    //     }

    //     if (cur.back() == n - 2)
    //     {
    //         for (int i = 1; i <= n; i++)
    //             cout << a[i] << " ";
    //         cout << "\n";
    //     }
    // } while (next_permutation(a.begin() + 1, a.end()));
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