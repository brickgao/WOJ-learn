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

int main() {
    int cas = 1, n;
    int a[100100];
    while(scanf("%d", &n) != EOF) {
        if(n == -1)
            return 0;
        for(int i = 0; i < n; ++ i)
            scanf("%d", &a[i]);
        int ans = 0;
        bool flag = true;
        while(flag) {
            flag = false;
            for(int i = 1; i < n; ++ i) {
                if(a[i - 1] == 1 && a[i] == -1) {
                    a[i] = 1;
                    a[i - 1] = -1;
                    flag = true;
                    ++ ans;
                }
            }
        }
        printf("Case %d: %d\n", cas ++, ans);
    }
    return 0;
}
