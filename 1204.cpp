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
    int n;
    int rec[500010];
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; ++ i) {
            scanf("%d", &rec[i]);
        }
        sort(rec, rec + n);
        int ans = 0;
        for(int i = max(n / 2 - 5, 0); i < min(n / 2 + 5, n); ++ i) {
            int cnt = 0;
            for(int j = 0; j < n; ++ j) {
                if(rec[j] == rec[i])
                    ++ cnt;
            }
            if(cnt >= n / 2) {
                ans = rec[i];
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
