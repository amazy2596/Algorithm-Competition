#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    getline(cin, a[0]);
    for (int i = 0; i < n; i++)
        getline(cin, a[i]);

    int k;
    cin >> k;
    string all;
    getline(cin, all);
    getline(cin, all);

    map<int, int> line;
    vector<int> vis(all.size() + 1);
    while (true)
    {
        bool f = 1;
        for (auto key : a)
        {
            int l = all.find(key);
            while (l != -1)
            {
                if (l != -1 && line.find(l) == line.end())
                {
                    f = 0;
                    int r = l;
                    while (r < all.size())
                    {
                        if (all.substr(l, r - l + 1) == key)
                        {
                            for (int i = l; i <= r; i++)
                                all[i] = '*';
                            line[l] = r;
                            break;
                        }
                        r++;
                    }
                }
                l = all.find(key);
            }
        }
        if (f)
            break;
    }

    if (line.size() >= k)
    {
        cout << line.size() << "\n";
        cout << "He Xie Ni Quan Jia!\n";
        return;
    }

    for (int i = 0; i < all.size(); i++)
    {
        if (line.find(i) == line.end())
        {
            cout << all[i];
            continue;
        }
        
        cout << "<censored>";
        i = line[i];
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}