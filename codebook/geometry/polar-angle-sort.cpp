Pt center; //sort base
int Quadrant(Pt a) {
  if(a.ft > 0 && a.sd >= 0) return 1;
  if(a.ft <= 0 && a.sd > 0) return 2;
  if(a.ft < 0 && a.sd <= 0) return 3;
  if(a.ft >= 0 && a.sd < 0) return 4;
}
bool cmp(Pt a, Pt b) { // integer
  a = a - center, b = b - center;
  if (Quadrant(a) != Quadrant(b))
    return Quadrant(a) < Quadrant(b);
  if (cross(b, a) == 0) return abs2(a) < abs2(b);
  return cross(a, b) > 0;
}
bool cmp(Pt a, Pt b) { // float
  a = a - center, b = b - center;
  if(isZ(atan2(a.sd, a.ft) - atan2(b.sd, b.ft)))
    return abs(a) < abs(b);
  return atan2(a.sd, a.ft) < atan2(b.sd, b.ft);
}
