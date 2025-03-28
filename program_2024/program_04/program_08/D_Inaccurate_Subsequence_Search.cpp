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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        map<int, int> mapa, mapb;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
        {
            int b;
            cin >> b;
            mapb[b]++;
        }
        int ans = 0, cnt = 0;;
        for (int i = 0; i < m; i++)
        {
            if (++mapa[a[i]] <= mapb[a[i]])
                cnt++;
        }
        if (cnt >= k)
            ans++;
        int l = 1, r = m;
        while (r < n)
        {
            if (mapb[a[l - 1]])
                if (mapa[a[l - 1]]-- <= mapb[a[l - 1]])
                    cnt--;
            if (mapb[a[r]])
                if (++mapa[a[r]] <= mapb[a[r]])
                    cnt++;
            if (cnt >= k)
                ans++;
            l++, r++;
        }
        cout << ans << "\n";
    }
    return 0;
}