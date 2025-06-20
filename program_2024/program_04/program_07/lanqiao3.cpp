#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<intt> cnt(n + 2), ans(n + 1);
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cnt[l] += k;
        cnt[r + 1] -= k; 
    }
    for (int i = 1; i <= n; i++)
        ans[i] = ans[i - 1] + cnt[i];
    for (int i = 1; i <= n; i++)
    {
        ans[i] %= 26;
        while (ans[i]--)
        {
            if (s[i - 1] == 'z')
                s[i - 1] = 'a';
            else 
                s[i - 1]++;
        }
    }
    cout << s;
    return 0;
}