#include <bits/stdc++.h>
#define int long long
using namespace std;

map<string, pair<string, string>> opted;

pair<string, string> parse(string type)
{
    int l = type.find('<');
    int bal = 0, idx = -1;
    for (int i = l + 1; i < type.length(); i++)
    {
        if (type[i] == '<')
            bal++;
        if (type[i] == '>')
            bal--;
        if (type[i] == ',' && bal == 0)
        {
            idx = i;
            break;
        }
    }
    string first_type = type.substr(l + 1, idx - l - 1);
    string second_type = type.substr(idx + 1, type.length() - idx - 2);
    return {first_type, second_type};
}

void solve()
{
    int n, m;
    cin >> n >> m;
    map<string, string> mp;
    for (int i = 0; i < n; i++)
    {
        string key, val;
        cin >> key >> val;
        val.pop_back();
        mp[val] = key;
    }
    for (auto [name, type] : mp)
    {
        if (type.substr(0, 4) == "pair")
            opted[name] = parse(type);
    }

    for (int i = 0; i < m; i++)
    {
        string q;
        cin >> q;
        string name = q.substr(0, q.find('.'));
        string type = mp[name];
        string suffix = q.substr(q.find('.') + 1);
        while (!suffix.empty())
        {
            string cur = suffix.substr(0, suffix.find('.'));
            suffix = (suffix.find('.') != -1) ? suffix.substr(suffix.find('.') + 1) : "";
            if (cur == "first") 
                type = opted[name].first;
            else if (cur == "second")
                type = opted[name].second;
            
            if (type.substr(0, 4) == "pair")
            {
                name = type;
                if (opted.find(name) == opted.end())
                    opted[name] = parse(type);
            }
        }
        cout << type << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}