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
    string s1, s2;
    while(cin >> s1) {
        if(s1 == "#")
            break;
        cin >> s2;
        int cnt = 0;
        for(int i = 0; i < SZ(s1); ++ i) {
            if(s1[i] == 'A' && s2[i] == 'T')
                ++ cnt;
            if(s2[i] == 'A' && s1[i] == 'T')
                ++ cnt;
            if(s1[i] == 'G' && s2[i] == 'C')
                ++ cnt;
            if(s2[i] == 'G' && s1[i] == 'C')
                ++ cnt;
        }
        cnt = SZ(s1) - cnt;
        cout << cnt << endl;
    }
    return 0;
}
