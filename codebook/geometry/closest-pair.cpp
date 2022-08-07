struct cmp_y { bool operator()(const Pt &a,
        const Pt &b) const { return a.sd < b.sd; } };
ld solve(vector<Pt> &v) {
  multiset<Pt, cmp_y> s{};
  ld ans = 1e20;
  auto upd_ans = [&](Pt a, Pt b) {
    ld dist = abs(a-b);
    if (ans > dist) ans = dist; };
  s.clear();
  sort(ALL(v), [](Pt a, Pt b) { return a.ft < b.ft
          or (a.ft == b.ft and a.sd < b.sd); });
  for (int i = 0, l = 0, n = v.size(); i < n; i++) {
    while (l < i && v[i].ft - v[l].ft >= ans)
        s.erase(s.find(v[l++]));
    auto it = s.lower_bound(Pt{v[i].ft,v[i].sd - ans});
    while (it != s.end() and it->sd - v[i].sd < ans)
      upd_ans(*it++, v[i]);
    s.insert(v[i]);
  }
  return ans;
}
