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
    vector<int> a(n + 1);
    for (int i = n; i >= 0; i--)
        cin >> a[i];
    string s;
    for (int i = n; i >= 0; i--)
    {
        if (a[i] > 0)
        {
            s += "+";
            if (a[i] != 1 || i == 0)
                s += to_string(a[i]);
            if (i == 1)
                s += "x";
            else if(i != 0)
            {
                s += "x^";
                s += to_string(i);
            }
        }
        else if (a[i] < 0)
        {
            s += "-";
            if (a[i] != -1 || i == 0)
                s += to_string(abs(a[i]));
            if (i == 1)
                s += "x";
            else if (i != 0)
            {
                s += "x^";
                s += to_string(i);
            }
        }
    }
    for (int i = (s[0] == '+' ? 1 : 0); i < s.length(); i++)
        cout << s[i];
    return 0;
}