#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };



void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    map<int, pair<int,int>> ev;

    for (auto& [l, r] : a) 
    {
        cin >> l >> r;
        int w = l + r;
        ev[l].first  += w;
        ev[r + 1].first  -= w;
        ev[l].second += 1;
        ev[r + 1].second -= 1;
    }

    int mx = -inf;       
    int idx =  inf;      
    int curW = 0;        
    int curCnt = 0;      

    for (auto& [x, pr] : ev) 
    {
        curW  += pr.first;
        curCnt+= pr.second;
        if (curCnt > 0) 
        {
            if (curW > mx || (curW == mx && x < idx)) 
            {
                mx  = curW;
                idx = x;
            }
        }
    }

    cout << idx << "\n";
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