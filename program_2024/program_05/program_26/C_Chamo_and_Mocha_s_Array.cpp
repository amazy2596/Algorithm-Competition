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
        if (n == 2)
            cout << *min_element(a.begin(), a.end()) << "\n";
        else 
        {
            int ans = min(a[0], a[1]);
            for (int i = 0; i < n - 2; i++)
            {
                vector<int> temp;
                for (int j = 0; j < 3; j++)
                    temp.push_back(a[i + j]);
                sort(temp.begin(), temp.end());
                ans = max(ans, temp[1]);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}