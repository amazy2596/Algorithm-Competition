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
        intt n, k, q;
        cin >> n >> k >> q;
        vector<double> a(k + 1), b(k + 1);
        for (int i = 1; i <= k; i++)
            cin >> a[i];
        for (int i = 1; i <= k; i++)
            cin >> b[i];
        while (q--)
        {
            intt d;
            cin >> d;
            auto idx = lower_bound(a.begin() + 1, a.end(), d) - a.begin();
            intt aa = a[idx] - a[idx - 1];
            intt bb = b[idx] - b[idx - 1];
            intt diff = d - a[idx - 1];
            intt ans = b[idx - 1] + (diff * bb) / aa;
            // intt ans = floor(temp);
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}