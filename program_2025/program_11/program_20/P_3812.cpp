// Problem: 【模板】线性基
// URL: https://www.luogu.com.cn/problem/P3812
// Author: amazy
// Date: 2025-11-20 18:08:16

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

struct LinearBasis
{
    int bits;
    vector<i64> basis;

    LinearBasis (int _bits) : bits(_bits)
    {
        basis.resize(bits + 1);
    }

    bool insert(i64 x)
    {
        for (int i = bits - 1; i >= 0; i--)
        {
            if (!(x >> i & 1))
                continue;

            if (basis[i])
                x ^= basis[i];
            else 
            {
                basis[i] = x;
                return true;
            }
        }

        return false;
    }

    bool exist(i64 x)
    {
        for (int i = bits - 1; i >= 0; i--)
        {
            if (!(x >> i & 1))
                continue;
            
            x ^= basis[i];
        }

        return x == 0;
    }

    i64 queryMIN()
    {
        for (int i = 0; i < bits; i++)
        {
            if (basis[i] != 0)
                return basis[i];
        }
        
        return 0;
    }

    i64 queryMAX()
    {
        i64 res = 0;
        for (int i = bits - 1; i >= 0; i--)
        {
            if (basis[i] == 0)
                continue;

            if (!((res >> i) & 1))
                res ^= basis[i];
        }

        return res;
    }
};

void solve()
{
    int n;
    cin >> n;
    LinearBasis lb(64);
    for (int i = 0; i < n; i++)
    {
        i64 x;
        cin >> x;
        lb.insert(x);
    }

    cout << lb.queryMAX() << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}