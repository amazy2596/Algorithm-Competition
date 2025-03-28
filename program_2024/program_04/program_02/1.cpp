#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool flag = 1;
    while (flag)
    {
        flag = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                flag = 1;
                swap(a[i], a[i + 1]);
            }
        }
    }
    int x;
    cin >> x;
    a.insert(upper_bound(a.begin(), a.end(), x), x);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}