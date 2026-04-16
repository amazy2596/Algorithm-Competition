#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

struct node
{
    i64 s;
    vector<i64> p;
    i64 sum = 0;
    int idx;

    bool operator<(node o)
    {
        return s < o.s;
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<node> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].s;
        a[i].p.resize(m);
        for (int j = 0; j < m; j++) 
        {
            cin >> a[i].p[j];
            if (a[i].p[j] != -1) a[i].sum += a[i].p[j];
        }
        a[i].idx = i;
    }

    sort(a.rbegin(), a.rend());
    for (int j = 0; j < m; j++)
    {
        if (a[0].p[j] == -1)
        {
            a[0].p[j] = k;
            a[0].sum += k;
        }
    }

    for (int i = 1; i < n; i++)
    {
        i64 tar = a[i - 1].sum;
        for (int j = 0; j < m; j++)
        {
            if (a[i - 1].s > a[i].s)
            {
                if (a[i - 1].sum <= a[i].sum)
                {
                    cout << "No\n";
                    return;
                }
                if (a[i].p[j] == -1)
                {
                    if (a[i].sum + k < tar)
                    {
                        a[i].p[j] = k;
                        a[i].sum += k;
                    }
                    else 
                    {
                        a[i].p[j] = tar - a[i].sum - 1;
                        a[i].sum += tar - a[i].sum - 1;
                    }
                }
            }
            else if (a[i - 1].s == a[i].s)
            {
                if (a[i - 1].sum < a[i].sum)
                {
                    cout << "No\n";
                    return;
                }
                if (a[i].p[j] == -1)
                {
                    if (a[i].sum + k <= tar)
                    {
                        a[i].p[j] = k;
                        a[i].sum += k;
                    }
                    else 
                    {
                        a[i].p[j] = tar - a[i].sum;
                        a[i].sum += tar - a[i].sum;
                    }
                }
            }
        }
    }

    vector<node> ans(n);
    for (int i = 0; i < n; i++) ans[a[i].idx] = a[i];
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i].p[j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}