// stars and pars ---- The number of ways to put n indistinguishable objects into k distinguishable boxes is:

long long comb(int n, int k) {
	if (k > n - k) { k = n - k; }
	long long ret = 1;
	for (int i = 0; i < k; i++) {
		// this is done instead of *= for divisibility issues
		ret = ret * (n - i) / (i + 1);
	}
	return ret;
}
