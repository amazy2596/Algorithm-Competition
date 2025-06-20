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
        string s;
        cin >> n >> s;
        set<char> ss;
        for (int i = 0; i < n; i++)
            ss.insert(s[i]);
        vector<char> temp;
        for (auto cur : ss)
            temp.push_back(cur);
        for (int i = 0; i < n; i++)
        {
            int it = lower_bound(temp.begin(), temp.end(), s[i]) - temp.begin();
            s[i] = temp[temp.size() - it - 1];
        }
        cout << s << "\n";
    }
    return 0;
}