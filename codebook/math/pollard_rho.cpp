ll pollard_rho(ll x) {
  ll s = 0, t = 0, v = 1, c = randint(1LL, x);
  for (int g = 1; ; g *= 2, s = t, v = 1) {
    for (int ss = 1; ss <= g; ++ss) {
      t = ((LL)t * t + c) % x;
      v = (LL)v * abs(t - s) % x;
      if ((ss % 127) == 0) {
        ll d = __gcd(v, x);
        if (d > 1) return d;
      }
    }
    ll d = __gcd(v, x);
    if (d > 1) return d;
  }
}
