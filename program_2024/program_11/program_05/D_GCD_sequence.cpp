#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++)
        b[i] = __gcd(a[i], a[i + 1]);
    auto check = [&](vector<int> b)
    {
        for (int i = 1; i < b.size(); i++)
        {
            if (b[i - 1] > b[i])
                return false;
        }
        return true;
    };
    int cnt = 0;
    for (int j = 1; j < n - 1; j++)
    {
        if (b[j - 1] > b[j])
        {
            for (int i = j - 1; i <= j + 1; i++)
            {
                vector<int> temp = b;
                if (i == 0)
                {
                    temp.erase(temp.begin());
                    if (check(temp))
                    {
                        cout << "YES\n";
                        return;
                    }
                }
                else if (i == 1)
                {
                    temp.erase(temp.begin());
                    temp.erase(temp.begin());
                    int z = __gcd(a[i - 1], a[i + 1]);
                    temp.insert(temp.begin(), z);
                    if (check(temp))
                    {
                        cout << "YES\n";
                        return;
                    }
                }
                else if (i == n - 1)
                {
                    temp.pop_back();
                    if (check(temp))
                    {
                        cout << "YES\n";
                        return;
                    }
                }
                else if (i == n - 2)
                {
                    int z = __gcd(a[i - 1], a[i + 1]);
                    temp.pop_back();
                    temp.pop_back();
                    temp.push_back(z);
                    if (check(temp))
                    {
                        cout << "YES\n";
                        return;
                    }
                }
                else 
                {
                    int z = __gcd(a[i - 1], a[i + 1]);
                    temp.erase(temp.begin() + i - 1, temp.begin() + i + 1);
                    temp.insert(temp.begin() + i - 1, z);
                    if (check(temp))
                    {
                        cout << "YES\n";
                        return;
                    }
                }
            }
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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