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
    vector<int> a(n);
    int ans = -1e9, cur = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cur = max(0, cur + a[i]);
        ans = max(ans, cur);
    }
    cout << (ans ? ans : *max_element(a.begin(), a.end()));
    // cout << ans << "\n";
    return 0;
}