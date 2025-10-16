//线段树，区间修改，区间查询
//https://www.luogu.com.cn/problem/P3372
template<typename Info, typename Tag>
struct SegmentTree {
#define ls (id<<1)
#define rs (id<<1|1)
	SegmentTree() = default;
	SegmentTree(int n) : n(n), info(n << 2), tag(n << 2), len(n << 2) {}
	SegmentTree(const SegmentTree<Info, Tag> &o) : n(o.n), info(o.info), tag(o.tag) {}
	template<typename T>
	SegmentTree(const std::vector<T> &init) : SegmentTree((int)init.size()) {
		auto build = [&](auto self, int id, int l, int r) ->void {
			len[id] = r - l + 1;
			if(l == r) {
				info[id] = init[l];
				return;
			}
			int mid = (l + r) / 2;
			self(self, ls, l, mid);
			self(self, rs, mid + 1, r);
			pushup(id);
		};
		build(build, 1, 0, n - 1);
	}
	void apply(int id, const Tag &dx) {
		info[id].apply(dx, len[id]);
		tag[id].apply(dx);
	}
	void pushup(int id) {
		info[id] = info[ls] + info[rs];
	}
	void pushdown(int id) {
		apply(ls, tag[id]);
		apply(rs, tag[id]);
		tag[id] = Tag();
	}
	
	void modify(int id, int l, int r, int pos, const Info &val) {
		if(l == r) {
			info[id] = val;
			return;
		}
		pushdown(id);
		int mid = (l + r) / 2;
		if(pos <= mid) {
			modify(ls, l, mid, pos, val);
		} else {
			modify(rs, mid + 1, r, pos, val);
		}
		pushup(id);
	}
	
	void rangeUpdate(int id, int l, int r, int x, int y, const Tag &dx) {
		if(x <= l && r <= y) {
			apply(id, dx);
			return;
		}
		int mid = (l + r) / 2;
		pushdown(id);
		if(x <= mid) {
			rangeUpdate(ls, l, mid, x, y, dx);
		}
		if(y > mid) {
			rangeUpdate(rs, mid + 1, r, x, y, dx);
		}
		pushup(id);
	}
	Info rangeQuery(int id, int l, int r, int x, int y) {
		if(x <= l && r <= y) {
			return info[id];
		}
		int mid = (l + r) / 2;
		pushdown(id);
		Info res;
		if(x <= mid) {
			res = res + rangeQuery(ls, l, mid, x, y);
		}
		if(y > mid) {
			res = res + rangeQuery(rs, mid + 1, r, x, y);
		}
		return res;
	}


	void rangeUpdate(int l, int r, const Tag &dx) {
		rangeUpdate(1, 0, n - 1, l, r, dx);
	}
	void update(int pos, const Tag &dx) {
		rangeUpdate(pos, pos, dx);
	}
	Info rangeQuery(int l, int r) {
		return rangeQuery(1, 0, n - 1, l, r);
	}
	Info query(int pos) {
		return rangeQuery(pos, pos);
	}

	void modify(int pos, const Info &val) {
		return modify(1, 0, n - 1, pos, val);
	}
#undef ls
#undef rs
	int n;
	std::vector<Info> info;
	std::vector<Tag> tag;
	std::vector<int> len;
};

constexpr i64 INF = 4E18;
i64 mod = 1e9 + 7;
struct Tag {
	i64 add = 0;
	i64 mul = 1;
	void apply(const Tag &dx) {
		mul = (mul * dx.mul) % mod;
		add = (add * dx.mul + dx.add) % mod;
	}
};

struct Info {
	i64 sum = 0;
	Info() {}
	Info(i64 x) : sum(x) {};
	void apply(const Tag &dx, const int &len) {
		sum = (sum * dx.mul + dx.add * len) % mod;
	}
};

Info operator+(const Info &x, const Info &y) {
	Info res;
	res.sum = (x.sum + y.sum) % mod;
	return res;
}