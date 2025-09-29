template <typename T>
struct Fenwick {
	int n;
	std::vector<T> a;
	
	Fenwick(int n) : n(n), a(n + 1) {}
	
	
	void add(int x, const T &v) {
		for (int i = x; i <= n; i += i & -i) {
			a[i] = a[i] + v;
		}
	}
	
	T sum(int x) {
		T ans{};
		for (int i = x; i > 0; i -= i & -i) {
			ans = ans + a[i];
		}
		return ans;
	}
	
	T range(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	T kth(T k) {
		int pos = 0;
		int logn = std::bit_width(a.size() - 1);
		for(int i = 1 << (logn - 1); i > 0; i >>= 1) {
			if(pos + i < a.size() && a[pos + i] < k) {
				k -= a[pos + i];
				pos += i;
			}
		}
		return pos + 1;
	}
	
};