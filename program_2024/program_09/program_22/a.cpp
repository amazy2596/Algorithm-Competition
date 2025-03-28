#include <bits/stdc++.h>
#define int long long
using namespace std;

struct compare
{
    bool operator()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
    {
        return a.first + a.second.second > b.first + b.second.second;
    }
};

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> q;
        int n = workerTimes.size();
        for (int i = 0; i < n; i++)
            q.push({workerTimes[i], {workerTimes[i], 0}});
        while (mountainHeight--)
        {
            auto top = q.top();
            q.pop();
            top.second.second += top.first;
            top.first += top.second.first;
            q.push(top);
        }
        int ans = 0;
        while (!q.empty())
        {
            auto top = q.top();
            q.pop();
            ans = max(ans, top.second.second);
        }
        return ans;
    };
};

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Solution s;
    cout << s.minNumberOfSeconds(m, a) << "\n";
    return 0;
}