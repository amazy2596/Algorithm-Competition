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
    for (int i = 0; i < n; i++)
    {
        int ith = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[ith])
                ith = j;
        }
        swap(a[ith], a[i]);
    }
    int x;
    cin >> x;
    a.insert(upper_bound(a.begin(), a.end(), x), x);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}