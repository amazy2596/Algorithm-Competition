#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node
{
    int x1, y1, x2, y2;

    const bool operator<(node o) const
    {
        pair<int, int> p1 = {x1, y1}, p2 = {x2, y2}; 
        pair<int, int> p3 = {o.x1, o.y1}, p4 = {o.x2, o.y2};

        auto p5 = make_pair(p1, p2), p6 = make_pair(p3, p4);

        return p5 < p6;
    }
};

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    
    map<node, int> mp;
    vector<int> q;
    int scoreA = 0, scoreB = 0;

    auto check = [&](int x1, int y1, int x2, int y2)
    {
        int res = 0;
        int distX = abs(x1 - x2), distY = abs(y1 - y2);

        if (distX == 1 && distY == 1)
            return -1ll;

        if (distX == 1)
        {
            int tmp = (y1 >= 2);
            if (y1 >= 2 && mp.find({x1, y1 - 1, x2, y2 - 1}) == mp.end())
                tmp = 0;
            if (y1 >= 2 && mp.find({x1, y1, x1, y1 - 1}) == mp.end())
                tmp = 0;
            if (y2 >= 2 && mp.find({x2, y2, x2, y2 - 1}) == mp.end())
                tmp = 0;
            res += tmp;

            tmp = (y1 <= m - 1);
            if (y1 <= m - 1 && mp.find({x1, y1 + 1, x2, y2 + 1}) == mp.end())
                tmp = 0;
            if (y1 <= m - 1 && mp.find({x1, y1, x1, y1 + 1}) == mp.end())
                tmp = 0;
            if (y2 <= m - 1 && mp.find({x2, y2, x2, y2 + 1}) == mp.end())
                tmp = 0;
            res += tmp;
        }
        else if (distY == 1) 
        {
            int tmp = (x1 >= 2);
            if (x1 >= 2 && mp.find({x1 - 1, y1, x2 - 1, y2}) == mp.end())
                tmp = 0;
            if (x1 >= 2 && mp.find({x1, y1, x1 - 1, y1}) == mp.end())
                tmp = 0;
            if (x2 >= 2 && mp.find({x2, y2, x2 - 1, y2}) == mp.end())
                tmp = 0;
            res += tmp;

            tmp = (x1 <= n - 1);
            if (x1 <= n - 1 && mp.find({x1 + 1, y1, x2 + 1, y2}) == mp.end())
                tmp = 0;
            if (x1 <= n - 1 && mp.find({x1, y1, x1 + 1, y1}) == mp.end())
                tmp = 0;
            if (x2 <= n - 1 && mp.find({x2, y2, x2 + 1, y2}) == mp.end())
                tmp = 0;
            res += tmp;
        }

        return res;
    };

    int last = 0;
    for (int i = 1; i <= s; i++)
    {
        int id, x1, y1, x2, y2;
        cin >> id >> x1 >> y1 >> x2 >> y2;

        if (last != -1 && last != id)
        {
            q.push_back(i);
            continue;
        }

        if (mp.find({x1, y1, x2, y2}) != mp.end())
        {
            q.push_back(i);
            continue;
        }

        int res = check(x1, y1, x2, y2);
        if (res == -1)
        {
            q.push_back(i);
            continue;
        }

        mp[{x1, y1, x2, y2}]++;
        mp[{x2, y2, x1, y1}]++;
        
        if (id == 0)
        {
            scoreA += res;
            if (res)
                last = id;
            else 
                last = -1;
        }
        else if (id == 1)
        {
            scoreB += res;
            if (res)
                last = id;
            else 
                last = -1;
        }
    }

    if (q.empty())
        cout << "-1\n";
    else 
    {
        for (int i = 0; i < q.size(); i++)
            cout << q[i] << " ";
        cout << "\n";
    }

    if (scoreA > scoreB)
        cout << "0 " << scoreA;
    else 
        cout << "1 " << scoreB;
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}