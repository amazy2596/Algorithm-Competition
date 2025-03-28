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
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        vector<int> logs;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == 'L')
                logs.push_back(i);
        logs.push_back(n + 1);
        int i = -1;
        int next_log = 0;
        bool f = 1;
        while (i < n - 1)
        {
            if (m >= logs[next_log] - i)
                i = logs[next_log];
            else 
            {
                i += m;
                if (i > n - 1)
                {
                    f = 1;
                    break;
                }
                while (i < n && i < logs[next_log])
                {
                    if (s[i] != 'C' && k > 0)
                    {
                        i++;
                        k--;
                    }
                    else 
                    {
                        f = 0;
                        i = n;
                        break;
                    }
                }
            }
            next_log++;
        }
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}