void convex_hull(vector<Pt> &dots) {
  sort(dots.begin(), dots.end());
  vector<Pt> A(1, dots[0]);
  const int sz = dots.size()
  for(int ct = 0; ct < 2; reverse(ALL(dots)), ++ct)
    for(int i = 1, t = A.size(); i < sz;
            A.emplace_back(dots[i++]))
      while (A.size() > t and
          ori(A[A.size()-2], A.back(), dots[i]) <= 0)
        A.pop_back();
  A.pop_back(), A.swap(dots);
}
