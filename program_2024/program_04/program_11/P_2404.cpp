#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int n, temp = 0, tot = 0;
vector<int> cnt;
vector<string> ans;

void dfs(int x)
{
    if (temp == n && cnt.size() >= 2)
    {
        ans.push_back("");
        for (int i = 0; i < cnt.size(); i++)
        {
            ans[tot] += to_string(cnt[i]);
            if (i != cnt.size() - 1)
                ans[tot] += "+";
        }
        tot++;
    }
    for (int i = x; i < n && temp < n; i++)
    {
        temp += i;
        cnt.push_back(i);
        dfs(i);
        temp -= i;
        cnt.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n;
    dfs(1);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
    return 0;
}