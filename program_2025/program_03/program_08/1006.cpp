#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<int> getCandidates(int u, int v, int w) 
{
    vector<int> cand;
    auto checkCandidate = [&](int a, int b, int c) 
    {
        if(a == 0) return;
        if((c - b) % a != 0) return;
        int x = (c - b) / a;
        if(x >= 0)
            cand.push_back(x);
    };
    checkCandidate(u, v, w);  
    checkCandidate(u, w, v);  
    checkCandidate(v, u, w);
    checkCandidate(v, w, u);  
    checkCandidate(w, u, v);
    checkCandidate(w, v, u);
    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());
    return cand;
}

void solve() 
{
    int n;
    cin >> n;
    int u, v, w;
    cin >> u >> v >> w;
    vector<int> curr = getCandidates(u, v, w);
    
    for (int i = 1; i < n; i++) 
    {
        cin >> u >> v >> w;
        vector<int> temp = getCandidates(u, v, w);
        vector<int> next;
        for (int x : curr) 
        {
            for (int y : temp) 
            {
                if (x == y) 
                {
                    next.push_back(x);
                    break;
                }
            }
        }
        curr = move(next);
    }
    
    cout << curr[0] << "\n";
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