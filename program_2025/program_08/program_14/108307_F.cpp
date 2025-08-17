#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

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
i64 mod = 1e18 + 7;
struct Tag {
	int add = 0;
	void apply(const Tag &dx) {
		add = add + dx.add;
	}
};

struct Info {
	int maxx = 0;
	int idx = 0;
	Info() {}
	Info(i64 x) : maxx(x) {};
	void apply(const Tag &dx, const int &len) {
		maxx = maxx + dx.add;
	}
};

Info operator+(const Info &x, const Info &y) {
	Info res;
	if(x.maxx > y.maxx) {
		res.idx = x.idx;
	} else {
		res.idx = y.idx;
	}
	res.maxx = max(x.maxx, y.maxx);
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	unordered_map<int, vector<int>> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >= 2; i--) {
		q[a[i]].push_back(i);
	}
	unordered_map<int, int> mp, mp1, mp2, mp3;


	mp1[a[1]] = 1;
	mp2[a[2]] = 1;
	SegmentTree<Info, Tag> seg(n + 1);
	for(int i = 3; i <= n; i++) {
		mp3[a[i]]++;
		if(mp1[a[i]] && mp2[a[i]]) mp[a[i]] = 1;
	}
	Info info;
	info.maxx = mp.size();
	info.idx = 3;
	seg.modify(3, info);
	for(int i = 4; i <= n; i++) {
		mp3[a[i - 1]]--;
		mp2[a[i - 1]]++;
		if(mp.count(a[i - 1])) {
			if(!mp1[a[i - 1]] || !mp2[a[i - 1]] || !mp3[a[i - 1]]) {
				mp.erase(a[i - 1]);
			}
		} else {
			if(mp1[a[i - 1]] && mp2[a[i - 1]] && mp3[a[i - 1]]) {
				mp[a[i - 1]] = 1;
			}
		}
		Info info;
		info.maxx = mp.size();
		info.idx = i;
		seg.modify(i, info);
	}
	i64 ans = -1;
	int b1 = 0, b2 = 0;

	Info tmp = seg.rangeQuery(3, n);
	if(ans < tmp.maxx) {
		ans = tmp.maxx;
		b1 = 2, b2 = tmp.idx;
	}

	for(int i = 3; i < n; i++) {
		q[a[i - 1]].pop_back();
		if(!mp1[a[i - 1]]) {
			if(!q[a[i - 1]].empty()) {
				int l = q[a[i - 1]].back() + 1, r = q[a[i - 1]].front();
				Tag tag;
				tag.add = 1;
				seg.rangeUpdate(l, r, tag);
			}
				
		} else {
			if(!q[a[i - 1]].empty()) {
				int r = q[a[i - 1]].back();
				int l = i;
				Tag tag;
				tag.add = -1;
				seg.rangeUpdate(l, r, tag);
			}

			

		}
		Info tmp = seg.rangeQuery(i + 1, n);
		if(ans < tmp.maxx) {
			ans = tmp.maxx;
			b1 = i, b2 = tmp.idx;
		}


		mp1[a[i - 1]] ++;

		
	};

	cout << ans << '\n';
	cout << b1 << ' ' << b2 << '\n';





}


int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int T = 1;
	cin >> T;
	while (T--) solve();

	return 0;
}
