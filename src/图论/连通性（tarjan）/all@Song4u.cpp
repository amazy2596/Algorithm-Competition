// tarjan求强连通分量
// e.g. https://www.luogu.com.cn/problem/P2863
// const int N = 1e4+10;

// vector<int> gra[N];
// int dfn[N];//时间戳，节点x第一次被访问的顺序
// int low[N];//追溯值，从节点x出发，所能访问到的最早时间戳
// int tot;//时间戳编号
// int stk[N];//栈
// int instk[N];//在不在栈中
// int top;
// int scc[N];//点x属于哪一个scc
// int siz[N];//scc大小
// int cnt;//scc编号

// void tarjan(int x){
//     //入x时，盖戳，入栈
//     dfn[x] = low[x] = ++ tot;
//     stk[++top] =  x;
//     instk[x] = 1;

//     for(int y : gra[x]){
//         if(!dfn[y]){
//             tarjan(y);
//             low[x] = min(low[x],low[y]);
//         }else if(instk[y]){
//             low[x] = min(low[x],dfn[y]);
//         }
//     }

//     if(dfn[x] == low[x]){
//         int y;
//         ++cnt;
//         do{
//             y = stk[top--];
//             instk[y] = 0;
//             scc[y] = cnt;
//             ++siz[cnt];
//         }while(y!=x);
//     }
// }

//tarjan scc 缩点
//e.g.https://www.luogu.com.cn/problem/P2341
//e.g.https://www.luogu.com.cn/problem/P3387
//e.g.https://www.luogu.com.cn/problem/P3387
// vector<int> gra[N];
// int dfn[N];//时间戳，节点x第一次被访问的顺序
// int low[N];//追溯值，从节点x出发，所能访问到的最早时间戳
// int tot;//时间戳编号
// int stk[N];//栈
// int instk[N];//在不在栈中
// int top;
// int scc[N];//点x属于哪一个scc
// int siz[N];//scc大小
// int cnt;//scc编号
// int din[N],dout[N];//统计scc的入度和出度

// void tarjan(int x){
//     //入x时，盖戳，入栈
//     dfn[x] = low[x] = ++ tot;
//     stk[++top] =  x;
//     instk[x] = 1;

//     for(int y : gra[x]){
//         if(!dfn[y]){
//             tarjan(y);
//             low[x] = min(low[x],low[y]);
//         }else if(instk[y]){
//             low[x] = min(low[x],dfn[y]);
//         }
//     }

//     if(dfn[x] == low[x]){
//         int y;
//         ++cnt;
//         do{
//             y = stk[top--];
//             instk[y] = 0;
//             scc[y] = cnt;
//             ++siz[cnt];
//         }while(y!=x);
//     }
// }

//  for(int i = 1;i<=n;i++){
//         for(int j : gra[i]){
//             if(scc[i] != scc[j]){
//                 din[scc[j]] ++;
//                 dout[scc[i]] ++;
//             }
//         }
//     }



//tarjan判割点
//e.g.https://www.luogu.com.cn/problem/P3388

// const int N = 2e4+10;

// vector<int> gra[N];
// int dfn[N];//时间戳，节点x第一次被访问的顺序
// int low[N];//追溯值，从节点x出发，所能访问到的最早时间戳
// int tot;//时间戳编号
// int cut[N];//记录当前点是不是割点
// int root;//哪个点是根


// void tarjan(int x){
//     //入x时，盖戳
//     dfn[x] = low[x] = ++tot;
//     int child = 0;

//     for(int y : gra[x]){
//         if(!dfn[y]){//若y尚未访问
//             tarjan(y);
//             //回x时，更新low，判割点
//             low[x] = min(low[x],low[y]);
//             if(low[y] >= dfn[x]){
//                 child ++;//子树的数量
//                 if(x != root || child > 1){
//                     cut[x] = 1;
//                 }
//             }
//         }else{//若y已经找到
//             low[x] = min(low[x],dfn[y]);
//         }

//     }
// }
// void solve(){
//     cin>>n>>m;
    
//     while(m--){
//         int u,v;
//         cin>>u>>v;

//         gra[u].push_back(v);
//         gra[v].push_back(u);
//     }


//     for(int i = 1;i<=n;i++){
//         if(!dfn[i]){
//             root  = i;
//             tarjan(i);
//         }
//     }

//     int ans = 0;
//     for(int i = 1;i<=n;i++){
//         if(cut[i]) ans++;
//     }

//     cout<<ans<<'\n';

//     for(int i = 1;i<=n;i++) {
//         if(cut[i]) cout<<i<<' ';
//     }
// }




//tarjan找割边
//e.g.https://www.luogu.com.cn/problem/P1656

// const int N=210,M=10010;
// int n,m,a,b;

// struct edge{int u,v;};
// vector<edge>e;//边集
// vector<int>h[N];//出边
// int dfn[N],low[N],tot;

// struct bridge{
//   int x,y;
//   bool operator<(const bridge &t)const{
//     if(x==t.x)return y<t.y;
//     return x<t.x;
//   }
// }bri[M];
// int cnt;//给割边计数

