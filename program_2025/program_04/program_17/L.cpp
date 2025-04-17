#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;

struct Point {
    long long x, y, z;
    bool operator==(const Point& o) const { return x==o.x && y==o.y && z==o.z; }
};
struct PointHash {
    size_t operator()(const Point& p) const {
        size_t h = std::hash<long long>{}(p.x);
        h ^= std::hash<long long>{}(p.y + 0x9e3779b97f4a7c15ULL + (h<<6) + (h>>2));
        h ^= std::hash<long long>{}(p.z + 0x9e3779b97f4a7c15ULL + (h<<6) + (h>>2));
        return h;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;  cin >> T;
    while (T--) {
        long long W,H,L;  cin >> W >> H >> L;
        int n;            cin >> n;

        unordered_set<Point,PointHash> P;
        P.reserve(8LL*n*2);
        i128 totalVol = 0;

        auto toggle = [&](long long x,long long y,long long z){
            Point p{x,y,z};
            auto it = P.find(p);
            if (it==P.end()) P.insert(p);
            else P.erase(it);
        };

        for(int i=0;i<n;++i){
            long long xl,yl,zl,xr,yr,zr;
            cin>>xl>>yl>>zl>>xr>>yr>>zr;

            totalVol += i128(xr-xl)*(yr-yl)*(zr-zl);

            toggle(xl,yl,zl); toggle(xl,yl,zr);
            toggle(xl,yr,zl); toggle(xl,yr,zr);
            toggle(xr,yl,zl); toggle(xr,yl,zr);
            toggle(xr,yr,zl); toggle(xr,yr,zr);
        }

        bool ok = (totalVol == i128(W)*H*L);
        if (ok && P.size()==8){
            const Point need[8]={
                {0,0,0},{0,0,L},{0,H,0},{0,H,L},
                {W,0,0},{W,0,L},{W,H,0},{W,H,L}
            };
            for(const auto& p:need) if(!P.count(p)){ ok=false;break; }
        }else ok=false;

        cout<<(ok?"Yes\n":"No\n");
    }
    return 0;
}
