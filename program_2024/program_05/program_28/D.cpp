#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int get_result(double temp)
{
    int sum = 0;
    string s = to_string(temp);
    if (s[s.find('.') + 1] <= '4')
        sum = temp;
    else 
        sum = temp + 1;
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    double temp = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], temp += a[i];
    sort(a.begin(), a.end());
    if (get_result(temp / n) == 5)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        temp += 5 - a[i];
        if (get_result(temp / n) == 5)
        {
            cout << i + 1;
            break;
        }
    }
    return 0;
}