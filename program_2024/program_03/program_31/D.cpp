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
        intt l, r;
        cin >> l >> r;
        vector<pair<intt, intt>> p(3);
        for (int i = 0; i < 3; i++)
            cin >> p[i].first >> p[i].second;
        sort(p.begin(), p.end());
        if (l >= p[2].first)
        {
            double ans = 0;
            double x = l;
            for (int i = 0; i < 3; i++)
                ans += sqrt((p[i].first - x) * (p[i].first - x) + p[i].second * p[i].second);
            cout << fixed << setprecision(1) << ans << "\n";
        }
        else if (r <= p[0].first)
        {
            double ans = 0;
            double x = r;
            for (int i = 0; i < 3; i++)
                ans += sqrt((p[i].first - x) * (p[i].first - x) + p[i].second * p[i].second);
            cout << fixed << setprecision(1) << ans << "\n";
        }
        else 
        {
            double k1 = (p[0].second + p[1].second) / (p[0].first - p[1].first),
                   k2 = (p[1].second + p[2].second) / (p[1].first - p[2].first),
                   k3 = (p[0].second + p[2].second) / (p[0].first - p[2].first);
            double temp_x[3];
            temp_x[0] = (k1 * p[0].first - p[0].second) / k1;
            temp_x[1] = (k2 * p[1].first - p[1].second) / k2;
            temp_x[2] = (k3 * p[0].first - p[0].second) / k3;
            double ans = INT32_MAX;
            for (int i = 0; i < 3; i++)
            {
                if (temp_x[i] <= r && temp_x[i] >= l)
                    ans = min(ans, sqrt((p[0].first - temp_x[i]) * (p[0].first - temp_x[i]) + p[0].second * p[0].second) + sqrt((p[1].first - temp_x[i]) * (p[1].first - temp_x[i]) + p[1].second * p[1].second) + sqrt((p[2].first - temp_x[i]) * (p[2].first - temp_x[i]) + p[2].second * p[2].second));
            }
            cout << fixed << setprecision(1) << ans << "\n";
        }
    }
    return 0;
}