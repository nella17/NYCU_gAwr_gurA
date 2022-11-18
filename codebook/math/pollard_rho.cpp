ull pollard(ull n) {
	auto f = [n](ull x){ return modmul(x, x, n) + 1; };
	ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
	while (t++ % 40 || __gcd(prd, n) == 1) {
		if (x == y) x = ++i, y = f(x);
		if ((q = modmul(prd, max(x,y) - min(x,y), n)))
            prd = q;
		x = f(x), y = f(f(y));
	}
	return __gcd(prd, n);
}
