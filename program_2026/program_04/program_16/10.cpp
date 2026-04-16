#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct node
{
    int prev = 0, nxt = 0;
    i64 val;
};

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n);
    vector<node> b(n);
    map<int, vector<int>> id;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        id[a[i]].push_back(i);
        b[i] = {i - 1, i + 1, a[i]};
    }
    b[0].prev = n - 1;
    b[n - 1].nxt = 0;
    
    i64 ans = 0, cnt = 0;
    for (auto &[val, v] : id)
    {
        for (auto idx : v)
        {
            if (cnt < n - 1)
            {
                ans += min(b[b[idx].prev].val, b[b[idx].nxt].val);
                b[b[idx].prev].nxt = b[idx].nxt;
                b[b[idx].nxt].prev = b[idx].prev;
                cnt++;
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}