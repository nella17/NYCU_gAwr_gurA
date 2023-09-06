// if there are multi-edges, then they are not bridges
void dfs(int c, int p) {
  tin[c] = low[c] = ++t;
  st.push(c);
  for (auto [x,i]: G[c]) if (x != p) {
      if (tin[x]) {
        low[c] = min(low[c], tin[x]);
        continue;
      }
      dfs(x, c);
      low[c] = min(low[c], low[x]);
      if (low[x] == tin[x]) br[i] = true;
    }
  if (tin[c] == low[c]) {
    ++sz;
    while (st.size()) {
      int u = st.top(); st.pop();
      bcc[u] = sz;
      if (u == c) break;
    }
  }
}
