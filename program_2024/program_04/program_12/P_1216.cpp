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
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
            a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
    }
    cout << a[1][1];
    return 0;
}