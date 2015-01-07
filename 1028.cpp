//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int n;

typedef struct Point {
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
} Point;

int main() {
    int t;
    while(scanf("%d", &t) != EOF) {
        for(int T = 1; T <= t; ++ T) {
            if(T != 1)  puts("");
            scanf("%d", &n);
            Point p1, p2;
            scanf("%d%d", &p1.x, &p1.y);
            scanf("%d%d", &p2.x, &p2.y);
            int difx = abs(p1.x - p2.x), dify = abs(p1.y - p2.y);
            if(abs(difx - dify) % 2 != 0) {
                printf("Case %d:\n-1\n", T);
            }
            else {
                printf("Case %d:\n%d\n", T, max(dify, difx));
            }
        }
    }
    return 0;
}