// void add(int a,int b){
//   e.push_back({a,b});
//   h[a].push_back(e.size()-1);
// }
// void tarjan(int x,int in_edge){
//   dfn[x]=low[x]=++tot;
//   for(int i=0;i<h[x].size();i++){
//     int j=h[x][i], y=e[j].v;//j是当前出边在边集中的位置，y是当前边的下一个点
//     if(!dfn[y]){ //若y尚未访问
//       tarjan(y,j);
//       low[x]=min(low[x],low[y]);
//       if(low[y]>dfn[x]){
//         bri[cnt++]={x,y};
//       }
//     }
//     else if(j!=(in_edge^1)) //不是反边
//       low[x]=min(low[x],dfn[y]);
//   }
// }


// void solve(){
//     cin>>n>>m;

//     while(m--){
//         cin>>a>>b;

//         add(a,b);
//         add(b,a);
//     }

//     for(int i = 1;i<=n;i++){
//         if(!dfn[i]) tarjan(i,0);
//     }

//     sort(bri,bri+cnt);

//     for(int i = 0;i<cnt;i++){
//         cout<<bri[i].x<<' '<<bri[i].y<<'\n';
//     }
// }



// //eDCC：无向图中极大的不包含割边的连通块被称为“边双连通分量”
 
//适用于无向有环图得到森林或树
// const int M = 1e4+10;
// const int N = 5e3+10;

// int n,m;
// struct edge{
//     int v,ne;
// };
// edge e[M];
// int h[N],idx = 1;
// int dfn[N];
// int low[N];
// int tot;
// stack<int> stk;
// int dcc[N],cnt;
// int bri[M];
// int d[N];

// void add(int x,int y){
//     e[++idx].v = y;
//     e[idx].ne = h[x];
//     h[x] = idx;
// }

// void tarjan(int x,int in_edg){
//     dfn[x] = low[x] = ++tot;
//     stk.push(x);

//     for(int i = h[x];i;i = e[i].ne){
//         int y = e[i].v;

//         if(!dfn[y]){
//             tarjan(y,i);
//             low[x] = min(low[x],low[y]);
//             if(low[y] > dfn[x]){
//                 bri[i] = bri[i^1] = true;
//             }
//         }else if(i!=(in_edg^1)){
//             low[x] = min(low[x],dfn[y]);
//         }
//     }

//     if(dfn[x] == low[x]){
//         ++cnt;

//         while(1){
//             int y = stk.top();
//             stk.pop();
//             dcc[y] = cnt;
//             if(y==x) break;
//         }
//     }
// }
 
// void solve(){
//     cin>>n>>m;

//     while(m--){
//         int x,y;
//         cin>>x>>y;

//         add(x,y);
//         add(y,x);
//     }

//     tarjan(1,0);

//     for(int i = 2;i<=idx;i++){
//         if(bri[i]){
//             d[dcc[e[i].v]] ++;
//         }
//     }

//     int ans = 0;

//     for(int i = 1;i<=cnt;i++){
//         if(d[i] == 1) ans++;
//     }
    
//     cout<<ans<<'\n';
//     ans = (ans+1) / 2;

//     cout<<ans;

// }


// // tarjan求vDCC
// //e.g.https://www.luogu.com.cn/problem/P8435
// const int N = 1e4+10;
// int n,m;
// vector<int> e[N];//加边数组
// vector<int> ne[N];//new_e在缩完点之后要建的新图
// int dfn[N];
// int low[N];
// int tot;
// stack<int> stk;
// vector<int> dcc[N];//点双连通分量
// int cnt;//记录dcc
// int cut[N];//点x是不是割点
// int root;
// int num;//给每个割点一个新编号
// int id[N];//给每个割点新编号用

// void tarjan(int x){
//     dfn[x] = low[x] = ++ tot;
//     stk.push(x);
//     if(!e[x].size()){//若x没有边，就是一个孤立点
//         dcc[++cnt].push_back(x);
//         return ;
//     }

//     int child = 0;
//     for(int y : e[x]){
//         if(!dfn[y]){
//             tarjan(y);
//             low[x] = min(low[x],low[y]);
//             if(low[y] >= dfn[x]){
//                 child ++;
//                 if(x!=root || child > 1){
//                     cut[x] = true;
//                 }

//                 cnt++;

//                 while(1){
//                     int z = stk.top();
//                     stk.pop();
//                     dcc[cnt].push_back(z);
//                     if(z==y) break;
//                 }

//                 dcc[cnt].push_back(x);
//             }
//         }else{
//             low[x] = min(low[x],dfn[y]);
//         }
//     }
// }

// void solve(){
//     cin>>n>>m;

//     while(m--){
//         int a,b;
//         cin>>a>>b;

//         e[a].push_back(b);
//         e[b].push_back(a);
//     }

//     for(root = 1;root<=n;root ++){
//         if(!dfn[root]) tarjan(root);
//     }

//     //给每个割点一个新编号，因为缩点之后要把割点裂点
//     num = cnt;
//     for(int i = 1;i<=n;i++){
//         if(cut[i]) id[i] = ++num;
//     }

//     //建新图，从每个vdcc向对应割点连边
//     for(int i = 1;i<=cnt;i++){
//         for(int j = 0;j<dcc[i].size();j++){
//             int x = dcc[i][j];
//             if(cut[x]){
//                 ne[i].push_back(id[x]);
//                 ne[id[x]].push_back(i);
//             }
//         }
//     }
// }