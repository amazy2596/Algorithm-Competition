#include <bits/stdc++.h>
#define uint uint64_t 
#define int long long
using namespace std;

void solve() {
   double r;
   cin >> r;
   
   int total = 0;
   double r2 = r * r;
   int i = 0;
   
   double i_half = 0.5;
   double i_half2 = 0.25;
   
   while (true) {
       double max_j2 = r2 - i_half2;
       if (max_j2 < 0.25) break;
       
       int j = floor(sqrt(max_j2) - 0.5);
       total += j + 1;
       
       i++;
       i_half = i + 0.5;
       i_half2 = i_half * i_half;
   }
   
   if (i == 0) {
       cout << 1 << "\n";
       return;
   }
   cout << 4 * total - 4 * (i - 1) - 3 << "\n";
}

signed main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   
   int T = 1;
   // cin >> T;
   while (T--) solve();
   return 0;
}