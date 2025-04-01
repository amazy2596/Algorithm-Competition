#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct node
{
    int dist, x, y, tx, ty;

    bool operator<(const node other) const
    {
        if (dist == other.dist && tx == other.tx)
            return ty > other.ty;
        else if (dist == other.dist)
            return tx > other.tx;
        return dist > other.dist;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    priority_queue<node> q1;
    for (int x = 0; x <= 1000 && q1.size() < 4 * n; x++)
    {
        for (int y = 0; y <= 1000 && q1.size() < 4 * n; y++)
        {
            int tx = 3 * x + 1, ty = 3 * y + 1;
            q1.push({tx + ty, x, y, tx, ty});
            q1.push({tx + ty + 1, x, y, tx + 1, ty});
            q1.push({tx + ty + 1, x, y, tx, ty + 1});
            q1.push({tx + ty + 2, x, y, tx + 1, ty + 1});
        }
    }

    priority_queue<node> q2 = q1;
    map<pair<int, int>, int> mp1, mp2;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            while (!q1.empty())
            {
                auto [_, x, y, tx, ty] = q1.top();
                q1.pop();
                if (!mp2.contains({tx, ty}))
                {
                    mp1[{x, y}]++;
                    mp2[{tx, ty}]++;
                    cout << tx << " " << ty << "\n";
                    break;
                }
            }
        }
        else 
        {
            while (!q2.empty())
            {
                auto [_, x, y, tx, ty] = q2.top();
                q2.pop();
                if (!mp1.contains({x, y}) && !mp2.contains({tx, ty}))
                {
                    mp1[{x, y}]++;
                    mp2[{tx, ty}]++;
                    cout << tx << " " << ty << "\n";
                    break;
                }
            }
        }
    }
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