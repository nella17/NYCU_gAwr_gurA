ll solve_crt(ll x1, ll m1, ll x2, ll m2) {
  ll g = __gcd(m1, m2);
  if((x2 - x1) % g) return -1; // no sol
  m1 /= g; m2 /= g;
  auto [pf,ps] = extgcd(m1, m2);
  ll lcm = m1 / g * m2;
  ll res = pf * (x2 - x1) * m1 + x1;
  return (res % lcm + lcm) % lcm;
}
