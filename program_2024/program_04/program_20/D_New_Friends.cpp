#include <bits/stdc++.h>
using intt = long long;
using namespace std;

struct DSU 
{
    vector<int> fa, size;

    DSU (int n)
    {
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        size.assign(n + 1, 1);
    }

    int find(int x)
    {
        if (x == fa[x])
            return x;
        return fa[x] = find(fa[x]);
    }

    void add(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x != y)
        {
            size[x] += size[y];
            size[y] = 0;
            fa[y] = x;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        dsu.add(x, y);
    }
    intt ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dsu.find(i) == i)
            ans += (intt) dsu.size[i] * (dsu.size[i] - 1) / 2;
    }
    ans -= m;
    cout << ans << endl;
    return 0;
}