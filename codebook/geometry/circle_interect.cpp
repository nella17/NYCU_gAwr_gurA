struct Cir{ Pt O; Dt R; }; // Dt = ld
bool CCinter(Cir a, Cir b, Pt &p1, Pt &p2) {
  auto [o1,r1] = a; auto [o2,r2] = b;
  auto d2 = abs2(o1 - o2), d = sqrt(d2);
  if(d < max(r1, r2) - min(r1, r2) or d > r1 + r2)
      return 0;     Vt u = (o1+o2)*0.5
          + (o1-o2) * ((r2*r2 - r1*r1) / (2*d2));
  ld A = sqrt((r1 + r2 + d) * (r1 - r2 + d) *
          (r1 + r2 - d) * (-r1 + r2 + d));
  Vt v = perp(o2 - o1) * A / (2 * d2);
  p1 = u + v, p2 = u - v;
  return 1;
}
