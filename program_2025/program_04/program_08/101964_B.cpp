#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> a(26);
    for (int i = 0; i < s.length(); i++)
        a[s[i] - 'a']++;

    set<pair<int, char>> st;
    for (int i = 0; i < 26; i++)
        if (a[i] > 0)
            st.insert({a[i], (char)('a' + i)});

    string t = "";
    int mx = *max_element(a.begin(), a.end());

    if (mx == 1)
    {
        cout << n << "\n";
        cout << s << "\n";
        return;
    }

    int k = (n - 1) / (mx - 1);

    vector<int> last(26, -1);
    queue<pair<int, char>> q;

    while (st.size())
    {
        auto [cnt, ch] = *st.rbegin();
        q.push({cnt, ch});
        st.erase({cnt, ch});
    }

    int j = 0;
    while (q.size())
    {
        auto [cnt, ch] = q.front();
        q.pop();
        if (last[ch - 'a'] == -1 || j - last[ch - 'a'] >= k)
        {
            t += ch, cnt--;
            last[ch - 'a'] = j++;
        }
        if (cnt > 0)
            q.push({cnt, ch});
    }

    cout << k << "\n";
    cout << t << "\n";
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