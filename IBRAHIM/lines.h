#define ld long double
const ld eps = 1e-12, PI = acosl(-1.0);

struct P {
   ld x, y;
   void read() {
      cin >> x >> y;
   }
   P operator-(P const &he) const {
      return {x - he.x, y - he.y};
   }

   // cross
   ot operator^(P const &he) const {
      return x * he.y - y * he.x;
   }

   // dot
   ot operator*(P const &he) const {
      return x * he.x + y * he.y;
   }
};
<------------------------------------------------------------------------->
struct line {
    ld a, b, c;
};
// يرجعلك معادلة الخط اللي عليه النقطتين
line linefromvec(P p, P v) {
    line L;
    L.a = v.y;
    L.b = -v.x;
    L.c = v.x*p.y-v.y*p.x;
    ld norm = sqrt(L.a*L.a+L.b*L.b);
    if (norm > 1e-12) L.a /= norm, L.b /= norm, L.c /= norm;
    if (L.a < 0 || (abs(L.a)< 1e-12 && L.b < 0))
        L.a = -L.a, L.b = -L.b, L.c = -L.c;
    return L;
}
<-------------------------------------------------------------------------->
ld cross(P v, P w) {
    return (v.x*w.y-v.y*w.x);
}
// a_b علي الخط C تقارن هل النقطة
bool cmp_line(P a, P b, P c) {
    return  (fabsl(cross({b.x-a.x,b.y-a.y},
                {c.x-a.x,c.y-a.y})) < eps);
}
<---------------------------------------------------------------------------->

void convexhull(vector<P> p, vector<P> &hull) {
    sort(all(p), [&](P &a, P &b) {
        if (a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    });
    if (p.size() == 1) {
        hull.push_back(p[0]);
        return;
    }
    for (int rep = 0; rep < 2; rep++) {
        int s = hull.size();
        for (int i = 0; i < p.size(); i++) {
            while (hull.size() >= s+2) {
                P p1 = hull.end()[-2];
                P p2 = hull.end()[-1];
                if ((vec(p1, p2) ^ vec(p1, p[i])) < -eps)
                    break;
                hull.pop_back();
            }
            hull.push_back(p[i]);
        }
        reverse(all(p));
        hull.pop_back();
    }
}
