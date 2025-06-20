#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> s[i];
    vector<vector<int>> ans(n, vector<int>(4));
    for (int k = 0; k < n; k++)
    {
        int i = k, j = k, count = 0, target = n - k;
        while (j < 2 * n - k && s[i][j] == 'X')
            j++;
        while (j < 2 * n - k)
        {
            if (s[i][j] == 'X')
                count++;
            if (count == target)
                break;
            j++;
        }
        if (count == target)
        {
            ans[k][1] = (2 * n - k) - (j + 1);
            ans[k][2] = ans[k][1] + 2 * (n - k) - 1;
            ans[k][3] = ans[k][2] + 2 * (n - k) - 1;
            ans[k][0] = ans[k][3] + 2 * (n - k) - 1;
            continue;
        }
        else
            i++, j--;

        while (i < 2 * n - k)
        {
            if (s[i][j] == 'X')
                count++;
            if (count == target)
                break;
            i++;
        }
        if (count == target)
        {
            ans[k][2] = (2 * n - k) - (i + 1);
            ans[k][3] = ans[k][2] + 2 * (n - k) - 1;
            ans[k][0] = ans[k][3] + 2 * (n - k) - 1;
            ans[k][1] = ans[k][0] + 2 * (n - k) - 1;
            continue;
        }
        else
            i--, j--;

        while (j >= k)
        {
            if (s[i][j] == 'X')
                count++;
            if (count == target)
                break;
            j--;
        }
        if (count == target)
        {
            ans[k][3] = j - k;
            ans[k][0] = ans[k][3] + 2 * (n - k) - 1;
            ans[k][1] = ans[k][0] + 2 * (n - k) - 1;
            ans[k][2] = ans[k][1] + 2 * (n - k) - 1;
            continue;
        }
        else
            i--, j++;

        while (i >= k)
        {
            if (s[i][j] == 'X')
                count++;
            if (count == target)
                break;
            i--;
        }
        if (count == target)
        {
            ans[k][0] = i - k;
            ans[k][1] = ans[k][0] + 2 * (n - k) - 1;
            ans[k][2] = ans[k][1] + 2 * (n - k) - 1;
            ans[k][3] = ans[k][2] + 2 * (n - k) - 1;
            continue;
        }
        else
            i++, j++;
        
        while (j < 2 * n - k)
        {
            if (s[i][j] == 'X')
                count++;
            if (count == target)
                break;
            j++;
        }
        if (count == target)
        {
            ans[k][1] = (2 * n - k) - (j + 1);
            ans[k][2] = ans[k][1] + 2 * (n - k) - 1;
            ans[k][3] = ans[k][2] + 2 * (n - k) - 1;
            ans[k][0] = ans[k][3] + 2 * (n - k) - 1;
            continue;
        }
        else
            i++, j--;
    }
    vector<int> cnt(4);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            cnt[j] += ans[i][j];
    cout << min({cnt[0] , cnt[1], cnt[2], cnt[3]}) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}