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
        map<int, int> mapp;
        for (int i = 0; i < n; i++)
            cin >> a[i], mapp[a[i]]++;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        n = a.size();
        if (n == 1 || mapp.size() == 1)
            cout << "Alice\n";
        else 
        {
            string ans[2] = {"Alice", "Bob"};
            int cnt = 0;
            for (int i = 1; i < n; i++)
            {
                if (mapp[i])
                    cnt++;
                else 
                    break;
            }
            cnt += cnt == n;
            cout << ans[cnt % 2] << "\n";
        }
    }
    return 0;
}