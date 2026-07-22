<------------------------------------------------------------------------->
T cross(pt v, pt w) {
    return (v.x*w.y-v.y*w.x);
}

// بيجيب الزاوية بين 2 فيكتور
T angle(pt v, pt w) {
    return acos(clamp(dot(v, w)/abs(v)/abs(w), (T)-1.0, (T)1.0));
}

// لو انا عندي خط من a ل b ال c هتكون علي شمالو ولا يمينو
T orient(pt a, pt b, pt c) {
    return cross(b-a, c-a);
}

// بيجيب زاوية نقطة بالنسبة لنقطتين عكس عقارب الساعة
T orientedAngle(pt a, pt b, pt c) {
    ld angl = angle(b-a, c-a);
    if (orient(a, b, c) > -EPS) {
        return angl;
    }
    else {
        return 2*PI-angl;
    }
}

<------------------------------------------------------------------------->

T cross(pt v, pt w) {
    return (v.x*w.y-v.y*w.x);
}
// لو انا عندي خط من a ل b ال c هتكون علي شمالو ولا يمينو
T orient(pt a, pt b, pt c) {
    return cross(b-a, c-a);
}

bool inAngle(pt a, pt b, pt c, pt p) {
    T abp = orient(a, b, p), acp = orient(a, c, p), abc = orient(a, b, c);
    if (abc < 0)swap(abp, acp);
    return (abp >= 0 && acp <= 0)^(abc < 0);
}

<------------------------------------------------------------------------->

T angle_x(pt v) {
    T ang = atan2(v.y, v.x);
    if (ang < -EPS)
        ang += 2 * PI;
    return ang;
}
