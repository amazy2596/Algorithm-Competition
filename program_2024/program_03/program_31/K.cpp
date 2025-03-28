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
        int m;
        cin >> m;
        intt ans = 1;
        vector<pair<int, intt>> mul, div; 
        while (m--)
        {
            int op;
            int x;
            cin >> op >> x;
            if (op == 0)
                mul.push_back({op, x});
            else 
                div.push_back({op, x});
        }
        int idx = 0;
        for (int i = 0; i < mul.size(); i++)
        {
            if (ans >= 1e9 && idx < div.size())
                ans /= div[idx++].second;
            else 
            {
                ans *= mul[i].second;
            }
        }
        while (idx < div.size())
        {
            ans /= div[idx++].second;
        }
        int n;
        cin >> n;
        idx = 0;
        intt solve = 1;
        mul.clear(), div.clear();
        while (n--)
        {
            int op;
            int x;
            cin >> op >> x;
            if (op == 0)
                mul.push_back({op, x});
            else 
                div.push_back({op, x});
        }
        idx = 0;
        for (int i = 0; i < mul.size(); i++)
        {
            if (solve >= 1e9 && idx < div.size())
                solve /= div[idx++].second;
            else 
            {
                solve *= mul[i].second;
            }
        }
        while (idx < div.size())
        {
            solve /= div[idx++].second;
        }
        if (ans == solve)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
    return 0;
}