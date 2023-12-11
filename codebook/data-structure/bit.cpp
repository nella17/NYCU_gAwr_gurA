template<typename S>
struct BIT { // 0-based
#define lb(x) (x&-x)
  int sz; vector<S> ary;
  BIT(int _sz): sz(_sz), ary(_sz) {}
  void update(int x, S v) {
    for(x++; x <= sz; x += lb(x))
      ary[x-1] += v;
  }
  S query(int x) { // [0,x]
    S r;
    if (x >= sz) x = sz;
    for(x++; x > 0; x -= lb(x))
      r += ary[x-1];
    return r;
  }
  S query(int l, int r) { // [l,r]
    if (l > r) return S{};
    return query(r) - query(l-1);
  }
#undef lb
};
struct S {
  int v;
  S(int _v = 0): v(_v) {}
  void operator+=(S o) { v += o.v; }
};
