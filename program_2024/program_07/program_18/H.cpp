// #include <bits/stdc++.h>
// using intt = long long;
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(nullptr);
//     cin.tie(nullptr);
//     int n, x, y;
//     cin >> n >> x >> y;
//     string s;
//     cin >> s;
//     int l = 0, r = 0;
//     intt ans = 0;
//     if (x == 0 && y == 0)
//     {
//         for (int i = 1; i <= n; i++)
//             ans += i;
//     }
//     else 
//     {
//         int w = 0, a = 0, ss = 0, d = 0;
//         bool f = 1;
//         while (l <= r && r < n && l < n)
//         {
//             if (s[r] == 'W' && f)
//                 w++;
//             else if (s[r] == 'A' && f)
//                 a++;
//             else if (s[r] == 'S' && f)
//                 ss++;
//             else if (s[r] == 'D' && f)
//                 d++;
//             if (x > 0 && y > 0)
//             {
//                 if (d >= abs(x) && w >= abs(y))
//                 {
//                     int dy = w - ss, dx = d - a;
//                     if (dx == x && dy == y)
//                     {
//                         ans += n - r;
//                         int i = l - 1, j = r + 1;
//                         while (i >= 0 && j < n)
//                         {
//                             if (s[i] == 'A' && s[j] == 'D')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'D' && s[j] == 'A')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'W' && s[j] == 'S')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'S' && s[j] == 'W')
//                                 ans++, i--, j++;
//                             else 
//                                 break;
//                         }
//                     }
//                     else 
//                     {
//                         if (s[l] == 'W')
//                             w--;
//                         else if (s[l] == 'A')
//                             a--;
//                         else if (s[l] == 'S')
//                             ss--;
//                         else if (s[l] == 'D')
//                             d--;
//                         l++;
//                         f = 0;
//                         continue;
//                     }
//                 }
//             }
//             else if (x < 0 && y > 0)
//             {
//                 if (a >= abs(x) && w >= abs(y))
//                 {
//                     int dy = w - ss, dx = d - a;
//                     if (dx == x && dy == y)
//                     {
//                         ans += n - r;
//                         int i = l - 1, j = r + 1;
//                         while (i >= 0 && j < n)
//                         {
//                             if (s[i] == 'A' && s[j] == 'D')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'D' && s[j] == 'A')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'W' && s[j] == 'S')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'S' && s[j] == 'W')
//                                 ans++, i--, j++;
//                             else 
//                                 break;
//                         }
//                     }
//                     else 
//                     {
//                         if (s[l] == 'W')
//                             w--;
//                         else if (s[l] == 'A')
//                             a--;
//                         else if (s[l] == 'S')
//                             ss--;
//                         else if (s[l] == 'D')
//                             d--;
//                         l++;
//                         f = 0;
//                         continue;
//                     }
//                 }
//             }
//             else if (x < 0 && y < 0)
//             {
//                 if (a >= abs(x) && ss >= abs(y))
//                 {
//                     int dy = w - ss, dx = d - a;
//                     if (dx == x && dy == y)
//                     {
//                         ans += n - r;
//                         int i = l - 1, j = r + 1;
//                         while (i >= 0 && j < n)
//                         {
//                             if (s[i] == 'A' && s[j] == 'D')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'D' && s[j] == 'A')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'W' && s[j] == 'S')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'S' && s[j] == 'W')
//                                 ans++, i--, j++;
//                             else 
//                                 break;
//                         }
//                     }
//                     else 
//                     {
//                         if (s[l] == 'W')
//                             w--;
//                         else if (s[l] == 'A')
//                             a--;
//                         else if (s[l] == 'S')
//                             ss--;
//                         else if (s[l] == 'D')
//                             d--;
//                         l++;
//                         f = 0;
//                         continue;
//                     }
//                 }
//             }
//             else if (x > 0 && y < 0)
//             {
//                 if (d >= abs(x) && ss >= abs(y))
//                 {
//                     int dy = w - ss, dx = d - a;
//                     if (dx == x && dy == y)
//                     {
//                         ans += n - r;
//                         int i = l - 1, j = r + 1;
//                         while (i >= 0 && j < n)
//                         {
//                             if (s[i] == 'A' && s[j] == 'D')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'D' && s[j] == 'A')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'W' && s[j] == 'S')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'S' && s[j] == 'W')
//                                 ans++, i--, j++;
//                             else 
//                                 break;
//                         }
//                     }
//                     else 
//                     {
//                         if (s[l] == 'W')
//                             w--;
//                         else if (s[l] == 'A')
//                             a--;
//                         else if (s[l] == 'S')
//                             ss--;
//                         else if (s[l] == 'D')
//                             d--;
//                         l++;
//                         f = 0;
//                         continue;
//                     }
//                 }
//             }
//             else if (x == 0)
//             {
//                 if (w >= abs(y))
//                 {
//                     int dy = w - ss;
//                     if (dy == y)
//                     {
//                         ans += n - r;
//                         int i = l - 1, j = r + 1;
//                         while (i >= 0 && j < n)
//                         {
//                             if (s[i] == 'A' && s[j] == 'D')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'D' && s[j] == 'A')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'W' && s[j] == 'S')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'S' && s[j] == 'W')
//                                 ans++, i--, j++;
//                             else 
//                                 break;
//                         }
//                     }
//                     else 
//                     {
//                         if (s[l] == 'W')
//                             w--;
//                         else if (s[l] == 'A')
//                             a--;
//                         else if (s[l] == 'S')
//                             ss--;
//                         else if (s[l] == 'D')
//                             d--;
//                         l++;
//                         f = 0;
//                         continue;
//                     }
//                 }
//             }
//             else if (y == 0)
//             {
//                 if (d >= abs(x))
//                 {
//                     int dx = d - a;
//                     if (dx == x)
//                     {
//                         ans += n - r;
//                         int i = l - 1, j = r + 1;
//                         while (i >= 0 && j < n)
//                         {
//                             if (s[i] == 'A' && s[j] == 'D')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'D' && s[j] == 'A')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'W' && s[j] == 'S')
//                                 ans++, i--, j++;
//                             else if (s[i] == 'S' && s[j] == 'W')
//                                 ans++, i--, j++;
//                             else 
//                                 break;
//                         }
//                     }
//                     else 
//                     {
//                         if (s[l] == 'W')
//                             w--;
//                         else if (s[l] == 'A')
//                             a--;
//                         else if (s[l] == 'S')
//                             ss--;
//                         else if (s[l] == 'D')
//                             d--;
//                         l++;
//                         f = 0;
//                         continue;
//                     }
//                 }
//             }
//             r++;
//             f = 1;
//         }
//     }
//     cout << ans << "\n";
//     return 0;
// }

#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, x, y;
    string s;
    cin >> n >> x >> y >> s;
    vector<pair<int, int>> a(n + 1);
    for (int i = 0; i < n; i++)
    {
        a[i + 1].first += a[i].first;
        a[i + 1].second += a[i].second;
        if (s[i] == 'W')
            a[i + 1].second++;
        else if (s[i] == 'S')
            a[i + 1].second--;
        else if (s[i] == 'D')
            a[i + 1].first++;
        else 
            a[i + 1].first--;
    }
    map<pair<int, int>, int> mp;
    intt ans = 0;
    for (int i = n; i >= 0; i--)
    {
        mp[{a[i].first, a[i].second}] = i;
        if (mp.count({a[i].first + x, a[i].second + y}))
        {
            int j = mp[{a[i].first + x, a[i].second + y}];
            j = max(j, i + 1);
            ans += n - j + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}