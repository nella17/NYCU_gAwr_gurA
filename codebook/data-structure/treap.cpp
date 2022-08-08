struct Treap;
using TreapP = Treap*;
struct Treap {
  int sz, data;
  TreapP l, r;
  Treap(int k): sz(1), data(k), l(0), r(0) {}
};
inline int sz(TreapP o) { return o ? o->sz : 0; }
void pull(TreapP o) { o->sz = sz(o->l)+sz(o->r)+1; }
void push(TreapP o) {}
TreapP merge(TreapP a, TreapP b) {
  if (!a or !b) return a ? a : b;
  TreapP r; // new{ r <- ab }
  if (randint(sz(a)+sz(b)) < sz(a))
       r = a, push(r), r->r = merge(a->r, b);
  else r = b, push(r), r->l = merge(a, b->l);
  return pull(r), r;
}
void split(TreapP o, TreapP &a, TreapP &b, int k) {
  if (!o) return a = b = 0, void();
  push(o);
  if (o->data <= k) // new { ab <- o }
       a = o, split(o->r, a->r, b, k), pull(a);
  else b = o, split(o->l, a, b->l, k), pull(b);
}
void split2(TreapP o, TreapP &a, TreapP &b, int k) {
  if (sz(o) <= k) return a = o, b = 0, void();
  push(o);
  if (sz(o->l) + 1 <= k) // new { ab <- o }
    a = o, split2(o->r, a->r, b, k - sz(o->l) - 1);
  else b = o, split2(o->l, a, b->l, k);
  pull(o); // a b
}
TreapP kth(TreapP o, int k) {
  if (k <= sz(o->l)) return kth(o->l, k);
  if (k == sz(o->l) + 1) return o;
  return kth(o->r, k - sz(o->l) - 1);
}
int Rank(TreapP o, int key) {
  if (o->data < key)
    return sz(o->l) + 1 + Rank(o->r, key);
  else return Rank(o->l, key);
}
bool erase(TreapP &o, int k) {
  if (!o) return 0;
  if (o->data == k) {
    TreapP t = o;
    push(o), o = merge(o->l, o->r);
    delete t;
    return 1;
  }
  TreapP &t = k < o->data ? o->l : o->r;
  return erase(t, k) ? pull(o), 1 : 0;
}
void insert(TreapP &o, int k) {
  TreapP a, b;
  split(o, a, b, k);
  o = merge(a, merge(new Treap(k), b));
}
void interval(TreapP &o, int l, int r) {
  TreapP a, b, c;
  split2(o, a, b, l - 1), split2(b, b, c, r);
  // operate
  o = merge(a, merge(b, c));
}
