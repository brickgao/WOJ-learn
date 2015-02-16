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
    vector <lint> v;
    map <lint, int> dict;
    v.push_back(0);
    dict[0] = 1;
    for(int i = 1; i < 500010; ++ i) {
        int tmp = v[i - 1] - i;
        if(tmp < 0 || dict[tmp] == 1)
            tmp = v[i - 1] + i;
        dict[tmp] = 1;
        v.push_back(tmp);
    }
    int n;
    while(scanf("%d", &n) != EOF) {
        if(n == -1)
            return 0;
        else
            cout << v[n] << endl;
    }
    return 0;
}
