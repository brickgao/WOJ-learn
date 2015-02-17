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

int dfs(int u) {
    int tmp = u;
    if(u == 1) {
        return 1;
    }
    if(tmp % 2)
        tmp = 3 * tmp + 1;
    else
        tmp /= 2;
    int ret = dfs(tmp);
    return ret + 1;
}

int main() {
    int begin, end;
    while(scanf("%d%d", &begin, &end) != EOF) {
        if(begin == 0 && end == 0)
            break;
        int ans = 0;
        if(begin > end)
            _swap(begin, end);
        for(int i = begin; i <= end; ++ i) {
            get_max(ans, dfs(i));
        }
        printf("%d\n", ans);
    }
    return 0;
}
