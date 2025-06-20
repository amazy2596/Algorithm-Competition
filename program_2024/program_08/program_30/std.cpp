#include <iostream>
#include <system_error>
#include <vector>
using namespace std;
 
int qry(int a, int b){
    cout << "? " << a+1 << ' ' << b+1 << endl;
    fflush(stdout);
    int r; cin >> r;
    return r-1;
}
 
void solve(){
    int N; cin >> N;
    vector<int> in_tree(N, 0), stk;
    for (size_t i = 1; i < N; ++i)
        stk.push_back(i);
    in_tree[0] = 1;
 
    vector<pair<int, int>> edges;
 
    while(!stk.empty()){
        int n = stk.back();
        stk.pop_back();
        if(in_tree[n])continue;
        int l = 0, r = n;
        while(1){
            int q = qry(l, r);
            if(q == l){
                in_tree[r] = 1;
                edges.push_back({l, r});
                break;
            }
            if(in_tree[q])l = q;
            else r = q;
        }
        stk.push_back(n);
    }
    cout << "! ";
    for(auto [x, y]: edges)cout << x+1 << ' ' << y+1 << ' ';
    cout << endl;
}
 
int main(){
    int t; cin >> t;
    while(t--)solve();
}

