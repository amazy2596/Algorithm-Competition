#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    getline(cin, s);

    auto check = [&]() -> pair<int, int>
    {
        for (int len = s.length(); len > 1; len--)
        {
            for (int l = 0; l + len - 1 < s.length(); l++)
            {
                int r = l + len - 1;

                int i = l, j = r;
                while (i <= j && s[i] == s[j])
                    i++, j--;
                if (i >= j)
                {
                    return {l, r};
                }
            }
        }

        return {-1, -1};
    };

    while (true)
    {
        auto [l, r] = check();
        // cout << s.substr(l, r - l + 1) << "\n";
        if (l == -1 && r == -1)
        {
            cout << s << "\n";
            return;
        }
        s.erase(s.begin() + l + ceil((r - l + 1) * 1.0 / 2), s.begin() + r + 1);
    }
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