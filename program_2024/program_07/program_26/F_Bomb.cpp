#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    auto get = [&](int x)
    {
        int sum = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= x)
            {
                int t = (a[i] - x) / b[i] + 1;
                cnt += t;
                sum += a[i] * t - (t * (t - 1) / 2) * b[i];
            }
        }
        return pair<int, int> {cnt, sum};
    };
    int l = 0, r = 1e10;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (get(mid).first <= k)
            r = mid;
        else 
            l = mid + 1;
    }
    auto [cnt, sum] = get(l);
    if (l > 0)
        sum += (k - cnt) * (l - 1);
    cout << sum << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

// #include <bits/stdc++.h>
// using intt = long long;
// using namespace std;

// void solve()
// {
//     intt n, k;
//     cin >> n >> k;
//     vector<pair<intt, intt>> p(n);
//     priority_queue<pair<intt, intt>> q;
//     for (int i = 0; i < n; i++)
//         cin >> p[i].first;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> p[i].second;
//         q.push(make_pair(p[i].first, p[i].second));
//     }
//     intt ans = 0;
//     while (k)
//     {
//         auto [a1, b1] = q.top();
//         q.pop();
//         if (a1 == 0)
//             break;
//         auto [a2, b2] = q.top();
//         intt l = 0, r = 1e6;
//         while (l < r)
//         {
//             intt mid = (l + r) >> 1;
//             if (a1 - mid * b1 < a2)
//                 r = mid;
//             else 
//                 l = mid + 1;
//         }
//         if (l < k)
//         {
//             ans += l * a1;
//             ans -= (l * (l - 1) / 2) * b1;
//             k -= l;
//             q.push(make_pair(max(0ll, a1 - l * b1), b1));
//         }
//         else 
//         {
//             ans += k * a1;
//             ans -= (k * (k - 1) / 2) * b1;
//             break;
//         }
//     }
//     cout << ans << "\n";
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(nullptr);
//     cin.tie(nullptr);
//     intt t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }
