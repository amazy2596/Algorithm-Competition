#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n < 7)
    {
        cout << "NO\n";
        return;
    }
    string tar = "CHICKEN";
    map<char, int> mp;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
        if (s[i] == tar[j])
            j++;
    }
    if (j == tar.length())
    {
        for (auto ch : tar)
            mp[ch]--;
    }
    else 
    {
        cout << "NO\n";
        return;
    }

    vector<int> cnt;
    int sum = 0;
    for (auto [ch, val] : mp)
    {
        cnt.push_back(val);
        sum += val;
    }

    sort(cnt.rbegin(), cnt.rend());
    if (cnt[0] > sum - cnt[0])
        cout << "NO\n";
    else 
    {
        if (sum % 2 == 0)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}