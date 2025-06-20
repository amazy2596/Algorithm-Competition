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
        intt n;
        cin >> n;
        vector<intt> ans;
        for (int i = 62; i >= 0; i--)
        {
            if ((n >> i & 1ll))
            {
                if ((n ^ (1ll << i)) == 0)
                    continue;
                ans.push_back(n ^ (1ll << i));
            }
        }
        cout << ans.size() + 1 << "\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << n << "\n";
    }
    return 0;
}