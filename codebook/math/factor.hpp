vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (is_prime(n)) return { n };
	ull x = pollard_rho(n);
	auto l = factor(x), r = factor(n / x);
	l.insert(l.end(), ALL(r));
	return l;
}
