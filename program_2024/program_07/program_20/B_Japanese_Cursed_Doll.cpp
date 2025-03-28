#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> l(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];
    sort(l.begin(), l.end(), greater<int>());
    cout << (t - l[p - 1] >= 0 ? t - l[p - 1] : 0) << "\n";
    return 0;
}