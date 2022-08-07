pll extgcd(ll a, ll b) {
  if(b == 0) return pll{1, 0};
  else {
    ll p = a / b;
    auto [x,y] = extgcd(b, a % b);
    return pll{y, x - y * p};
  }
}
