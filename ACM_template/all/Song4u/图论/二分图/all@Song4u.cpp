//染色法判二分图
// const int N = 1e5+10;
// const int M = 2*N;

// int n,m;
// struct edge{
//     int v,ne;
// }e[M];

// int h[N];
// int idx;
// int col[N];

// void add(int a,int b){
//     e[idx++] = {b,h[a]};
//     h[a] = idx;
// }

// bool dfs(int u,int c){
//     col[u] = c;
//     for(int i = h[u];i;i = e[i].ne){
//         int v = e[i].v;
//         if(!col[v]){
//             if(dfs(v,3-c)) return true;
//         }else{
//             if(col[v] == c) return false;
//         }
//     }

//     return false;
// }

// void solve(){
//     cin>>n>>m;

//     for(int i = 1;i<=m;i++){
//         int a,b;
//         cin>>a>>b;

//         add(a,b);
//         add(b,a);
//     }

//     bool suc = true;
//     for(int i = 1;i<=n;i++){
//         if(!col[i]){
//             if(dfs(i,1)){
//                 suc = false;
//                 break;
//             }
//         }
//     }

//     cout<<(suc ? "YES" : "NO")<<'\n';
// }


//二分图最大匹配
// std::mt19937_64 rng(
//     static_cast<std::mt19937_64::result_type>(std::time(nullptr)));
// struct BipartiteGraph {
//   int n1, n2;                       // number of vertices in X and Y, resp.
//   std::vector<std::vector<int>> g;  // edges from X to Y
//   std::vector<int> ma, mb;  // matches from X to Y and from Y to X, resp.
//   std::vector<bool> vis;    // visiting marks for DFS.

//   BipartiteGraph(int n1, int n2)
//       : n1(n1), n2(n2), g(n1), ma(n1, -1), mb(n2, -1) {}

//   // Add an edge from u in X to v in Y.
//   void add_edge(int u, int v) { g[u].emplace_back(v); }

//   // Find an augmenting path starting at u.
//   bool dfs(int u) {
//     vis[u] = true;
//     // Heuristic: find unsaturated vertices whenever possible.
//     for (int v : g[u]) {
//       if (mb[v] == -1) {
//         ma[u] = v;
//         mb[v] = u;
//         return true;
//       }
//     }
//     for (int v : g[u]) {
//       if (!vis[mb[v]] && dfs(mb[v])) {
//         ma[u] = v;
//         mb[v] = u;
//         return true;
//       }
//     }
//     return false;
//   }

//   // Kuhn's maximum matching algorithm.
//   std::vector<std::pair<int, int>> kuhn_maximum_matching() {
//     // Randomly shuffle the edges.
//     for (int u = 0; u < n1; ++u) {
//       std::shuffle(g[u].begin(), g[u].end(), rng);
//     }
//     // Find a maximal set of vertex-disjoint augmenting paths in each round.
//     while (true) {
//       bool succ = false;
//       vis.assign(n1, false);
//       for (int u = 0; u < n1; ++u) {
//         succ |= ma[u] == -1 && dfs(u);
//       }
//       if (!succ) break;
//     }
//     // Collect the matched pairs.
//     std::vector<std::pair<int, int>> matches;
//     matches.reserve(n1);
//     for (int u = 0; u < n1; ++u) {
//       if (ma[u] != -1) {
//         matches.emplace_back(u, ma[u]);
//       }
//     }
//     return matches;
//   }
// };

// void solve(){
//     int n,m,e;
//     cin>>n>>m>>e;

//     BipartiteGraph bg(n+1,m+1);

//     for(int i = 1;i<=e;i++){
//         int u,v;
//         cin>>u>>v;
//         bg.add_edge(u,v);
//     }

//     vector<pii> q = bg.kuhn_maximum_matching();

//     cout<<q.size()<<'\n';

// }

