#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    int k;
    cin >> k;
    vector<int> n(k);
    intt ans = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> n[i];
        vector<int> a(n[i] - 1);
        for (int j = 0; j < n[i] - 1; j++)
            cin >> a[j];
        for (int k = 31; k >= 0; k--)
        {
            if ((n[i] >> k & 1) == 0)
                continue;
            if ((ans >> k & 1) == 0)
                ans |= 1ll << k;
            else 
                ans |= (1ll << k) - 1;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}