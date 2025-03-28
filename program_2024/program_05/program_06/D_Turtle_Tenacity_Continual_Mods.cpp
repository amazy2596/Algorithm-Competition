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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int mn = *min_element(a.begin(), a.end());
        if (count(a.begin(), a.end(), mn) == 1)
        {
            cout << "YES\n";
            continue;
        }
        else 
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] % mn != 0)
                {
                    cout << "YES\n";
                    break;
                }
                if (i == n - 1)
                    cout << "NO\n";
            }
        }
    }
    return 0;
}