#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<int> cnt(2e6 + 5);

void init()
{
    int sum = 0;
    for (int i = 1; i < 2e6 + 5; i++)
    {
        sum += i;
        cnt[i] = cnt[i - 1] + sum;
    }
}

void solve()
{
    int m;
    cin >> m;

    int l = 0, r = 1817120;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (cnt[mid] > m)
            r = mid - 1;
        else 
            l = mid;
    }

    cout << l + 1 << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    init();
    while (T--)
        solve();
    return 0;
}