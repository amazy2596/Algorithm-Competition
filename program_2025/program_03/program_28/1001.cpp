#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct node
{
    int ehq, hurt, idx;
};

void solve()
{
    int n, u, k, hq;
    cin >> n >> u >> k >> hq;
    vector<int> hurt(n), ehq(n), mx_count(n);
    for (int i = 0; i < n; i++)
        cin >> hurt[i] >> ehq[i];

    if (u == 1)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (ehq[i] == 1)
                ans++;
        cout << ans << "\n";
        return;
    }

    vector<node> temp;
    for (int i = 0; i < n; i++)
        temp.push_back({ehq[i], hurt[i], i});
    
    sort(temp.begin(), temp.end(), [&](node a, node b){
        if (a.ehq == b.ehq && a.hurt == b.hurt)
            return a.idx < b.idx;
        else if (a.ehq == b.ehq)
            return a.hurt < b.hurt;

        return a.ehq < b.ehq;
    });

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (temp[i].ehq <= u)
            mx_count[temp[i].idx] = count++;
        else 
        {
            int need = 1 + ceil((temp[i].ehq - u) * 1.0 / (u / 2));
            if (need > k)
            {
                mx_count[temp[i].idx] = 1e16;
                count += k;
            }
            else 
            {
                mx_count[temp[i].idx] = count + need;
                count += need;
            }
        }
    }

    int left = 1;
    priority_queue<pair<int, int>> que;
    for (int i = 0; i < n; i++)
        que.push({hurt[i], mx_count[i]});

    vector<pair<int, pair<int, int>>> segment;
    while (!que.empty())
    {
        auto [hurt, count] = que.top();
        que.pop();

        if (count > left)
            segment.push_back({hurt, {left, count}}), left = count + 1;
    }

    auto check = [&](int count)
    {
        int sum = 0;
        for (auto [hurt, p] : segment)
        {
            auto [l, r] = p;
            if (count <= r)
                sum += hurt * (count - l + 1);
            else 
                sum += hurt * (r - l + 1);
        }
        
        return sum;
    };
    
    int l = 0, r = 1e16;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid) > hq)
            r = mid;
        else 
            l = mid + 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mx_count[i] <= l)
            ans++;
    }

    cout << ans << "\n";
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