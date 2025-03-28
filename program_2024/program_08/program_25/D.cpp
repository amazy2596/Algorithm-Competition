#include <bits/stdc++.h>
#define int long long
using namespace std;

int k, b;

int get(int x1, int y1)
{
    return y1 - (k * x1 + b);
}

void solve()
{
    int n;
    cin >> n >> k >> b;
    vector<pair<pair<int, int>, int>> above, below, onLine;
    
    for (int i = 0; i < 2 * n; i++) {
        int x, y;
        cin >> x >> y;
        int d = get(x, y);
        if (d > 0)
            above.push_back(make_pair(make_pair(x, y), i + 1));
        else if (d < 0)
            below.push_back(make_pair(make_pair(x, y), i + 1));
        else 
            onLine.push_back(make_pair(make_pair(x, y), i + 1));
    }
    
    vector<pair<pair<int, int>, char>> ans;
    int m = 0;
    
    int i = 0, j = 0;
    while (i < above.size() && j < below.size()) {
        int t1 = above[i].second, t2 = below[j].second;
        ans.push_back(make_pair(make_pair(t1, t2), 'Y'));
        m++;
        i++, j++;
    }
    
    int k = 0;
    while (i < above.size() && k < onLine.size()) {
        int t1 = above[i].second, t2 = onLine[k].second;
        ans.push_back(make_pair(make_pair(t1, t2), 'Y'));
        m++;
        i++, k++;
    }
    while (j < below.size() && k < onLine.size()) {
        int t1 = below[j].second, t2 = onLine[k].second;
        ans.push_back(make_pair(make_pair(t1, t2), 'Y'));
        m++;
        j++, k++;
    }

    while (i < above.size()) {
        if (i + 1 < above.size()) {
            ans.push_back(make_pair(make_pair(above[i].second, above[i + 1].second), 'N'));
            i += 2;
        }
    }
    while (j < below.size()) {
        if (j + 1 < below.size()) {
            ans.push_back(make_pair(make_pair(below[j].second, below[j + 1].second), 'N'));
            j += 2;
        }
    }
    while (k < onLine.size()) {
        if (k + 1 < onLine.size()) {
            ans.push_back(make_pair(make_pair(onLine[k].second, onLine[k + 1].second), 'Y'));
            k += 2;
            m++;
        }
    }

    cout << m << "\n";
    for (auto &p : ans) {
        cout << p.first.first << " " << p.first.second << " " << p.second << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    int T = 1;
    while (T--) {
        solve();
    }
    
    return 0;
}
