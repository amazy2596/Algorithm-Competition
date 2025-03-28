#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> a, b, ans;
    map<string, int> map_a, map_b, map_ans;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (map_a.find(s) == map_a.end())
            a.push_back(s), map_a[s]++;
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (map_b.find(s) == map_b.end())
            b.push_back(s), map_b[s]++;
    }
    for (int i = 0, j = 0; i < a.size() || j < b.size(); i++, j++)
    {
        if (i < a.size())
            ans.push_back(a[i]);
        if (j < b.size())
            ans.push_back(b[i]);
    }
    for (int i = 0; i < ans.size(); i++)
        if (map_ans.find(ans[i]) == map_ans.end())
            cout << ans[i] << "\n", map_ans[ans[i]]++;
        else 
            map_ans[ans[i]]++;
    return 0;
}