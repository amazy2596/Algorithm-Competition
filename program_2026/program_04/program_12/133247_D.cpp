// Problem: 跳
// URL: https://ac.nowcoder.com/acm/contest/133247/D
// Author: amazy
// Date: 2026-04-12 17:02:46

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct node
{
    i64 key, pos;
};

struct ST
{
    node op(node a, node b) 
    { 
        if (a.key > b.key) return a;
        return b;
    }
    vector<vector<node>> a;
    int n;

    ST(vector<int> &input)
    {
        n = input.size();
        int max_log = __lg(n);
        a.assign(n, vector<node>(max_log + 1));
        for (int i = 0; i < n; i++) a[i][0] = node(input[i], (i64)i);

        for (int j = 1; j <= max_log; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {
                a[i][j] = op(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    node query(int l, int r)
    {
        assert(l <= r && l >= 0 && r < n);
        int j = __lg(r - l + 1);
        return op(a[l][j], a[r - (1 << j) + 1][j]);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = min(a[i] + i, n);
    ST st(b);
    vector<vector<int>> up(n + 1, vector<int>(32));
    for (int i = n; i >= 1; i--)
    {
        up[i][0] = st.query(i, b[i]).pos;
        for (int j = 1; j < 32; j++)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    while (q--)
    {
        i64 L, R;
        cin >> L >> R;

        if (L >= R) 
        {
            cout << 0 << '\n';
            continue;
        }

        if (b[L] >= R) 
        {
            cout << 1 << '\n';
            continue;
        }

        int cur = L;
        int ans = 0;

        for (int k = 31; k >= 0; k--) 
        {
            int nx = up[cur][k];
            if (b[nx] < R) 
            {
                cur = nx;
                ans += (1 << k);
            }
        }

        cout << ans + 2 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}