#include <bits/stdc++.h>
#define int long long
using namespace std;

int convert_to_minute(string s) {
    int hs = (s[0] - '0') * 10 + (s[1] - '0');
    int ms = (s[3] - '0') * 10 + (s[4] - '0');
    return hs * 60 + ms;
}

bool is_in_happy_time(vector<pair<int, int>>& happy_time, int t)
{
    for (auto [b, e] : happy_time)
    {
        if (t >= b && t <= e)
            return true;
    }
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    bool f = 0;
    vector<pair<int, int>> happy_times;
    for (int i = 0; i < n; i++)
    {
        string s_str, e_str;
        cin >> s_str >> e_str;
        int s = convert_to_minute(s_str), e = convert_to_minute(e_str);
        if (s == e)
            f = 1;
        if (s <= e)
            happy_times.push_back({s, e});
        else 
        {
            happy_times.push_back({0, e});
            happy_times.push_back({s, 1439});
        }
    }

    sort(happy_times.begin(), happy_times.end());
    vector<pair<int, int>> merge_times;
    int cur_s = happy_times[0].first, cur_e = happy_times[0].second;

    for (int i = 1; i < happy_times.size(); i++)
    {
        if (happy_times[i].first <= cur_e)
            cur_e = max(cur_e, happy_times[i].second);
        else 
        {
            merge_times.push_back({cur_s, cur_e});
            cur_s = happy_times[i].first;
            cur_e = happy_times[i].second;
        }
    }
    merge_times.push_back({cur_s, cur_e});

    set<string> favorite_teas;
    for (int i = 0; i < m; i++)
    {
        string tea;
        cin >> tea;
        favorite_teas.insert(tea);
    }

    int q;
    cin >> q;
    while (q--)   
    {
        string send_time_str, x_arrival_str, c_arrival_str, bought_tea;
        cin >> send_time_str >> x_arrival_str >> c_arrival_str >> bought_tea;

        int send_time = convert_to_minute(send_time_str);
        int x_arrival = convert_to_minute(x_arrival_str);
        int c_arrival = convert_to_minute(c_arrival_str);

        if (!(0 <= send_time && send_time <= 119))
        {
            cout << "Loser xqq\n";
            continue;
        }

        if (!is_in_happy_time(merge_times, send_time) && !f)
        {
            cout << "Loser xqq\n";
            continue;
        }

        if (x_arrival > c_arrival)
            cout << "Joker xqq\n";
        else if (favorite_teas.find(bought_tea) == favorite_teas.end())
            cout << "Joker xqq\n";
        else 
            cout << "Winner xqq\n";
    }
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