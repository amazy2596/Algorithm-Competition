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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        intt ans = 0;
        map<pair<int, int>, int> mp1, mp2, mp3;
        map<vector<int>, int> cnt;
        for (int i = 2; i < n; i++)
        {
            ans += mp1[{a[i - 2], a[i - 1]}]++;
            ans += mp2[{a[i - 1], a[i]}]++;
            ans += mp3[{a[i - 2], a[i]}]++;
            vector<int> v = {a[i - 2], a[i - 1], a[i]};
            ans -= 3 * cnt[v];
            cnt[v]++;
        }
        cout << ans << "\n";
    }
    return 0;
}