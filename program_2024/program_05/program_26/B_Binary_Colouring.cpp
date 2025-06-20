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
        intt x;
        cin >> x;
        vector<int> ans(35);
        for (int i = 0; i < 33; i++)
            ans[i] = x >> i & 1;
        int q = 100;
        while (q--)
        {
            for (int i = 31; i >= 0; i--)
            {
                if (ans[i] == 1 && ans[i + 1] == 1)
                {
                    ans[i + 2] = 1;
                    ans[i + 1] = 0;
                    ans[i] = -1;
                }
                if (ans[i] == -1 && ans[i + 1] == -1)
                {
                    ans[i + 2] = -1;
                    ans[i + 1] = 0;
                    ans[i] = 1;
                }
                if (ans[i] == 1 && ans[i + 1] == -1)
                {
                    ans[i] = -1;
                    ans[i + 1] = 0;
                }
                if (ans[i] == -1 && ans[i + 1] == 1)
                {
                    ans[i] = 1;
                    ans[i + 1] = 0;
                }
            }
        }
        while (ans.back() == 0)
            ans.pop_back();
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}