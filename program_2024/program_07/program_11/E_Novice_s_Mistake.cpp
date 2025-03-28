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
        string s = to_string(n);
        vector<pair<int, int>> ans;
        for (int a = 1; a <= 10000; a++)
        {
            int len = s.length() * a;
            for (int b = max(len - 10, 1); b <= min(10000, len - 1); b++)
            {
                // int b = 2519;
                string cur;
                while (cur.length() <= len - b)
                    cur += s;
                while (cur.length() && cur.length() > len - b)
                    cur.pop_back();
                int temp = 0;
                for (int i = 0; i < cur.length(); i++)
                    temp = cur[i] - '0' + temp * 10;
                if (temp == a * n - b)
                    ans.push_back({a, b});
            }
        }
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}