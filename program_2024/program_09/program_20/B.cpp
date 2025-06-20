#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (!st.empty() && ((st.top() == 'f' && s[i] == 'c') || (st.top() == 't' && s[i] == 'b')))
            st.pop();
        else 
            st.push(s[i]);
    }
    cout << st.size() << "\n";
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