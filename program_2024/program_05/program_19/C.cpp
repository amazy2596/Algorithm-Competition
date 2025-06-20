 #include <bits/stdc++.h>
 using intt = long long;
 using namespace std;
 
 int main()
 {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.length();
    s = " " + s + " ";
    vector<int> prefixsum(n + 2, 0), suffixsum(n + 2, 0);
    for (int i = 1; i <= n; i++)
        prefixsum[i] = prefixsum[i - 1] + ((s[i] >= 'a' && s[i] <= 'z') ? 1 : 0);
    for (int i = n; i >= 1; i--)
        suffixsum[i] = suffixsum[i + 1] + ((s[i] >= 'A' && s[i] <= 'Z') ? 1 : 0);
    int ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        // cout << i << ": " << prefixsum[i] + suffixsum[i + 1] << "\n";
        if (i == n)
            ans = min(ans, prefixsum[i] + 1);
        else 
            ans = min(ans, prefixsum[i] + suffixsum[i + 1]);
    }
    cout << ans << "\n";
    return 0;
 }