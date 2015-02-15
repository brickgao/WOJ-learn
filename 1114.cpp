//By Brickgao
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#define out(v) cout << #v << " " << v << endl
#define pb push_back
#define PI acos(-1.0)
using namespace std;
typedef long long lint;
const int inf = 1e9 + 7;
const double eps = 1e-10;
inline int sgn(const double x) {return (x > eps) - (x < -eps);}
template <class T> T _abs(T x) {if(x < 0) x = -x; return x;}
template <class T> bool get_max(T &a, const T b) {return a < b ? a = b, true : false;}
template <class T> bool get_min(T &a, const T b) {return a > b ? a = b, true : false;}
template <class T> void _swap(T &a, T &b) {T t = a; a = b; b = t;}

double radii[5] = {3, 6, 9, 12, 15};
int score[5] = {100, 80, 60, 40, 20};

int main() {
    double pos_x[20], pos_y[20];
    while(cin >> pos_x[0] >> pos_y[0]) {
        int score_1 = 0, score_2 = 0;
        for(int i = 1; i < 6; ++ i) {
            cin >> pos_x[i] >> pos_y[i];
        }
        if(sgn(pos_x[0] + 100) == 0)
            return 0;
        for(int i = 0; i < 6; ++ i) {
            double dis = pos_x[i] * pos_x[i] + pos_y[i] * pos_y[i];
            int score_get = 0;
            for(int j = 0; j < 5; ++ j) {
                if(sgn(radii[j] * radii[j] - dis) >= 0) {
                    score_get = score[j];
                    break;
                }
            }
            if(i < 3)
                score_1 += score_get;
            else
                score_2 += score_get;
        }
        printf("SCORE: %d to %d, ", score_1, score_2);
        if(score_1 == score_2)
            puts("TIE.");
        else if(score_1 > score_2)
            puts("PLAYER 1 WINS.");
        else
            puts("PLAYER 2 WINS.");
    }
    return 0;
}
