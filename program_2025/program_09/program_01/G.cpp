#include <bits/stdc++.h>
using namespace std;

#define Song4u ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pdd pair<double,double>
#define tri tuple<int,int,int>
#define fi first
#define se second
#define inf 0x3f3f3f3f 
#define infll 0x3f3f3f3f3f3f3f3fLL

struct Fenwick
{
    int n;
    vector<int> a;

    Fenwick(int _n) : n(_n), a(_n + 1) {}

    int lowbit(int x)
    {
        return x & -x;
    }

    void update(int x, int k)
    {
        while (x >= 1 && x <= n)
        {
            a[x] += k;
            x += lowbit(x);
        }
    }

    int pre(int r)
    {
        int res = 0;   

        while (r > 0)
        {
            res += a[r];
            r -= lowbit(r);
        }

        return res;
    }

    int query(int l, int r)
    {
        return pre(r) - pre(l - 1);
    }

    int kth(int k)
    {
        int ans = 0;
        for (int p = __lg(n); p >= 0; p--)
        {
            int step = 1ll << p;
            if (ans + step <= n && a[ans + step] < k)
            {
                k -= a[ans + step];
                ans += step;
            }
        }

        return ans + 1;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> id;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    auto val = a;
    sort(val.begin() + 1, val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    for (int i = 1; i < val.size(); i++)
        id[val[i]] = i;
        
    vector<vector<int>> b(n + 1, vector<int>(n + 1));
    for (int l = 1; l <= n; l++)
    {
        // priority_queue<int, vector<int>, less<int>> big;
        // priority_queue<int, vector<int>, greater<int>> small;
        Fenwick fw(n);
        for (int r = l; r <= n; r++)
        {
            fw.update(id[a[r]], 1);
            b[l][r] = val[fw.kth((r - l + 1 + 1) / 2)];
            // if (!big.empty() && big.top() > a[r])
            // {
            //     big.push(a[r]);
            // } else {
            //     small.push(a[r]);
            // }
            // if (!small.empty() && small.size() > big.size() + 1)
            // {
            //     big.push(small.top());
            //     small.pop();
            // } else if (small.size() < big.size()) {
            //     small.push(big.top());
            //     big.pop();
            // }
            // if (small.size() == big.size())
            //     b[l][r] = big.top();
            // else 
            //     b[l][r] = small.top();
        }
    }

    auto check = [&](int x)
    {
        auto g = b;
        vector<int> col(n + 1);
        vector<vector<int>> row(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                if (g[i][j] <= x)
                    g[i][j] = -1;
                else 
                    g[i][j] = 1;
                col[j] += g[i][j];
                row[i][j] = row[i][j - 1] + g[i][j];
            }
        }
        vector<vector<int>> c(n + 1, vector<int>(n + 1));
        c[1][1] = g[1][1];

        int cnt = 0;
        cnt += (c[1][1] <= 0 ? -1 : 1);
        for (int j = 2; j <= n; j++)
        {
            c[1][j] = c[1][j - 1] + col[j];
            cnt += (c[1][j] <= 0 ? -1 : 1);
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                c[i][j] = c[i - 1][j] - (row[i - 1][j] - row[i - 1][i - 2]);
                cnt += (c[i][j] <= 0 ? -1 : 1);
            }
        }

        // vector<vector<int>> tmp(n + 1, vector<int>(n + 1));
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = i; j <= n; j++)
        //     {
        //         vector<int> all;
        //         for (int l = i; l <= j; l++)
        //         {
        //             for (int r = l; r <= j; r++)
        //             {
        //                 all.push_back(b[l][r]);
        //             }
        //         }

        //         sort(all.begin(), all.end());
        //         tmp[i][j] = all[(all.size() - 1) / 2];
        //     }
        // }

        // cout << "m: " << x << "\n";
        // cout << "B: \n";
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         cout << b[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "Real C: \n";
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         cout << tmp[i][j] << " "; 
        //     }
        //     cout << "\n";
        // }
        // cout << "G: \n";
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         cout << g[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        // cout << "C: \n";
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         cout << c[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        return cnt <= 0;
    };

    int l = 1, r = 1e9 + 10;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid + 1;
    }

    cout << l << "\n";
}

int main()
{
    Song4u
    
    int Test_number = 1;
    // cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}

