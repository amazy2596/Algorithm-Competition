#include <bits/stdc++.h>
using intt = long long;
using namespace std;

vector<int> a;
vector<bool> vis;
int beg = -1, siz = 0;

void find(int x)
{
    vis[x] = 1;
    if (a[x] != beg)
    {
        x = a[x];
        siz++;
        find(x);
    }
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int num = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if(vis[i] || a[i] == i)
        {
            vis[i]=1;
             continue;
        }
        vis[i] = 1;
        beg = i;
        siz = 1;
        find(i);
        if (siz == 2)
            num++;
        else if(siz<=4)
            ans++;
        else if(siz%3==2)
        {
            num++;
            ans+=(siz+1)/3-1;
        }
        else 
            {
                ans+=(siz+1)/3;  //ans++;  //ans+=ceil(siz*1.0/4);
            }
          
    }
    ans+=ceil(num * 1.0 / 2);//ans+=ceil(num * 1.0 / 2);
    cout << ans << "\n";
    ans=0;
    num=0;
    siz=0;
    beg=-1;
    for (int i = 1; i <= n; i++)
    {
        vis[i]=0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    intt t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}