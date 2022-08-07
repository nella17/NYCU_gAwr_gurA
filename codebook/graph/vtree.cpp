vector<int> vG[MAXN];
int top, st[MAXN];
void insert(int u) {
  if (top == -1) return st[++top] = u, void();
  int p = LCA(st[top], u);
  if (p == st[top]) return st[++top] = u, void();
  while (top >= 1 and dep[st[top-1]] >= dep[p])
    vG[st[top-1]].eb(st[top]), --top;
  if (st[top] != p)
    vG[p].eb(st[top]), --top, st[++top] = p;
  st[++top] = u;
}
void reset(int u) {
  for (int i : vG[u]) reset(i);
  vG[u].clear();
}
void solve(vector<int> &v) {
  top = -1;
  sort(ALL(v),[&](int a,int b){return dfn[a]<dfn[b];});
  for (int i : v) insert(i);
  while (top > 0) vG[st[top-1]].eb(st[top]), --top;
  // do something
  reset(v[0]);
}
