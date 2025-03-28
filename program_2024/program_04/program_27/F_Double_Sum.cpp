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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first, a[i].second = i;
    sort(a.begin(), a.end(), [&](pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    });
    intt ans = 0;
    
    return 0;
}