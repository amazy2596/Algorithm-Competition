#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int N = n + m + 1;
        vector<intt> a(N), b(N), ans(N);
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 0; i < N; i++)
            cin >> b[i];
        int t = 0;
        int x = 0, y = 0;
        intt sum = 0;
        while (x < n && y < m)
        {
            if (a[t] > b[t])
            {
                sum += a[t];
                x++;    
            }
            else 
            {
                sum += b[t];
                y++;
            }
            t++;
        }
        intt res = sum;
        for (int i = t; i < N; i++)
            res += x == n ? b[i] : a[i];
        for (int i = t; i < N; i++)
            ans[i] = res - (x == n ? b[i] : a[i]);
        for (int i = 0; i < t; i++)
            if ((x == n) == (a[i] < b[i]))
                ans[i] = res - max(a[i], b[i]);
        int ox = x, ot = t;
        if (x == n)
            x--;
        else 
            y--;
        while (x < n && y < m)
        {
            if (a[t] > b[t])
            {
                sum += a[t];
                x++;    
            }
            else 
            {
                sum += b[t];
                y++;
            }
            t++;
        }
        res = sum;
        for (int i = t; i < N; i++)
            res += x == n ? b[i] : a[i];

        for (int i = 0; i < ot; i++)
            if ((ox == n) == (a[i] > b[i]))
                ans[i] = res - max(a[i], b[i]);
        
        for (int i = 0; i < N; i++)
            cout << ans[i] << " \n"[i == N - 1];
    }
    return 0;
}