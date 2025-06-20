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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> idx(m);
        for (int i = 0; i < m; i++)
            cin >> idx[i];
        vector<char> ch(m);
        for (int i = 0; i < m; i++)
            cin >> ch[i];
        sort(ch.begin(), ch.end());
        sort(idx.begin(), idx.end());
        idx.erase(unique(idx.begin(), idx.end()), idx.end());
        int cnt = 0;
        for (int i = 0; i < idx.size(); i++)
            s[idx[i] - 1] = ch[cnt++];
        cout << s << "\n";
    }
    return 0;
}