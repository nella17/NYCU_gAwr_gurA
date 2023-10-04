using Dt = ld;
using Pt = pair<Dt,Dt>;
using Vt = Pt;
using Line = pair<Pt,Pt>;
const double eps = 1e-9;
bool isZ(Dt x) { return -eps < x and x < eps; }
Pt operator+(Pt a,Pt b){return {a.ft+b.ft,a.sd+b.sd};}
Pt operator-(Pt a,Pt b){return {a.ft-b.ft,a.sd-b.sd};}
Pt operator*(Pt a,Dt k){return { a.ft*k, a.sd*k }; }
Pt operator/(Pt a,Dt k){return { a.ft/k, a.sd/k }; }
Dt dot(Vt a, Vt b)   { return a.ft*b.ft + a.sd*b.sd; }
Dt cross(Vt a, Vt b) { return a.ft*b.sd - a.sd*b.ft; }
Dt abs2(Vt a) { return dot(a,a); }
ld abs(Vt a) { return sqrt(dot(a,a));}
int sign(Dt x) { return isZ(x) ? 0 : x > 0 ? 1 : -1; }
int ori(Pt p1, Pt p2, Pt p3) {
  return sign(cross(p2 - p1, p3 - p2));}
bool collinearity(Pt p1, Pt p2, Pt p3) {
  return isZ(cross(p1 - p3, p2 - p3)); }
bool btw(Pt p1, Pt p2, Pt p3) {
  if(!collinearity(p1, p2, p3)) return 0;
  return sign(dot(p1 - p3, p2 - p3)) <= 0;
}
bool seg_intersect(Pt p1, Pt p2, Pt p3, Pt p4) {
  int a123 = ori(p1, p2, p3);
  int a124 = ori(p1, p2, p4);
  int a341 = ori(p3, p4, p1);
  int a342 = ori(p3, p4, p2);
  if(a123 == 0 && a124 == 0)
    return btw(p1, p2, p3) or btw(p1, p2, p4)
        or btw(p3, p4, p1) or btw(p3, p4, p2);
  return a123 * a124 <= 0 && a341 * a342 <= 0;
}
Pt intersect(Pt p1, Pt p2, Pt p3, Pt p4) {
  Dt a123 = cross(p2 - p1, p3 - p1);
  Dt a124 = cross(p2 - p1, p4 - p1);
  return (p4 * a123 - p3 * a124) / (a123 - a124);
}
Vt perp(Vt a) { return Vt{ -a.sd, a.ft }; }
Pt projection(Pt a, Pt b, Pt p) {
    return (b - a) * dot(p - a, b - a) / abs2(b - a); }
