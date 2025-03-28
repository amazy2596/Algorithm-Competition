#include <bits/stdc++.h>
using intt = long long;
using namespace std;

intt sum = 0, a[10];
vector<int> idx;
bool check[10], ok = 0;

void calc(int x)
{
    if (idx.size() == 3)
    {
        intt temp1 = sum, temp2 = 0;
        for (int i = 0; i < idx.size(); i++)   
        {
            temp1 -= a[idx[i]];
            temp2 += a[idx[i]];
        }
        if (temp1 == temp2)
        {
            ok = 1;
            return;
        }
    }
    for (int i = 1; i <= 6; i++)
    {
        if (check[i])
            continue;
        idx.push_back(i);
        check[i] = 1;
        calc(x + 1);
        idx.pop_back();
        check[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    for (int i = 1; i <= 6; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    calc(1);
    if (ok) 
        cout << "YES\n";
    else 
        cout << "NO\n";
    return 0;
}