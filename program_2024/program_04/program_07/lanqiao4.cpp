#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), cnt(32);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    intt ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 32; j++)
            if ((a[i] >> j) & 1 == 1)
                ans += cnt[j];
        for (int j = 0; j < 32; j++)
            if ((a[i] >> j) & 1 == 1)
                cnt[j]++;
    }
    cout << ans << "\n";
    return 0;
}