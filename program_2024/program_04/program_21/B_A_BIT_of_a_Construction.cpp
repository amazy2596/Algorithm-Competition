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
        vector<int> ans;
        if (n == 1)
            ans.push_back(k);
        else 
        {
            int i;
            for (i = 1; i < k; i++)
            {
                if (k >= pow(2, i) - 1 && k < pow(2, i + 1) - 1)
                    break;
            }
            int cur = 0;
            cur += pow(2, i) - 1;
            ans.push_back(pow(2, i) - 1);
            while (cur < k || ans.size() < n)
            {
                ans.push_back(k - cur);
                cur += k - cur;
            }
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n - 1];
    }
    return 0;
}