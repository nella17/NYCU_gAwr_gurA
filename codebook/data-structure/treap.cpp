struct Treap {
  int data, sz;
  Treap *l, *r;
  Treap(int k) : data(k), sz(1), l(0), r(0) {}
};
inline int sz(Treap *o) { return o ? o->sz : 0; }
void pull(Treap *o) { o->sz = sz(o->l) + sz(o->r) + 1; }
void push(Treap *o) {}
Treap *merge(Treap *a, Treap *b) {
  if (!a || !b) return a ? a : b;
  if (randint(sz(a)+sz(b)) < sz(a))
    return push(a), a->r = merge(a->r, b), pull(a), a;
  return push(b), b->l = merge(a, b->l), pull(b), b;
}
void split(Treap *o, Treap *&a, Treap *&b, int k) {
  if (!o) return a = b = 0, void();
  push(o);
  if (o->data <= k)
    a = o, split(o->r, a->r, b, k), pull(a);
  else b = o, split(o->l, a, b->l, k), pull(b);
}
void split2(Treap *o, Treap *&a, Treap *&b, int k) {
  if (sz(o) <= k) return a = o, b = 0, void();
  push(o);
  if (sz(o->l) + 1 <= k)
    a = o, split2(o->r, a->r, b, k - sz(o->l) - 1);
  else b = o, split2(o->l, a, b->l, k);
  pull(o);
}
Treap *kth(Treap *o, int k) {
  if (k <= sz(o->l)) return kth(o->l, k);
  if (k == sz(o->l) + 1) return o;
  return kth(o->r, k - sz(o->l) - 1);
}
int Rank(Treap *o, int key) {
  if (o->data < key)
    return sz(o->l) + 1 + Rank(o->r, key);
  else return Rank(o->l, key);
}
bool erase(Treap *&o, int k) {
  if (!o) return 0;
  if (o->data == k) {
    Treap *t = o;
    push(o), o = merge(o->l, o->r);
    delete t;
    return 1;
  }
  Treap *&t = k < o->data ? o->l : o->r;
  return erase(t, k) ? pull(o), 1 : 0;
}
void insert(Treap *&o, int k) {
  Treap *a, *b;
  split(o, a, b, k);
  o = merge(a, merge(new Treap(k), b));
}
void interval(Treap *&o, int l, int r) {
  Treap *a, *b, *c;
  split2(o, a, b, l - 1), split2(b, b, c, r);
  // operate
  o = merge(a, merge(b, c));
}
