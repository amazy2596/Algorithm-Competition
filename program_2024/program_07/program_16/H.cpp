#include <bits/stdc++.h>
using intt = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    // int n,m;
    // char a1[100100][11],a2[100100][11];
    // intt b[100100],c[100100];
    // cin>>n;
    // for(int i=1;i<=n;i++)
    // {
    //     scanf("%s",&a1[i][]);
    //     cin>>b[i]>>c[i];
    // }
    //  cin>>m;
    // for(int i=1;i<=m;i++)
    // {
    //     scanf("%s",&a2[i][]);
    //     cin>>b[i]>>c[i];
    // }
    int n;
    cin >> n;
    map<string, pair<int, int>> first_contest, second_contest;
    pair<int, int> st, ed;
    for (int i = 0; i < n; i++)
    {
        string s;
        int solve, time;
        cin >> s >> solve >> time;
        if (s == "lzr010506")
            st.first = solve, st.second = time;
        else 
            first_contest[s] = {solve, time};
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string s;
        int solve, time;
        cin >> s >> solve >> time;
        if (s == "lzr010506")
            ed.first = solve, ed.second = time;
        else 
        {
            if (first_contest.find(s) != first_contest.end())
                first_contest.erase(s);
            else 
                second_contest[s] = {solve, time};
        }
    }
    int fir = 1, sed = 1;
    for (auto [s, val] : first_contest)
    {
        if (val.first > st.first)
            fir++;
        else if (val.first == st.first && val.second < st.second)
            fir++;
    }
    for (auto [s, val] : second_contest)
    {
        if (val.first > ed.first)
            sed++;
        else if (val.first == ed.first && val.second < ed.second)
            sed++;
    }
    cout << min(fir, sed);
    return 0;
}