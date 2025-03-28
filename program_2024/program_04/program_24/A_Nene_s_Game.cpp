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
        int k, q;
        cin >> k >> q;
        vector<int> a(k);
        for (int i = 0; i < k; i++)
            cin >> a[i];
        while (q--)
        {
            int n;
            cin >> n;
            while (true)
            {
                auto ed = lower_bound(a.begin(), a.end(), n);
                // cout << ed - a.begin() << endl;
                if (ed == a.begin() && n < *ed)
                    break;
                else if (*ed == n)
                    n -= ed - a.begin() + 1;
                else 
                    n -= ed - a.begin();
            }
            cout << n << " \n"[q == 0];
        }
    }
    return 0;
}