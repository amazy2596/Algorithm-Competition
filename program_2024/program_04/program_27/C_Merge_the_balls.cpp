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
    stack<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i > 0)
        {
            if (a.top() != x)
                a.push(x);
            else 
            {
                while (!a.empty() && a.top() == x)
                {
                    int y = a.top();
                    a.pop();
                    x++;
                }
                a.push(x);
            }
        }
        else 
            a.push(x);
    }
    cout << a.size();
    return 0;
}