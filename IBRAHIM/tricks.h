void tackpoint(pt &p) {
    int xx, yy; cin >> xx >> yy;
    T xxx = xx, yyy = yy;
    p = {xxx, yyy};
}

<------------------------------------------------------------------------->
////////////////////////transform////////////////////

pt translate(pt v, pt p) {
    return p+v;
}
pt scale(pt c, T factor, pt p) {
    return c + (p-c)*factor;
}
pt rot(pt p, T a) {
    return {p.x*cos(a)- p.y*sin(a), p.x*sin(a) + p.y*cos(a)};
}
pt linearTransfo(pt p, pt q, pt r, pt fp, pt fq) {
    return fp + (r-p) * (fq-fp) / (q-p);
}
