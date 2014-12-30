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
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

inline int sgn(double x) {
    return (x > eps) - (x < -eps);
}

int main() {
    bool flag = false;
    double rec[3];
    string recs[3];
    while(cin >> rec[0] >> recs[0] >> rec[1] >> recs[1] >> rec[2] >> recs[2]) {
        if(flag)
            cout << endl;
        else
            flag = true;
        for(int i = 0; i < 3; ++ i) {
            if(recs[i] == "meters")
                rec[i] *= 100;
            if(recs[i] == "inches")
                rec[i] *= 45.72 / 18;
            if(recs[i] == "feet")
                rec[i] *= 137.16 / 450 * 100;
            if(recs[i] == "cubits")
                rec[i] *= 45.72;
        }
        if(sgn(rec[0] - rec[1]) == 0)
            cout << "Spin" << endl;
        else if(sgn(rec[0] / 6.0 - rec[1]) == 0)
            cout << "Excellent" << endl;
        else
            cout << "Neither" << endl;
    }
    return 0;
}

