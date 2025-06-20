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
        vector<int> a;
        map<int, int> count;
        int mn = 1e9, mx = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
            if (count.find(x) == count.end())
                a.push_back(x);
            count[x]++;
        }
        if (count[mn] >= 2)
        {
            bool ok = 0, check = 1;
            for (int i = 1; i < a.size(); i++)
            {
                if (a[i] > a[i - 1] && !ok)
                    ok = 1;
                if (ok)
                {
                    if (a[i] < a[i - 1])
                    {
                        check = 0;
                        break;
                    }
                }
            }
            if (check && mx == count.size())
                cout << "Yes\n";
            else 
                cout << "No\n";
        }
    }
    return 0;
}