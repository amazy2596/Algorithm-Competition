#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n, na, nb;
    cin >> n >> na >> nb;
    vector<int> a(na), b(nb);
    for (int i = 0; i < na; i++)
        cin >> a[i];
    for (int i = 0; i < nb; i++)
        cin >> b[i];
    vector<vector<int>> vec = {{0, 0, 1, 1, 0}, {1, 0, 0, 1, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 0, 1}, {1, 1, 0, 0, 0}};
    int ans_a = 0, ans_b = 0;
    for (int i = 0; i < n; i++)
    {
        ans_a += vec[a[i % na]][b[i % nb]];
        ans_b += vec[b[i % nb]][a[i % na]];
    }
    cout << ans_a << " " << ans_b;
    return 0;
}