#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 1e5 + 5;
vector<int> fa(N), ans(N);

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i <= n + 1; i++) {
        fa[i] = i;
        ans[i] = 0;
    }
    int tot = 1;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            l = find(l);
            while (l <= r)
            {
                ans[l] = tot++;
                fa[l] = l + 1;
                l = find(l);
            }
        }
        else if (op == 2)
        {
            int x;
            cin >> x;
            cout << ans[x] << "\n";
        }
    }
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