//二分图最大权值匹配
// template <typename T>
// struct hungarian {  // km
//   int n;
//   vector<int> matchx;  // 左集合对应的匹配点
//   vector<int> matchy;  // 右集合对应的匹配点r
//   vector<int> pre;     // 连接右集合的左点
//   vector<bool> visx;   // 拜访数组 左
//   vector<bool> visy;   // 拜访数组 右
//   vector<T> lx;
//   vector<T> ly;
//   vector<vector<T>> g;
//   vector<T> slack;
//   T inf;
//   T res;
//   queue<int> q;
//   int org_n;
//   int org_m;

//   hungarian(int _n, int _m) {
//     org_n = _n;
//     org_m = _m;
//     n = max(_n, _m);
//     inf = numeric_limits<T>::max();
//     res = 0;
//     g = vector<vector<T>>(n, vector<T>(n));
//     matchx = vector<int>(n, -1);
//     matchy = vector<int>(n, -1);
//     pre = vector<int>(n);
//     visx = vector<bool>(n);
//     visy = vector<bool>(n);
//     lx = vector<T>(n, -inf);
//     ly = vector<T>(n);
//     slack = vector<T>(n);
//   }

//   void addEdge(int u, int v, int w) {
//     g[u][v] = max(w, 0);  // 负值还不如不匹配 因此设为0不影响
//   }

//   bool check(int v) {
//     visy[v] = true;
//     if (matchy[v] != -1) {
//       q.push(matchy[v]);
//       visx[matchy[v]] = true;  // in S
//       return false;
//     }
//     // 找到新的未匹配点 更新匹配点 pre 数组记录着"非匹配边"上与之相连的点
//     while (v != -1) {
//       matchy[v] = pre[v];
//       swap(v, matchx[pre[v]]);
//     }
//     return true;
//   }

//   void bfs(int i) {
//     while (!q.empty()) {
//       q.pop();
//     }
//     q.push(i);
//     visx[i] = true;
//     while (true) {
//       while (!q.empty()) {
//         int u = q.front();
//         q.pop();
//         for (int v = 0; v < n; v++) {
//           if (!visy[v]) {
//             T delta = lx[u] + ly[v] - g[u][v];
//             if (slack[v] >= delta) {
//               pre[v] = u;
//               if (delta) {
//                 slack[v] = delta;
//               } else if (check(v)) {  // delta=0 代表有机会加入相等子图 找增广路
//                                       // 找到就return 重建交错树
//                 return;
//               }
//             }
//           }
//         }
//       }
//       // 没有增广路 修改顶标
//       T a = inf;
//       for (int j = 0; j < n; j++) {
//         if (!visy[j]) {
//           a = min(a, slack[j]);
//         }
//       }
//       for (int j = 0; j < n; j++) {
//         if (visx[j]) {  // S
//           lx[j] -= a;
//         }
//         if (visy[j]) {  // T
//           ly[j] += a;
//         } else {  // T'
//           slack[j] -= a;
//         }
//       }
//       for (int j = 0; j < n; j++) {
//         if (!visy[j] && slack[j] == 0 && check(j)) {
//           return;
//         }
//       }
//     }
//   }

//   void solve() {
//     // 初始顶标
//     for (int i = 0; i < n; i++) {
//       for (int j = 0; j < n; j++) {
//         lx[i] = max(lx[i], g[i][j]);
//       }
//     }

//     for (int i = 0; i < n; i++) {
//       fill(slack.begin(), slack.end(), inf);
//       fill(visx.begin(), visx.end(), false);
//       fill(visy.begin(), visy.end(), false);
//       bfs(i);
//     }

//     // custom
//     for (int i = 0; i < n; i++) {
//       if (g[i][matchx[i]] > 0) {
//         res += g[i][matchx[i]];
//       } else {
//         matchx[i] = -1;
//       }
//     }
//     cout << res << "\n";
//     for (int i = 0; i < org_n; i++) {
//       cout << matchx[i] + 1 << " ";
//     }
//     cout << "\n";
//   }
// };


