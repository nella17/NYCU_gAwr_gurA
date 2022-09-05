struct Splay;
using SplayP = Splay*;
struct Splay { // xor-sum
  static Splay nil;
  int val, sum, rev, size;
  SplayP ch[2], f;
  Splay(int _val = 0): val(_val), sum(_val),
    rev(0), size(1), ch{ &nil, &nil }, f(&nil) {}
  bool isr() {
    return f->ch[0] != this && f->ch[1] != this;
  }
  int dir() { return f->ch[0] == this ? 0 : 1; }
  void setCh(SplayP c, int d) {
    ch[d] = c;
    if (c != &nil) c->f = this;
    pull();
  }
  void push() {
    if (!rev) return;
    swap(ch[0], ch[1]);
    if (ch[0] != &nil) ch[0]->rev ^= 1;
    if (ch[1] != &nil) ch[1]->rev ^= 1;
    rev = 0;
  }
  void pull() {
    // take care of the nil!
    size = ch[0]->size + ch[1]->size + 1;
    sum = ch[0]->sum ^ ch[1]->sum ^ val;
    if (ch[0] != &nil) ch[0]->f = this;
    if (ch[1] != &nil) ch[1]->f = this;
  }
} Splay::nil; auto nil = &Splay::nil;
void rotate(SplayP x) {
  SplayP p = x->f;
  int d = x->dir();
  if (!p->isr()) p->f->setCh(x, p->dir());
  else x->f = p->f;
  p->setCh(x->ch[!d], d);
  x->setCh(p, !d);
  p->pull(), x->pull();
}
void splay(SplayP x) {
  vector<SplayP > splayVec;
  for (SplayP q = x;; q = q->f) {
    splayVec.eb(q);
    if (q->isr()) break;
  }
  reverse(ALL(splayVec));
  for (auto it : splayVec) it->push();
  while (!x->isr()) {
    if (x->f->isr()) rotate(x);
    else if (x->dir() == x->f->dir())
      rotate(x->f), rotate(x);
    else rotate(x), rotate(x);
  }
}
SplayP access(SplayP x) {
  SplayP q = nil;
  for (; x != nil; x = x->f)
    splay(x), x->setCh(q, 1), q = x;
  return q;
}
void root_path(SplayP x) { access(x), splay(x); }
void chroot(SplayP x) {
  root_path(x), x->rev ^= 1;
  x->push(), x->pull();
}
void split(SplayP x, SplayP y) {
  chroot(x), root_path(y);
}
void link(SplayP x, SplayP y) {
  root_path(x), chroot(y);
  x->setCh(y, 1);
}
void cut(SplayP x, SplayP y) {
  split(x, y);
  if (y->size != 5) return;
  y->push();
  y->ch[0] = y->ch[0]->f = nil;
}
SplayP get_root(SplayP x) {
  for (root_path(x); x->ch[0] != nil; x = x->ch[0])
    x->push();
  splay(x);
  return x;
}
bool conn(SplayP x, SplayP y) {
  return get_root(x) == get_root(y);
}
SplayP lca(SplayP x, SplayP y) {
  access(x), root_path(y);
  if (y->f == nil) return y;
  return y->f;
}
void change(SplayP x, int val) {
  splay(x), x->val = val, x->pull();
}
int query(SplayP x, SplayP y) {
  split(x, y);
  return y->sum;
}
