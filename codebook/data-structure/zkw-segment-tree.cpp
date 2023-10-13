const int N = 200000;
struct segtree {
  int n;
  Node tr[N*2], tag[N];
  void upd(int p, Node d, int h) {
    tr[p] += d<<h;
    if(p < n) tag[p] += d;
  }
  void push(int p) {
    for(int h = __lg(n); h >= 0; h--) {
      int i = p>>h;
      if(!tag[i/2]) continue;
      upd(i,tag[i/2],h);
      upd(i^1,tag[i/2],h);
      tag[i/2] = 0;
    }
  }
  Node query(int l, int r) {
    Node resl=0, resr=0; // initialized as identity
    push(l+n), push(r-1+n);
    for(l+=n,r+=n; l<r; l>>=1,r>>=1) {
      if(l&1) resl = resl + tr[l++];
      if(r&1) resr = tr[--r] + resr;
    }
    return resl + resr;
  }
  void pull(int p) {
    for(int h=1; p>1; p>>=1, h++)
	  tr[p>>1] = tr[p^1]+tr[p] + (tag[p>>1]<<h);
  }
  
  void add(int l,int r,Node k) {
    int tl = l, tr = r, h = 0;
    push(l+n), push(r-1+n);
    for(l+=n, r+=n; l<r; l/=2, r/=2, h++) {
      if(l&1) upd(l++,k,h);
      if(r&1) upd(--r,k,h);
    }
    pull(tl+n), pull(tr-1+n);
  }
  void init(ll v[],int _n) {
    n = _n;
    for(int i = 0; i < n; i++) tr[i+n] = v[i];
    for(int i = n-1; i > 0; i--)
      tr[i] = tr[i*2]+tr[i*2|1];
  }
} sgt;
