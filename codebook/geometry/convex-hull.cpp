void convex_hull(vector<Pt> &dots) {
  sort(dots.begin(), dots.end());
  vector<Pt> ans(1, dots[0]);
  const int sz = dots.size()
  for(int ct = 0; ct < 2; reverse(ALL(dots)), ++ct)
    for(int i = 1, t = ans.size(); i < sz; ans.emplace_back(dots[i++]))
      while (ans.size() > t and ori(ans[ans.size()-2], ans.back(), dots[i]) <= 0)
        ans.pop_back();
  ans.pop_back(), ans.swap(dots);
}
