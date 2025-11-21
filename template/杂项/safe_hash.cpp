#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using i128 = __int128_t;

// snippet-begin:
using u64 = uint64_t;
struct safe_hash {
    static u64 splitmix64(u64 x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    // 随机种子只获取一次，static 保证效率
    static u64 get_rnd() {
        static const u64 R = chrono::steady_clock::now().time_since_epoch().count();
        return R;
    }

    size_t operator()(u64 x) const {
        return splitmix64(x + get_rnd());
    }

    // 支持 pair (如果不需要可以删掉这几行)
    size_t operator()(pair<u64, u64> x) const {
        return splitmix64(x.first + get_rnd()) ^ (splitmix64(x.second + get_rnd()) >> 1);
    }
};
// snippet-end:

void solve()
{
    
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}