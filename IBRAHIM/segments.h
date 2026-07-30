
T cross(pt v, pt w) {
    return (v.x*w.y-v.y*w.x);
}

// لو انا عندي خط من a ل b ال c هتكون علي شمالو ولا يمينو
T orient(pt a, pt b, pt c) {
    return cross(b-a, c-a);
}

int sgn(T val){
    if(val > EPS) return 1;
    if(val < -EPS) return -1;
    return 0;
}

// dot prodect (V1 . V2)
T dot(pt v, pt w) {
    return v.x*w.x+v.y*w.y;
}

//بتشوف هل بوينت في الدايرة اللي السيجمنت ده قطر فيها ولا لا
bool inDisk(pt a, pt b, pt p) {
    return dot(a-p, b-p) <= EPS;
}

//check if point p between segment a, b
bool onSegment(pt a, pt b, pt c){
    return sgn(orient(a, b, c)) == 0 && inDisk(a, b, c);
}
<------------------------------------------------------------------------->
struct line {
    pt v; T c;
    //line for two point
    line(pt p, pt q) {
        v = q-p;
        c = cross(v, p);
    }

    T side(pt p) {
        return cross(v, p)-c;
    }
    // dist from point p to line
    ld dist(pt p) {
        return abs(side(p))/abs(v);
    }
    // بترجع هل P قبل ال q ولا لا
    bool cmpProj(pt p, pt q) {
        return dot(v, p) < dot(v, q);
    }
};

// المسافة بين بوينت وسيجمانت
ld segPoint(pt a, pt b, pt p) {
    if (a != b) {
        line l(a,b);
        if (l.cmpProj(a,p) && l.cmpProj(p,b)) // if closest to projection
            return l.dist(p); // output distance to line
    }
    return min(abs(p-a), abs(p-b)); // otherwise distance to A or B
}

// المسافة بين سجمانت وسيجمانت
ld segSeg(pt a, pt b, pt c, pt d) {
    pt dummy;
    if (properInter(a,b,c,d,dummy))
        return 0;
    return min({segPoint(a,b,c), segPoint(a,b,d),
                segPoint(c,d,a), segPoint(c,d,b)});
}
<------------------------------------------------------------------------->

int sgn(T val){
    if(val > EPS) return 1;
    if(val < -EPS) return -1;
    return 0;
}

T cross(pt v, pt w) {
    return (v.x*w.y-v.y*w.x);
}

// dot prodect (V1 . V2)
T dot(pt v, pt w) {
    return v.x*w.x+v.y*w.y;
}

// لو انا عندي خط من a ل b ال c هتكون علي شمالو ولا يمينو
T orient(pt a, pt b, pt c) {
    return cross(b-a, c-a);
}

//بتشوف هل بوينت في الدايرة اللي السيجمنت ده قطر فيها ولا لا
bool inDisk(pt a, pt b, pt p) {
    return dot(a-p, b-p) <= EPS;
}
//check if point p between segment a, b
bool onSegment(pt a, pt b, pt c){
    return sgn(orient(a, b, c)) == 0 && inDisk(a, b, c);
}
bool properInter(pt a, pt b, pt c, pt d, pt &out) {
    T oa = orient(c,d,a),
            ob = orient(c,d,b),
            oc = orient(a,b,c),
            od = orient(a,b,d);
    // Proper intersection exists iff opposite signs
    if (sgn(oa)*sgn(ob) < 0 && sgn(oc)*sgn(od) < 0) {
        out = (a*ob - b*oa) / (ob-oa);
        return true;
    }
    return false;
}

// بيرجع النقاط اللي بتتقاطع فيها سيجمانت مع التانية
set<pair<ld,ld>> inters(pt a, pt b, pt c, pt d) {
    set<pair<ld,ld>> s;
    pt out;
    if(a == c || a == d){
        s.insert(make_pair(a.x, a.y));
    }
    if(b == c || b == d){
        s.insert(make_pair(b.x, b.y));
    }
    if(s.size()) return s;

    if (properInter(a,b,c,d,out)) return {make_pair(out.x, out.y)};
    if (onSegment(c,d,a)) s.insert(make_pair(a.x, a.y));
    if (onSegment(c,d,b)) s.insert(make_pair(b.x, b.y));
    if (onSegment(a,b,c)) s.insert(make_pair(c.x, c.y));
    if (onSegment(a,b,d)) s.insert(make_pair(d.x, d.y));
    return s;
}
