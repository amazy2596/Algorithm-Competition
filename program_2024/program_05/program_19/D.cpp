#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    intt ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        if (i >= k && --mp[a[i - k]] == 0)
            mp.erase(a[i - k]);
        ans += mp.rbegin()->first == k && mp.size() == k; 
    }
    cout << ans << "\n";
    return 0;
}