#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    getline(cin, s);

    deque<char> left, right;
    for (int i = 0; i < s.length(); i++)
        left.emplace_back(s[i]);

    string op;
    getline(cin, op);
    istringstream iss(op);
    string token;
    while (iss >> token)
    {
        if (token == "CTRL")
        {
            string nx;
            iss >> nx;
            if (nx == "S")
            {
                for (auto ch : left)
                    cout << ch;
                for (auto ch : right)
                    cout << ch;
                cout << "\n";
            }
            else 
            {
                nx.erase(nx.begin());
                int cnt = 0;
                for (int i = 0; i < nx.size(); i++)
                    cnt = (cnt * 10 + (nx[i] - '0'));
                while (cnt--)
                    left.emplace_back(left.back());
            }
        }
        else if (token == "LEFT")
        {
            if (!left.empty())
            {
                right.emplace_front(left.back());
                left.pop_back();
            }
        }
        else if (token == "RIGHT")
        {
            if (!right.empty())
            {
                left.emplace_back(right.front());
                right.pop_front();
            }
        }
            
    }

    for (auto ch : left)
        cout << ch;
    for (auto ch : right)
        cout << ch;
    cout << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}