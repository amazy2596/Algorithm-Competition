#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int n, k, a[10], ans = 0;
bool vis[10];
vector<int> ar;

bool check()
{
    bool f = 1;
    for (int i = 1; i < ar.size(); i++)
    {
        if (abs(ar[i] - ar[i - 1]) < k)
        {
            f = 0;
            break;
        }
    }
    return f;
}

void calc()
{
    if (ar.size() == n)
    {
        if (check())
            ans++;
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;
        ar.push_back(a[i]);
        calc();
        vis[i] = 0;
        ar.pop_back();
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
    calc();
    cout << ans << "\n";
    return 0;
}