#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int beg;
    int n;
    cin >> beg >> n;
    // unordered_map<string, int> val;
    // unordered_map<string, string> nxt;
    vector<int> vis(1e6 + 5), val(1e6 + 5), nxt(1e6 + 5);
    for (int i = 0; i < n; i++)
    {
        int address, nt;
        int value;
        cin >> address >> value >> nt;
        val[address] = value;
        nxt[address] = nt;
    }

    int ans = -1;
    int p = -1;
    bool isFirst = true;
    vis[abs(val[beg])] = true;
    int a = beg, b = nxt[beg];
    while (true)
    {
        if (b == -1)
            break;
        if (vis[abs(val[b])])
        {
            if (isFirst)
            {
                ans = p = b;
                if (b == -1)
                    break;
                nxt[a] = nxt[b];

                nxt[p] = -1;

                isFirst = false;
            }
            else 
            {
                if (b == -1)
                    break;
                nxt[p] = b;
                p = nxt[p];
                nxt[a] = nxt[b];

                nxt[p] = -1;
            }

            b = nxt[a];
            if (b == -1)
                break;
            continue;
        }
        if (b == -1)
            break;
        vis[abs(val[b])] = true;

        if (nxt[b] == -1)
            break;
        a = b, b = nxt[b];
    }

    while (ans != -1)
    {
        string temp1 = to_string(beg);
        while (temp1 != "-1" && temp1.length() < 5)
            temp1.insert(temp1.begin(), '0');

        string temp2 = to_string(nxt[beg]);
        while (temp2 != "-1" && temp2.length() < 5)
            temp2.insert(temp2.begin(), '0');
        cout << temp1 << " " << val[beg] << " " << temp2 << "\n";

        if (nxt[beg] == -1)
            break;
        beg = nxt[beg];
    }

    while (true)
    {
        string temp1 = to_string(ans);
        while (temp1 != "-1" && temp1.length() < 5)
            temp1.insert(temp1.begin(), '0');

        string temp2 = to_string(nxt[ans]);
        while (temp2 != "-1" && temp2.length() < 5)
            temp2.insert(temp2.begin(), '0');
        cout << temp1 << " " << val[ans] << " " << temp2 << "\n";
        if (nxt[ans] == -1)
            break;
        ans = nxt[ans];
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