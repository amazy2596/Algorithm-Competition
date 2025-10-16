template <typename T>
class SparseTable {
    
    // using func_type = function<T(const T &, const T &)>;

    vector<vector<T>> ST;
    // 更改操作, 修改这一条语句
    static T op(const T &t1, const T &t2) { return max(t1, t2); }

    // func_type op;

    public:
    SparseTable(const vector<T> &v) {

        int n = v.size() - 1;

        int len = __lg(n);
        ST.assign(n + 1, vector<T>(len + 1, 0));

        for (int i = 0; i <= n; ++i) {
            ST[i][0] = v[i];
        }
        for (int j = 1; j <= len; ++j) {
            int pj = (1 << (j - 1));
            for (int i = 0; i + pj <= n; ++i) {
                ST[i][j] = op(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) {
        int q = __lg(r - l + 1);
        return op(ST[l][q], ST[r - (1 << q) + 1][q]);
    }
};