#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    set<int> s;
    s.insert(x);
    for (int i = 0; i < m; i++)
    {
        int r;
        char op;
        cin >> r >> op;
        set<int> temp = s;
        s.clear();
        while (!temp.empty())
        {
            auto cur = *temp.begin();
            temp.erase(temp.begin());
            if (op == '0')
                s.insert(((cur + r) % n == 0 ? n : (cur + r) % n));
            else if (op == '1')
                s.insert(((cur - r + n) % n == 0 ? n : (cur - r + n) % n));
            else
            {
                s.insert(((cur + r) % n == 0 ? n : (cur + r) % n));
                s.insert(((cur - r + n) % n == 0 ? n : (cur - r + n) % n));
            }
        }
    }
    cout << s.size() << "\n";
    while (!s.empty())
    {
        cout << *s.begin() << " ";
        s.erase(s.begin());
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}