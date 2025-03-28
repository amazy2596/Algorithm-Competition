#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n > m)
        swap(n, m);
    if (n % 2 == 1 && m % 2 == 1)
        cout << "No\n";
    else if (n == 1 && m == 2)
        cout << "Yes\n";
    else if (a == 1 && b == 1)
        cout << "Yes\n";
    else if (a == 0 && b == 0)
        cout << "No\n";
    else if (a == 0 && b == 1)
    {
        if (n == 2 || m == 2)
            cout << "Yes\n";
        else if (n % 2 == 0 && m % 2 == 0)
        {
            int t1 = n % 3, t2 = m % 3;
            if (t1 == 2 || t2 == 2 || t1 == 0 || t2 == 0)
                cout << "Yes\n";
            else 
                cout << "No\n";
        }
        else 
        {
            if (n % 2 == 0)
            {
                if (m % 3 == 2 || m % 3 == 0)
                    cout << "Yes\n";
                else 
                    cout << "No\n";
            }
            else             {
                if (n % 3 == 2 || n % 3 == 0)
                    cout << "Yes\n";
                else 
                    cout << "No\n";
            }
        }
    }
    else
    {
        if (n == 1 && m % 2 == 0)
            cout << "Yes\n";
        else 
            cout << "No\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}