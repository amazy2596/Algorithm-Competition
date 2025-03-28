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
    vector<intt> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    vector<intt> b(m + 1), prefixsum(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(b.begin(), b.end());
    for (int i = 1; i <= m; i++)
        prefixsum[i] = prefixsum[i - 1] + b[i];
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(prefixsum.begin(), prefixsum.end(), a[i]);
        it--;
        cout << it - prefixsum.begin() << " ";
    }
    return 0;
}