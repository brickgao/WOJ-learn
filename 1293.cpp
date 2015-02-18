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
#define SZ(v) ((int)(v).size())
#define PI acos(-1.0)
using namespace std;
typedef long long lint;
const int inf = 1e9 + 7;
const double eps = 1e-8;
inline int sgn(const double x) {return (x > eps) - (x < -eps);}
template <class T> T _abs(T x) {if(x < 0) x = -x; return x;}
template <class T> bool get_max(T &a, const T b) {return a < b ? a = b, true : false;}
template <class T> bool get_min(T &a, const T b) {return a > b ? a = b, true : false;}
template <class T> void _swap(T &a, T &b) {T t = a; a = b; b = t;}
    
int mat[21][21];

int main() {
    int m, n;
    int cnt = 0;
    for(int i = 0; i < 10; ++ i) {
        int x = i, y = 0;
        mat[x][y] = cnt ++;
        for(int j = 0; j < i; ++ j) {
            -- x, ++ y;
            mat[x][y] = cnt ++;
        }
    }
    while(scanf("%d%d", &m, &n) != EOF) {
        if(m == 0 && n == 0)
            break;
        for(int i = n - 1; i >= 0; -- i) {
            for(int j = 0; j < n - i; ++ j) {
                printf("%2d", mat[i][j] + m);
                printf(" ");
            }
            puts("");
        }
        puts("");
    }
    return 0;
}
