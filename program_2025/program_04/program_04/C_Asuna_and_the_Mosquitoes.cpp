#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> odds, evens;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 1)
            odds.push_back(x);
        else 
            evens.push_back(x), sum += x;
    }

    if (odds.size() && evens.size())
    {
        int ans = 0;
        priority_queue<int> q_mx;
        priority_queue<int, vector<int>, greater<int>> q_mn;
        for (int i = 0; i < odds.size(); i++)
            q_mx.push(odds[i]);
        for (int i = 0; i < evens.size(); i++)
            q_mn.push(evens[i]);

        while (!q_mx.empty() && !q_mn.empty())
        {
            auto odd = q_mx.top();
            auto even = q_mn.top();
            if (odd == 1)
                break;
            q_mx.pop(), q_mn.pop();
            
            q_mx.push(1);
            q_mn.push(odd + even - 1);
        }
        
        while (!q_mn.empty())
        {
            ans += q_mn.top();
            q_mn.pop();
        }

        cout << ans + (!q_mx.empty()) << "\n";
    }
    else if (odds.size())
        cout << *max_element(odds.begin(), odds.end()) << "\n";
    else 
        cout << *max_element(evens.begin(), evens.end()) << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}