#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
string l, r;
vector<int> r1, r2, rr, l1, l2;

vector<int> mul(vector<int> &a, vector<int> &b)
{
    vector<int> res(a.size() + b.size() + 5);
    // reverse(a.begin(), a.end());
    // reverse(b.begin(), b.end());
    for (int i = 0, k = 0; i < a.size(); i++, k++)
    {
        for (int j = 0; j < b.size(); j++)
            res[j + k] += a[i] * b[j];
    }
    int t = 0;
    for (int i = 0; i < res.size() - 1; i++)
    {
        res[i] += t;
        t = res[i] / 10;
        if (res[i] >= 10)
            res[i] %= 10;
    }
    while (res.back() == 0 && res.size() > 1)
        res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

bool compare(vector<int> a, vector<int> b)
{
    if (a.size() > b.size())
        return 1;
    else if (a.size() < b.size())
        return 0;
    for (int i = 0; i < a.size(); i++)    
    {
        if (a[i] > b[i])
            return 1;
        else if (a[i] < b[i])
            return 0;
    }
    return 1;
}

vector<int> high_l, high_r, low_l, low_r, high;

void dfs_1(int x)
{
    if (x == 0)
        return;
    for (int i = 9; i >= 0; i--)
    {
        high_l[x - 1] = i;
        if (compare(r1, mul(high_l, high_l)))
        {
            dfs_1(x - 1);
            return;
        }
    }
}

void dfs_2(int x)
{
    if (x == 0)
        return;
    for (int i = 9; i >= 0; i--)
    {
        high_r[x - 1] = i;
        if (compare(r2, mul(high_r, high_r)))
        {
            dfs_2(x - 1);
            return;
        }
    }
}

void dfs_3(int x)
{
    if (x == 0)
        return;
    for (int i = 0; i <= 9; i++)
    {
        low_l[x - 1] = i;
        if (compare(mul(low_l, low_l), l1))
        {
            dfs_3(x - 1);
            return;
        }
    }
}

void dfs_4(int x)
{
    if (x == 0)
        return;
    for (int i = 0; i <= 9; i++)
    {
        low_r[x - 1] = i;
        if (compare(mul(low_r, low_r), l2))
        {
            dfs_4(x - 1);
            return;
        }
    }
}

void dfs_5(int x)
{
    if (x == 0)
        return;
    for (int i = 9; i >= 0; i--)
    {
        high[x - 1] = i;
        if (compare(rr, mul(high, high)))
        {
            dfs_5(x - 1);
            return;
        }
    }
}

int to(vector<int> a)
{
    int res = 0;
    for (int i = a.size() - 1, j = 0; i >= 0; i--, j++)
        res += a[i] * pow(10, j);
    return res;
}

vector<int> remove(vector<int> a)
{
    reverse(a.begin(), a.end());
    while (a.back() == 0 && a.size() > 1)
        a.pop_back();
    reverse(a.begin(), a.end());
    return a;
}

void solve()
{
    cin >> n;
    cin >> l >> r;
    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
        {
            l1.push_back(l[i] - '0');
            r1.push_back(r[i] - '0');
        }
        else 
        {
            l2.push_back(l[i] - '0');
            r2.push_back(r[i] - '0');
            rr.push_back('9');
        }
    }
    l1 = remove(l1);
    r1 = remove(r1);
    l2 = remove(l2);
    r2 = remove(r2);
    int num = ceil(n * 1.0 / 4);
    high_l.resize(num);
    high_r.resize(num);
    high.resize(num);
    low_l.resize(num, 9);
    low_r.resize(num, 9);
    dfs_1(num);
    dfs_2(num);
    dfs_3(num);
    dfs_4(num);
    dfs_5(num);
    reverse(high_l.begin(), high_l.end());
    reverse(high_r.begin(), high_r.end());
    reverse(low_l.begin(), low_l.end());
    reverse(low_r.begin(), low_r.end());
    reverse(high.begin(), high.end());
    // for (int i = 0; i < high_l.size(); i++)
        // cout << high_l[i];
    // cout << endl;
    // for (int i = 0; i < high_r.size(); i++)
        // cout << high_r[i];
    // cout << endl;
    // for (int i = 0; i < low_l.size(); i++)
        // cout << low_l[i];
    // cout << endl;
    // for (int i = 0; i < low_r.size(); i++)
        // cout << low_r[i];
    // cout << endl;
    // for (int i = 0; i < high.size(); i++)
        // cout << high[i];
    int ll1 = to(low_l), ll2 = to(low_r), rr1 = to(high_l), rr2 = to(high_r), rr3 = to(high);
    int cnt_1 = rr2 - ll2 + 1, cnt_2 = rr1 - ll1, cnt_3 = rr3 - ll2 + 1;
    // cout << (rr2 - ll2 + 1) + (rr1 - ll1) * (rr3 - ll2 + 1) << "\n";
    cout << cnt_1 + cnt_2 * cnt_3 << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}