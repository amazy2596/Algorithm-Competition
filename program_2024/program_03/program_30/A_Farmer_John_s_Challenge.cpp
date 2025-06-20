#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n == 1)
            cout << 1 << "\n";
        else if (n == 2)
        {
            if (k == 1)
                cout << 1 << " " << 2 << "\n";
            else 
                cout << 1 << " " << 1 << "\n";
        }
        else 
        {
            if (k == 1)
            {
                for (int i = 1; i <= n; i++)
                    cout << i << " ";
                cout << "\n";
            }
            else if (k == n)
            {
                for (int i = 0; i < n; i++)
                    cout << 1 << " ";
                cout << "\n";
            }
            else 
                cout << "-1\n";
        }
    }
    return 0;
}