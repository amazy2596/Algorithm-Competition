#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<intt> a(n + 1), b(n + 1), prefixsum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefixsum[i] = prefixsum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    while (q--)
    {
        int k;
        cin >> k;
        priority_queue<int> p;
        intt b_sum = 0;
        for (int i = 1; i <= k; i++)
            p.push(b[i]), b_sum += b[i];
        intt ans = prefixsum[k] + b_sum;
        for (int i = k + 1; i <= n; i++)
        {
            if (b[i] < p.top())
            {
                b_sum -= p.top();
                p.pop();
                p.push(b[i]);
                b_sum += b[i];
                ans = min(ans, prefixsum[i] + b_sum);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}