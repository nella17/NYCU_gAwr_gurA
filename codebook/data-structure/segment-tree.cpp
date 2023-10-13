struct SegmentTree { // Node, V
#define MYZ int m = l + (r - l) / 2, \
  y = o + 1, z = o + (r - l) / 2 * 2
  int n; vector<Node> ary;
  SegmentTree(int _n, auto& init) { build(_n, init); }
  void build(int _n, const auto& init) {
    n = _n; ary.resize(2*n); build(0, 0, n, init); }
  void modify(int ql, int qr, auto v) {
    modify(0, 0, n, ql, qr, v); }
  auto query(int ql, int qr) {
    return query(0, 0, n, ql, qr); }
  void build(int o, int l, int r, const auto& init) {
    if (l == r-1) {
      ary[o] = Node(init[l]); // TODO
    } else {
      MYZ;
      build(y, l, m, init);
      build(z, m, r, init);
      pull(o, l, r);
    }
  }
  inline void tag(int o, int l, int r, int v) { /**/ }
  inline void push(int o, int l, int r) { MYZ; /**/ }
  inline void pull(int o, int l, int r) { MYZ; /**/ }
  void modify(int o,int l,int r,int ql,int qr, V v) {
    if (r <= ql or qr <= l) return;
    if (ql <= l and r <= qr) {
      tag(o, l, r, v); // TODO
      return;
    }
    MYZ; push(o, l, r);
    modify(y, l, m, ql, qr, v);
    modify(z, m, r, ql, qr, v);
    pull(o, l, r);
  }
  Node query(int o, int l, int r, int ql, int qr) {
    if (r <= ql or qr <= l) return Node{};
    if (ql <= l and r <= qr) return ary[o]; // TODO
    MYZ; push(o, l, r);
    return query(y, l, m, ql, qr)
         + query(z, m, r, ql, qr);
  }
#undef MYZ
};
