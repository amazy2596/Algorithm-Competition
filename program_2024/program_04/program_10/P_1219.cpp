#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int n, ans = 0;
struct node {
    int i, j;
};
vector<node> a;

void dfs(int i)
{
    if (a.size() == n)
    {
        for (int k = 0; k < a.size() && ans < 3; k++)
            cout << a[k].j << " \n"[k == a.size() - 1];
        ans++;
        return;
    }
    for (int j = 1; j <= n; j++)
    {
        bool ok = 0;
        for (auto [x, y] : a)
        {
            if (j == y || abs(i - x) == abs(j - y))
            {
                if (j == n)
                    return;
                ok = 1;
                break;
            }
        }
        if (ok)
            continue;
        a.push_back({i, j});
        dfs(i + 1);
        a.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n;
    dfs(1);
    cout << ans << "\n";
    return 0;
}