#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n <= 2)
        cout << -1;
    else 
    {
        set<int> s;
        for (int i = 1; i <= n; i++)
            s.insert(i);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s.count(j) && abs(i - j) % 2 == 0 && (i + j) % 2 == 0 && i != j)
                {
                    cout << j << " ";
                    s.erase(j);
                }
            }
        }
    }
    return 0;
}