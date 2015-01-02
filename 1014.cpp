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
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int mat[3][3];

typedef struct Point {
    double x, y, z;
    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    inline Point operator - (Point p) {
        return Point(x - p.x, y - p.y, z - p.z);
    }

    inline Point operator * (Point p) {
        return Point(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
    }

    inline Point operator * (double d) {
        return Point(x * d, y * d, z * d);
    }

    inline Point operator / (double d) {
        return Point(x / d, y / d, z / d);
    }

    inline double operator ^ (Point p) {
        return (x * p.x + y * p.y + z * p.z);
    }
} Point;

inline double volume(Point a, Point b, Point c, Point d) {
    return fabs((b - a) * (c - a) ^ (d - a)) / 6.0;
}

int main() {
    while(scanf("%d%d%d", &mat[0][0], &mat[0][1], &mat[0][2]) != EOF) {
        int p[8][3] = {{0, 0, 0},
                       {0, 0, 1},
                       {1, 0, 1},
                       {1, 1, 1},
                       {0, 1, 1},
                       {1, 1, 0},
                       {1, 0, 0},
                       {0, 1, 0}};
        for(int i = 1; i < 3; ++ i)
            for(int j = 0; j < 3; ++ j)
                scanf("%d", &mat[i][j]);
        vector <Point> rec;
        for(int i = 0; i < 8; ++ i) {
            int tmpp[3] = {};
            for(int j = 0; j < 3; ++ j)
                for(int k = 0; k < 3; ++ k)
                    tmpp[j] += p[i][k] * mat[j][k];
            Point tmp(tmpp[0], tmpp[1], tmpp[2]);
            rec.push_back(tmp);
        }
        double ans = 0.0;
        ans = volume(rec[0], rec[1], rec[2], rec[3]) + \
              volume(rec[0], rec[2], rec[3], rec[6]) + \
              volume(rec[0], rec[3], rec[5], rec[6]) + \
              volume(rec[0], rec[1], rec[3], rec[4]) + \
              volume(rec[0], rec[3], rec[4], rec[5]) + \
              volume(rec[0], rec[4], rec[5], rec[7]);
        printf("%.2lf\n", ans);
    }
    return 0;
}

