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
    intt ans = 1ll * n * (n - 1) / 2;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < n && r[j] < l[i])
            j++;
        ans -= j;
    }
    cout << ans << "\n";
    return 0;
}