#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int p[5][9] = 
{
    {1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,1,0,1},
    {1,0,0,1,1,1,1,1,0},
    {1,0,0,0,0,1,1,0,0},
    {1,1,1,1,1,1,1,0,0},
};

void solve()
{
    int n, L;
    cin >> n >> L;
    vector<vector<int>> mt(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mt[i][j];
        }
    }
    
    vector<int> ans(L + 2);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + 4 >= n || j + 8 >= n) continue;
            int max_b = -1e9, min_w = 1e9;
            for (int x = i; x < i + 5; x++)
            {
                for (int y = j; y < j + 9; y++)
                {
                    int px = x - i, py = y - j;
                    if (p[px][py] == 1) min_w = min(min_w, mt[x][y]);
                    else max_b = max(max_b, mt[x][y]);
                }
            }
            if (max_b > min_w) continue;
            ans[max_b + 1]++;
            ans[min_w + 1]--;
        }
    }

    for (int i = 1; i <= L; i++) ans[i] += ans[i - 1];
    for (int i = 0; i < L; i++) 
    {
        if (ans[i] > 0)
        {
            cout << i << "\n";
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	// cin >> T;
	while (T--) solve();
	return 0;
}