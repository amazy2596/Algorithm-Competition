#include <bits/stdc++.h>
using intt = long long;
using namespace std;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    int num = 0;
    vector<int> h(n), a;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        if (h[i] < 3)
            num++;
        else 
            a.push_back(h[i]);
    }
    intt cir = ceil((n - r) * 1.0 / (r - l));
    sort(h.begin(), h.end(), greater<int>());
    for (int i = 0; i < h.size(); i++)
    
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    solve();
    return 0;
}