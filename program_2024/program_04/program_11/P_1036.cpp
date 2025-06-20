#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int n, k, a[25], ans = 0, temp = 0, cnt = 0;
vector<bool> vis(25, 0);
vector<int> cur;

bool isPrime(int x)
{
    if (x < 2)
        return 0;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return 0;
    return 1;
}

void dfs(int x)
{
    if (cnt == k)
    {
        if (isPrime(temp))
        {
            // for (int i = 0; i < cur.size(); i++)
                // cout << a[i] << " \n"[i == cur.size() - 1];
            ans++;
        }
        return;
    }
    for (int i = x; i < n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        temp += a[i];
        cur.push_back(a[i]);
        cnt++;
        dfs(i + 1);
        temp -= a[i];
        vis[i] = 0;
        cur.pop_back();
        cnt--;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dfs(0);
    cout << ans;
    return 0;
}