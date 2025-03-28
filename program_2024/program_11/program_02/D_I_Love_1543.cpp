#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<int> target(4);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = (s[i][j] - '0');
    target[0] = 1, target[1] = 5, target[2] = 4, target[3] = 3;
    auto check = [&](deque<int> d)
    {
        for (int i = 0; i < 4; i++)
        {
            if (target[i] != d.front())
                return false;
            d.push_back(d.front());
            d.pop_front();
        }
        return true;
    };
    set<pair<int, int>> ss;
    for (int k = 0; k < min(n, m) / 2; k++)
    {
        deque<int> d;
        int i = k, j = k;
        while (j < m - k)
        {
            d.push_back(a[i][j]);
            if (d.size() == 4)
            {
                if (check(d))
                    ss.insert({i, j});
                d.pop_front();
            }
            j++;
        }
        j--, i++;
        while (i < n - k)
        {
            d.push_back(a[i][j]);
            if (d.size() == 4)
            {
                if (check(d))
                    ss.insert({i, j});
                d.pop_front();
            }
            i++;
        }
        i--, j--;
        while (j >= k)
        {
            d.push_back(a[i][j]);
            if (d.size() == 4)
            {
                if (check(d))
                    ss.insert({i, j});
                d.pop_front();
            }
            j--;
        }
        j++, i--;
        while (i >= k)
        {
            d.push_back(a[i][j]);
            if (d.size() == 4)
            {
                if (check(d))
                    ss.insert({i, j});
                d.pop_front();
            }
            i--;
        }
        i++, j++;
        int count = 3;
        while (j < m - k)
        {
            count--;
            d.push_back(a[i][j]);
            if (d.size() == 4)
            {
                if (check(d))
                    ss.insert({i, j});
                d.pop_front();
            }
            j++;
            if (count == 0)
                break;
        }
        j--, i++;
        if (count == 0)
            continue;
        while (i < n - k)
        {
            count--;
            d.push_back(a[i][j]);
            if (d.size() == 4)
            {
                if (check(d))
                    ss.insert({i, j});
                d.pop_front();
            }
            i++;
            if (count == 0)
                break;
        }
        i--, j--;
        if (count == 0)
            continue;
        while (j >= k)
        {
            count--;
            d.push_back(a[i][j]);
            if (d.size() == 4)
            {
                if (check(d))
                    ss.insert({i, j});
                d.pop_front();
            }
            j--;
            if (count == 0)
                break;
        }
        j++, i--;
        if (count == 0)
            continue;
        while (i >= k)
        {
            count--;
            d.push_back(a[i][j]);
            if (d.size() == 4)
            {
                if (check(d))
                    ss.insert({i, j});
                d.pop_front();
            }
            i--;
            if (count == 0)
                break;
        }
        i++, j++;
        if (count == 0)
            continue;
    }
    cout << ss.size() << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}