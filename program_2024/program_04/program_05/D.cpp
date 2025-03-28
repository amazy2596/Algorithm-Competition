#include <bits/stdc++.h>
using intt = long long;
using namespace std;

struct node {
    int st, ed;
};

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<node> line(m);
    vector<bool> check(m);
    for (int i = 0; i < m; i++)
        cin >> line[i].st >> line[i].ed;
    int ans = 0;
    for (int temp = 0; temp < (1 << m); temp++)
    {
        vector<int> g(n + 1, 0), need;
        for (int i = 0; i < 10; i++)
        {
            if (((temp >> i) & 1) == 1 && i < m)
            {
                need.push_back(i);
                for (int j = line[i].st; j <= line[i].ed; j++)
                    g[j]++;
            }
        }
        // for (auto idx : need)
        // {
            // for (int i = line[idx].st; i < line[idx].ed; i++)
                // g[i]++;
        // }
        bool flag = 1;
        for (int i = 1; i <= n; i++)
            if (g[i] < 2)
            {
                flag = 0;
                break;
            }
        if (flag)
            ans++;
    }
    cout << ans << "\n";
    return 0;
}