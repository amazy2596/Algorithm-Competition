#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        int a, b, n, m;
        cin >> a >> b >> n >> m;
        vector<pair<int, int>> ver(n + 1), hor(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> ver[i].first >> ver[i].second;
            hor[i].first = ver[i].first;
            hor[i].second = ver[i].second;
        }
        sort(ver.begin() + 1, ver.end(), [&](pair<int, int> q, pair<int, int> p)
        {
            return q.first < p.first;
        });
        sort(hor.begin() + 1, hor.end(), [&](pair<int, int> q, pair<int, int> p)
        {
            return q.second < p.second;
        });
        set<pair<int, int>> deleted;
        int alice = 0, bob = 0;
        int u = 1, d = a, l = 1, r = b;
        int vl = 1, vr = n, hl = 1, hr = n;
        for (int i = 0; i < m; i++)
        {
            char op;
            int k;
            cin >> op >> k;
            if (op == 'U')
            {
                u += k;
                while (vl <= vr && ver[vl].first < u)
                {
                    if (deleted.find({ver[vl].first, ver[vl].second}) == deleted.end())
                    {
                        if (i % 2)
                            bob++;
                        else 
                            alice++;
                        deleted.insert({ver[vl].first, ver[vl].second});
                    }
                    vl++;
                }
            }
            else if (op == 'D')
            {
                d -= k;
                while (vl <= vr && ver[vr].first > d)
                {
                    if (deleted.find({ver[vr].first, ver[vr].second}) == deleted.end())
                    {
                        if (i % 2)
                            bob++;
                        else 
                            alice++;
                        deleted.insert({ver[vr].first, ver[vr].second});
                    }
                    vr--;
                }
            }
            else if (op == 'L')
            {
                l += k;
                while (hl <= hr && hor[hl].second < l)
                {
                    if (deleted.find({hor[hl].first, hor[hl].second}) == deleted.end())
                    {
                        if (i % 2)
                            bob++;
                        else 
                            alice++;
                        deleted.insert({hor[hl].first, hor[hl].second});
                    }
                    hl++;
                }
            }
            else if (op == 'R')
            {
                r -= k;
                while (hl <= hr && hor[hr].second > r)
                {
                    if (deleted.find({hor[hr].first, hor[hr].second}) == deleted.end())
                    {
                        if (i % 2)
                            bob++;
                        else 
                            alice++;
                        deleted.insert({hor[hr].first, hor[hr].second});
                    }
                    hr--;
                }
            }
        }
        cout << alice << " " << bob << "\n";
    }
    return 0;
}