#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (k > n || k == 1)
        cout << -1;
    else 
    {
        for (int i = 1; i < k; i++)
            cout << a[i] << " ";
        cout << a[0] << " "; 
        for (int i = k; i < n; i++)
        cout << a[i] << " ";
    }
    return 0;
}