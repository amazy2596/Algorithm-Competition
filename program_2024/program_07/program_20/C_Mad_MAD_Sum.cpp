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
        vector<int> a(n + 1);
        intt sum = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], sum += a[i];
        for (int k = 1; k <= n; k++)
        {
            unordered_map<int, int> mp, count;
            int mx = 0;
            for (int i = k; i <= n; i++)
            {
                mp[a[i]]++;
                if (mp[a[i]] >= 2 && a[i] > mx)
                    mx = a[i];
                a[i] = mx;
                sum += mx;
            }
            bool f1 = 1, f2 = 1;
            for (int i = 1; i <= n; i++)
            {
                count[a[i]]++;
                if (a[i - 1] > a[i])
                {
                    f1 = 0;
                    break;
                }
            }
            for (auto [key, val] : count)
            {
                if (key != 0 && val <= 1)
                {
                    f2 = 0;
                    break;
                }
            }
            if (f1 && f2)
                break;
        }
        for (int i = 1; i <= n; i++)
            sum += 1ll * (n - i) * a[i];
        cout << sum << "\n";
    }
    return 0;
}