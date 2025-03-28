#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if (s.length() == 1)
    {
        int temp = s[0] - '0';
        if (temp % 4 == 0)
            cout << 0 << "\n";
        else 
            cout << -1 << "\n";
        return 0;
    }
    vector<int> a;
    for (int i = 0; i < s.length(); i++)
        a.push_back(s[i] - '0');
    int n = a.size();
    int num = a[n - 2] * 10 + a[n - 1];
    if (num % 4 == 0 || num == 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    num = a[n - 1] * 10 + a[0];
    if (num % 4 == 0 || num == 0)
    {
        cout << 1 << "\n";
        return 0;
    }
    for (int i = 1; i < a.size(); i++)
    {
        num = a[i - 1] * 10 + a[i];
        if (num % 4 == 0 || num == 0)
        {
            cout << i + 1 << "\n";
            return 0;
        }
        if (i == a.size() - 1)
        {
            cout << -1 << "\n";
            return 0;
        }
    }
    return 0;
}