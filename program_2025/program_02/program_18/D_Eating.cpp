#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = pre[i - 1] ^ a[i];
    
    vector last(n + 1, vector<int>(32));
    for (int i = 1; i <= n; i++)
    {
        last[i] = last[i - 1];
        last[i][__lg(a[i])] = i;

        for (int j = 30; j >= 0; j--)
            last[i][j] = max(last[i][j], last[i][j + 1]);
    }
    
    while (q--)
    {
        int x;
        cin >> x;

        int idx = n;
        while (idx > 0 && x > 0)
        {
            int msb = __lg(x);

            int nxt = last[idx][msb];
            x ^= pre[idx] ^ pre[nxt];
            idx = nxt;

            if (nxt == 0 || a[nxt] > x)
                break;
            
            x ^= a[nxt];
            idx--;
        }

        cout << n - idx << " ";
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