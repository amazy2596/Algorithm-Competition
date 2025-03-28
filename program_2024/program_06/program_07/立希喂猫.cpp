    #include <bits/stdc++.h>
    using intt = long long;
    using namespace std;

    int main()
    {
        ios::sync_with_stdio(false);
        cout.tie(nullptr);
        cin.tie(nullptr);
        intt n, sum = 0;
        cin >> n;
        vector<pair<intt, intt>> p(n), cnt;
        for (int i = 0; i < n; i++)
            cin >> p[i].first, sum += p[i].first;
        for (int i = 0; i < n; i++)
            cin >> p[i].second;
        sort(p.begin(), p.end(), [&](pair<intt, intt> a, pair<intt, intt> b)
        {
            return a.second < b.second;
        });
        cnt.push_back({0, 0});
        cnt.push_back({p[0].first, p[0].second});
        for (int i = 0; i < n - 1; i++)
        {
            if (p[i].second == p[i + 1].second)
                cnt.back().first += p[i + 1].first;
            else 
                cnt.push_back({p[i + 1].first, p[i + 1].second});
        }
        vector<intt> prefixsum(cnt.size()), day(cnt.size());
        for (int i = 1; i < prefixsum.size(); i++)
        {
            prefixsum[i] = sum + prefixsum[i - 1];
            day[i] = cnt[i].second;
            sum -= cnt[i].first;
        }
        intt q;
        cin >> q;
        while (q--)
        {
            intt k;
            cin >> k;
            if (k > day.back())
            {
                cout << prefixsum.back() << "\n";
                continue;
            }
            int l = 0, r = day.size();
            while (l < r)
            {
                int mid = l + r >> 1;
                if (day[mid] >= k)
                    r = mid;
                else 
                    l = mid + 1;
            }
            intt ans = prefixsum[l];
            ans += (k - day[l]) * cnt[l + 1].first;
            cout << ans << "\n";
        }
        return 0;
    }