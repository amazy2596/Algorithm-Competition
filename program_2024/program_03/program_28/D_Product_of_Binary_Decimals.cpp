#include <bits/stdc++.h>
using intt = long long;
using namespace std;

const int N = 1e5;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    vector<intt> num(30), ans;
    num = {10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1100, 1110, 1101, 1011, 1111, 10001, 10010, 10100, 11000, 11100, 11010, 11001, 10110, 10101, 10011, 11110, 11101, 11011, 10111, 11111, 100000};
    ans.push_back(1);
    ans.push_back(0);
    for (int i = 0; i < 30; i++)
        ans.push_back(num[i]);
    for (int i = 0; i < 30; i++)
        for (int j = i; j < 30; j++)
            if (num[i] * num[j] <= N)
                ans.push_back(num[i] * num[j]);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i = 0; i < 30; i++)
        for (int j = i; j < 30; j++)
            for (int k = j; k < 30; k++)
                if (num[i] * num[j] * num[k] <= N)
                    ans.push_back(num[i] * num[j] * num[k]);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i = 0; i < 30; i++)
        for (int j = i; j < 30; j++)
            for (int k = j; k < 30; k++)
                for (int l = k; l < 30; l++)
                    if (num[i] * num[j] * num[k] * num[l] <= N && num[i] * num[j] * num[k] * num[l] >= 0)
                        ans.push_back(num[i] * num[j] * num[k] * num[l]);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i = 0; i < 30; i++)
        for (int j = i; j < 30; j++)
            for (int k = j; k < 30; k++)
                for (int l = k; l < 30; l++)
                    for (int r = l; r < 30; r++)
                        if (num[i] * num[j] * num[k] * num[l] * num[r] <= N && num[i] * num[j] * num[k] * num[l] * num[r] >= 0)
                            ans.push_back(num[i] * num[j] * num[k] * num[l] * num[r]);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    intt t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool ok = 1;
        if (n % 10 != 1 && n % 10 != 0)
            ok = 0;
        else 
        {
            int l = 0, r = ans.size();
            while (l < r)
            {
                int mid = (r + l) >> 1;
                if (ans[mid] >= n)
                    r = mid;
                else 
                    l = mid + 1;
            }
            if (ans[l] != n)
                ok = 0;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}