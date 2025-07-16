#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

// vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
// vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
// const double eps = 1e-12;
// const int inf = 1e18;

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

constexpr uint rev = 0xffffffffffffffff;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    int b = 64;
    int m = (n + b - 1) / b;
    vector<uint> block(m + 5, 0);
    for (int i = 0; i < n; i++)
        block[i / b] |= ((uint)(s[i] - '0') << (i % b));

    int t = (1ll << 16);
    vector<int> total(t + 1), left(t + 1), right(t + 1);
    for (int mask = 0; mask < t; mask++)
    {
        uint l = 0, r = 0;
        for (int k = 0; k < 16; k++)
        {
            if ((mask >> k) & 1)
                l++;
            else 
                break;
        }
        left[mask] = l;

        for (int k = 15; k >= 0; k--)
        {
            if ((mask >> k) & 1)
                r++;
            else 
                break;
        }
        right[mask] = r;

        int sum = 0;
        for (int k = 0; k < 16; k++)
        {
            if ((mask >> k) & 1)
                sum++, total[mask] += sum;
            else 
                sum = 0;
        }

    }

    vector<int> tag_diff(m + 5);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;

            while(l % 64 != 0 && l <= r) {
                block[l / 64] ^= 1ull << (l % 64);
                l++;
            }
            while(r % 64 != 63 && l <= r) {
                block[r / 64] ^= 1ull << (r % 64);
                r--;
            }
            if(l % 64 == 0 && r % 64 == 63) {
                tag_diff[l / 64] ^= 1ull;
                tag_diff[r / 64 + 1] ^= 1ull;
            }
        }
        else 
        {
            int l, x, y;
            cin >> l >> x >> y;
            x--, y--;

            for(int i = 0; i < m; ++i) {
                tag_diff[i + 1] ^= tag_diff[i];
                if(tag_diff[i]) {
                    block[i] ^= rev;
                }
                tag_diff[i] = 0;
            }

            auto get_mask = [&](int idx, int len)
            {
                int id = idx / b;
                int offset = idx % b;

                uint mask;
                if (offset + len <= b)
                    mask = (block[id] >> offset);
                else 
                {
                    uint left = block[id] >> offset;
                    uint right = block[id + 1] << (b - offset);
                    mask = left | right;
                }

                if (len < b)
                    mask &= (1ull << len) - 1;
                
                return mask;
            };

            int ans = 0, suf = 0;
            for (int i = 0; i < l; i += 64)
            {
                int len_chunk = min(64ll, l - i);

                uint maskA = get_mask(i + x, len_chunk);
                uint maskB = get_mask(i + y, len_chunk);

                uint mask64 = (~(maskA ^ maskB));

                for (int j = 0; j < len_chunk; j += 16) 
                {
                    int len = min(16ll, len_chunk - j);
                    uint mask16 = (mask64 >> j) & ((1ULL << len) - 1);

                    ans += total[mask16];
                    ans += suf * left[mask16];

                    if (left[mask16] >= len)
                        suf += len;
                    else 
                    {
                        if (len == 16)
                            suf = right[mask16];
                        else 
                        {
                            int true_right = 0;
                            for (int k = len - 1; k >= 0; --k) 
                            {
                                if ((mask16 >> k) & 1) true_right++;
                                else break;
                            }
                            suf = true_right;
                        }
                    }
                }
            }

            cout << ans << "\n";
        }
    }
}

signed main()
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