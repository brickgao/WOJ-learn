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

typedef struct Point {
    int x, y;
} Point;

bool cmp(Point a, Point b) {
    if(a.y == b.y)
        return a.x < b.x;
    else
        return a.y < b.y;
}

int n;

int main() {
    while(scanf("%d", &n) != EOF) {
        vector <Point> rec1, rec2;
        for(int i = 0; i < n; ++ i) {
            Point tmp;
            scanf("%d%d", &tmp.x, &tmp.y);
            rec1.push_back(tmp), rec2.push_back(tmp);
        }
        sort(rec1.begin(), rec1.end(), cmp);
        sort(rec2.begin(), rec2.end(), cmp);
        int line = -1;
        if(n % 2 == 0) {
            line = (rec1[SZ(rec1) / 2].y + rec1[SZ(rec1) / 2 - 1].y);
        }
        else {
            line = rec1[SZ(rec1) / 2].y * 2;
        }
        for(int i = 0; i < SZ(rec2); ++ i)
            rec2[i].y = line - rec2[i].y;
        sort(rec2.begin(), rec2.end(), cmp);
        bool flag = true;
        for(int i = 0; i < SZ(rec2); ++ i)
            if(rec2[i].x != rec1[i].x || rec2[i].y != rec1[i].y) {
                flag = false;
                break;
            }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

