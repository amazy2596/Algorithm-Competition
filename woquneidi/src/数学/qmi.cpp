int qmi(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = 1ll * res * a % mod;
		b >>= 1;
		a = 1ll * a * a % mod;

	}
	return res;
}