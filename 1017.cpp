//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
const double eps = 1e-8;
inline int sgn(const double x) {return (x > eps) - (x < -eps);}
template <class T> T _abs(T x) {if(x < 0) x = -x; return x;}
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

struct pnt {
    double x, y;
    pnt(){}
    pnt(double _x, double _y) : x(_x), y(_y) {}
}p[110];
struct vct{double x, y;};
struct seg{pnt s, t; double a, b, c;};
const pnt o = pnt(0.0, 0.0);

vct operator - (pnt t, pnt s) {
    vct ret = {t.x - s.x, t.y - s.y};
    return ret;
}

seg operator ^ (pnt s, pnt t) {
    double a = s.y - t.y;
    double b = t.x - s.x;
    double c = -(a * s.x + b * s.y);
    seg ret = {s, t, a, b, c};
    return ret;
}

double operator * (vct a, vct b) {
    return a.x * b.y - a.y * b.x;
}

double operator ^ (vct a, vct b) {
    return a.x * b.x + a.y * b.y;
}

double dis(pnt a, pnt b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dis(pnt a, seg b) {
    double s = (b.t - b.s) * (a - b.s);
    if(((b.t - b.s) ^ (a - b.s)) > 0.0 && ((b.s - b.t) ^ (a - b.t)) > 0.0)
        return _abs(s / dis(b.s, b.t));
    return min(dis(a, b.s), dis(a, b.t));
}

double getS(pnt *p, int n) {
    double ret = 0.0;
    for(int i = 0; i < n; i ++)
        ret += (p[i] - o) * (p[(i+1)%n] - o);
    return ret / 2.0;
}

bool isIntersect(seg a, seg b) {
    if(max(a.s.x, a.t.x) < min(b.s.x, b.t.x) - eps ||
       max(a.s.y, a.t.y) < min(b.s.y, b.t.y) - eps ||
       max(b.s.x, b.t.x) < min(a.s.x, a.t.x) - eps ||
       max(b.s.y, b.t.y) < min(a.s.y, a.t.y) - eps)
        return false;
    if(((a.t - a.s) * (b.t - a.s)) * ((a.t - a.s) * (b.s - a.s)) > eps ||
       ((b.t - b.s) * (a.t - b.s)) * ((b.t - b.s) * (a.s - b.s)) > eps)
        return false;
    return true;
}

pnt intersect(seg a, seg b) {
    pnt p1 = a.s;
    pnt p2 = a.t;
    pnt p3 = b.s;
    pnt p4 = b.t;
    double x = (p3.x - p4.x) * ((p1 - o) * (p2 - o)) - (p1.x - p2.x) * ((p3 - o) * (p4 - o));
    double y = (p3.y - p4.y) * ((p1 - o) * (p2 - o)) - (p1.y - p2.y) * ((p3 - o) * (p4 - o));
    double t = (p2 - p1) * (p4 - p3);
    pnt ret(x / t, y / t);
    return ret;
}

pnt mirror(seg s, pnt p) {
    vct tmpv = s.s - s.t;
    pnt tmpp;
    if(sgn(tmpv.y) == 0) {
        tmpp.x = p.x, tmpp.y = p.y + double(maxint);
    }
    else {
        double k = - tmpv.x / tmpv.y;
        tmpp.x = p.x + double(maxint), tmpp.y = p.y + k * double(maxint);
    }
    seg stmp;
    stmp.s = tmpp, stmp.t = p;
    pnt intersect_point = intersect(s, stmp);
    intersect_point.x *= 2.0, intersect_point.y *= 2.0;
    tmpv = intersect_point - p;
    return pnt(tmpv.x, tmpv.y);
}

bool cmp(pnt a, pnt b) {
    if(!sgn((a - p[0]) * (b - p[0])))
        return dis(a, p[0]) < dis(b, p[0]);
    return (a - p[0]) * (b - p[0]) > 0;
}

int n;

int main() {
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; ++ i) {
            vector <pnt> v;
            for(int j = 0; j < 3; ++ j) {
                int a, b;
                scanf("%d%d", &a, &b);
                pnt tmp(a, b);
                v.push_back(tmp);
            }
            vct tmpv = v[0] - v[1];
            pnt tmpp;
            if(sgn(tmpv.y) == 0) {
                tmpp.x = v[2].x, tmpp.y = v[2].y + double(maxint);
            }
            else {
                double k = - tmpv.x / tmpv.y;
                tmpp.x = v[2].x + double(maxint), tmpp.y = v[2].y + k * double(maxint);
            }
            seg s1, s2, s3;
            s1.s = v[0], s1.t = v[1];
            s2.s = tmpp, s2.t = v[2];
            pnt foot_point = intersect(s1, s2);
            s1.s = v[0], s1.t = v[2];
            s2.s = v[1], s2.t = v[2];
            pnt p1 = mirror(s1, foot_point), p2 = mirror(s2, foot_point);
            s3.s = p1, s3.t = p2;
            double ans = dis(intersect(s1, s3), foot_point) + \
                         dis(intersect(s2, s3), foot_point) + \
                         dis(intersect(s2, s3), intersect(s1, s3));
            printf("%.3lf\n", ans);
        }
    }
    return 0;
}

