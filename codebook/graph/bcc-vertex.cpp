vector<int> G[MAXN]; // 1-base
vector<int> nG[MAXN], bcc[MAXN];
int low[MAXN], dfn[MAXN], Time;
int bcc_id[MAXN], bcc_cnt; // 1-base
bool is_cut[MAXN]; // whether is av
bool cir[MAXN];
int st[MAXN], top;
void dfs(int u, int pa = -1) {
  int child = 0;
  low[u] = dfn[u] = ++Time;
  st[top++] = u;
  for (int v : G[u])
    if (!dfn[v]) {
      dfs(v, u), ++child;
      low[u] = min(low[u], low[v]);
      if (dfn[u] <= low[v]) {
        is_cut[u] = 1;
        bcc[++bcc_cnt].clear();
        int t;
        do {
          bcc_id[t = st[--top]] = bcc_cnt;
          bcc[bcc_cnt].eb(t);
        } while (t != v);
        bcc_id[u] = bcc_cnt;
        bcc[bcc_cnt].eb(u);
      }
    } else if (dfn[v] < dfn[u] and v != pa)
      low[u] = min(low[u], dfn[v]);
  if (pa == -1 and child < 2) is_cut[u] = 0;
}
void bcc_init(int n) {
  Time = bcc_cnt = top = 0;
  for (int i = 1; i <= n; ++i)
    G[i].clear(), dfn[i] = bcc_id[i] = is_cut[i] = 0;
}
void bcc_solve(int n) {
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) dfs(i);
  // circle-square tree
  for (int i = 1; i <= n; ++i)
    if (is_cut[i])
      bcc_id[i] = ++bcc_cnt, cir[bcc_cnt] = 1;
  for (int i = 1; i <= bcc_cnt and !cir[i]; ++i)
    for (int j : bcc[i]) if (is_cut[j])
      nG[i].eb(bcc_id[j]), nG[bcc_id[j]].eb(i);
}
