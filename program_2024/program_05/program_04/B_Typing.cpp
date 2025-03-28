#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    vector<int> ans;
    for (int i = 0; i < a.length(); )
    {
        for (int j = 0; j < b.length(); j++)
        {
            if (a[i] == b[j])
            {
                i++;
                ans.push_back(j + 1);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}