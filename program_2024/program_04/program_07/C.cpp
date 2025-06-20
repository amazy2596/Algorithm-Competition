#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, p, ans = 0;
    cin >> n >> p;
    vector<int> check(p, 0);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        check[temp % p]++;
    }
    if (check[0])
        cout << 1;
    else if (check[1] && check[2])
        cout << 2;
    else    
        cout << 3;
    return 0;
}