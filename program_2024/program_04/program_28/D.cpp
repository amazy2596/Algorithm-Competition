#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 2e5 + 5;
vector<vector<int>> ans(N);

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt n, d;
    cin >> n >> d;
    int mn = n - 1, mx = n * (n - 1) / 2;
    if (d < mn || d > mx)
        cout << "NO\n";
    else if (n == 1) 
        cout << 0 << "\n";
    else if (n == 2)
    {
        cout << "1 2\n";
        cout << 1 << "\n";
    }
    else if (n == 3)
    {
        if (d == 2)
        {
            cout << "1 2\n";
            cout << "1 3\n";
            cout << 1 << "\n";
        }
        else 
        {
            cout << "1 2\n";
            cout << "2 3\n";
            cout << 1 << "\n";
        }
    }
    else 
    {
        int a;
        for (int i = 3; i <= n; i++)
        {
            int cur = i * (i - 1) / 2;
            if (d < cur)
            {
                a = i - 1;
                d -= a * (a - 1) / 2;
                break;
            }
        }
        vector<int> idx;
        for (int i = 1; i <= a; i++)
        {
            if (i != a)
                ans[i].push_back(i + 1);
            idx.push_back(i);
        }
        int have = n - a;
        for (int i = a + 1; i <= n; i++)
        {
            for (int j = idx.size() - 1; j >= 0; j--)
            {
                if (d - idx[j] >= n - i)
                {
                    
                    d -= idx[j];
                    ans[idx[j]].push_back(i);
                }
            }
        }
        cout << "YES\n";
        for (int i = 0; i < idx.size(); i++)
        {
            for (int j = 0; j < ans[idx[i]].size(); j++)
                cout << idx[i] << " " << ans[idx[i]][j] << "\n";
        }
        cout << 1 << "\n";
    }
    return 0;
}