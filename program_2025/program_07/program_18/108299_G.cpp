#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
#define double long double
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct Point
{
    double x, y;

    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
};

double det(Point a, Point b, Point c, Point d)
{
    // a->b x c->d
    return (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x); 
}

double dist(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve()
{
    int n;
    double x, y;
    cin >> n >> x >> y;

    cout << fixed << setprecision(15);
    Point p(x, y);
    vector<Point> poly(n);
    for (int i = 0; i < n; i++)
        cin >> poly[i].x >> poly[i].y;

    bool f = 1;
    for (int i = 0; i < n; i++)
    {
        auto p1 = poly[i];
        auto p2 = poly[(i + 1) % n];
        if (det(p1, p2, p1, p) < 0)
        {
            f = 0;
            break;
        }
    }

    if (!f)
    {
        cout << 2 * numbers::pi << "\n";
        return;
    }

    double mx = 0;
    for (int i = 0; i < n; i++)
        mx = max(mx, dist(p, poly[i]));

    vector<double> angles;
    for (int i = 0; i < n; i++)
    {
        auto cur = poly[i];
        if (abs(mx - dist(p, cur)) <= eps)
        {
            double dx = p.x - cur.x;
            double dy = p.y - cur.y;

            double angle = atan2l(dy, dx);
            angles.push_back(angle);
        }
    }

    sort(angles.begin(), angles.end());
    double ans = 0;
    for (int i = 1; i < angles.size(); i++)
    {
        auto a1 = angles[i - 1];
        auto a2 = angles[i];

        ans = max(ans, a2 - a1);
    }

    ans = max(ans, 2 * numbers::pi - (angles.back() - angles[0]));

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}