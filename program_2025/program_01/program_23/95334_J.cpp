#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, h, m;
    cin >> n >> h >> m;
    
    // map<string, map<pair<int, int>, int>> mp;
    vector<map<string, int>> mp(3);
    for (int i = 0; i < n; i++)
    {
        string id, a, b;
        cin >> id >> a >> b;

        string year_s(a.begin(), a.begin() + 4), month_s(a.begin() + 5, a.begin() + 7), day_s(a.begin() + 8, a.end());
        int year = stoi(year_s), month = stoi(month_s), day = stoi(day_s);

        if (year == h && month == m)
        {
            int hour = stoi(b.substr(0, 2)), minute = stoi(b.substr(3, 2)), second = stoi(b.substr(6, 2));

            int time = hour * 60 * 60 + minute * 60 + second;

            if ((7 * 3600 <= time && time <= 9 * 3600) || (18 * 3600 <= time && time <= 20 * 3600))
                mp[0][id]++;
            
            if (11 * 3600 <= time && time <= 13 * 3600)
                mp[1][id]++;

            if ((22 * 3600 <= time && time <= 24 * 3600) || (0 <= time && time <= 3600))
                mp[2][id]++;
        }

        
    }

    cout << mp[0].size() << " " << mp[1].size() << " " << mp[2].size() << "\n";
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