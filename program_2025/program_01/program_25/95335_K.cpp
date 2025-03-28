#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n);
    vector<pair<int, int>> a;
    
    for (int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        v[i] = vector<int>(len);
        for (int j = 0; j < len; j++)
            cin >> v[i][j];
    }
    
    sort(v.begin(), v.end(), [](vector<int> A, vector<int> B)
    {
        return A[0] < B[0];
    });
    
    for (int i = 0; i < n; i++)
    {
        for (auto j : v[i])
        {
            a.emplace_back(i, j);
        }
    }

    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            if (a[i] > a[j])
                sum++;
        }
    }
    
    k -= sum;
    
    if (k < 0)
    {
        cout << "No\n";
        return;
    }
    
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j + 1 < a.size(); j++)
        {
            if (a[j].second == a[j + 1].second)
                continue;
            if (k > 0 && a[j].first < a[j + 1].first)
            {
                swap(a[j], a[j + 1]);
                k--;
            }
        }
    }
    
    if (k > 0)
    {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for (int i = 0; i < a.size(); i++)
        cout << a[i].second << (i + 1 == a.size() ? '\n' : ' ');
}

signed main()
{
    int T = 1;
    while (T--)
        solve();
    return 0;
}