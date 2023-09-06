Pt ccCenter(const Pt &A, const Pt &B, const Pt &C) {
  Vt b = C - A, c = B - A;
  return A + perp(b * abs2(c) - c * abs2(b))
      / cross(b, c) / 2;
}
pair<Pt, ld> mec(vector<Pt> v) {
  shuffle(ALL(v), mt19937(time(0)));
  Pt o = v[0]; int sz = v.size();
  Dt r2 = 0, EPS = 1 + 1e-8; // ld
  for (int i = 0; i < sz; i++)
    if (abs2(v[i] - o) > r2 * EPS) {
      o = v[i], r2 = 0;
        for (int j = 0; j < i; j++)
          if (abs2(v[j] - o) > r2 * EPS) {
            o = (v[i] + v[j]) / 2;
            r2 = abs2(v[i] - o);
            for(int k = 0; k < j; ++k)
              if (abs2(v[k] - o) > r2 * EPS) {
                o = ccCenter(v[i], v[j], v[k]);
                r2 = abs2(v[i] - o);
  } } }
  return { o, sqrt(r2) };
}
