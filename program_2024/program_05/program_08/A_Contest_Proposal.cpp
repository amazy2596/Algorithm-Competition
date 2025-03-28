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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        bool check = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (a[i] > b[i])
                check = 0;
        }
        for (int i = 0; i < n && !check; i++)
        {
            a.insert(upper_bound(a.begin(), a.end(), b[i]), b[i]);
            a.pop_back();
            bool f = 1;
            for (int j = 0; j < n; j++)
            {
                if (a[j] > b[j])
                {
                    f = 0;
                    break;
                }
            }
            if (f)
            {
                cout << i + 1 << "\n";
                break;
            }
        }
        if (check)
            cout << 0 << "\n";
    }
    return 0;
}