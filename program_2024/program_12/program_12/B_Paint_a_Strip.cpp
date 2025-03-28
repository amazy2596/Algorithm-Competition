#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e5 + 5;
int ans[N];

void init()
{
    ans[1] = 1, ans[2] = 2, ans[3] = 2, ans[4] = 2;
    int count = 3;
    int last = 4;
    for (int i = 5; i < N; i++)
    {
        if (i > last * 2 + 2)
            last = last * 2 + 2, count++;
        ans[i] = count;
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << "\n";
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