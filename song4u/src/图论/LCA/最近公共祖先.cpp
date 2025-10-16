// //倍增版
// const int N = 5e5+10;
// int n,m,s;
// vector<int> gra[N];
// int dep[N],fa[N][20];

// void dfs(int u,int pa){
//     dep[u] = dep[pa] + 1;

//     fa[u][0] = pa;
//     for(int i = 1;i<=19;i++){
//         fa[u][i] = fa[fa[u][i-1]][i-1];
//     }

//     for(auto x : gra[u]){
//         if(x!=pa) dfs(x,u);
//     }
// }

// int lca(int u,int v){
//     if(dep[u]<dep[v]) swap(u,v);

//     for(int i = 19;i>=0;i--){
//         if(dep[fa[u][i]] >= dep[v]) u = fa[u][i];
//     }

//     if(u==v) return v;

//     for(int i = 19;i>=0;i--){
//         if(fa[u][i] != fa[v][i]){
//             u = fa[u][i];
//             v = fa[v][i];
//         }
//     }

//     return fa[u][0];
// }

// //树链剖分版
// const int N = 5e5+10;

// vector<vector<int>> gra(N);

// int son[N];
// int fa[N];
// int dep[N];
// int sz[N];
// int top[N];

// int n,m,s;

// void dfs(int u,int pa){
//     dep[u] = dep[pa] + 1;
//     fa[u] = pa;
//     sz[u] = 1;

   
//     for(auto x : gra[u]){
//         if(x==pa) continue;
//         dfs(x,u);
//         sz[u] += sz[x];
//         if(sz[son[u]] < sz[x]) son[u] = x;
//     }
// }

// void gettop(int u,int t){
//     top[u] = t;

//     if(!son[u]) return ;

//     gettop(son[u],t);

//     for(auto x : gra[u]){
//         if(x==son[u] || x==fa[u]) continue;
//         gettop(x,x);
//     }
// }

// int lca(int u,int v){
//     while(top[u] != top[v]){
//         if(dep[top[u]] < dep[top[v]]) swap(u,v);
//         u = fa[top[u]];
//     }

//     return dep[u] < dep[v] ? u : v;
// }