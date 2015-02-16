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

lint gcd(lint a, lint b) {
    return b ? gcd(b, a % b): a;
}

int main() {
    lint a, b, n;
    while(cin >> a >> b >> n) {
        if(a < b)
            _swap(a, b);
        if(b == 0) {
            if(a == 0) {
                if(n == 0)
                    puts("Possible!");
                else
                    puts("Impossible!");
            }
            else {
                if(n % a != 0)
                    puts("Impossible!");
                else
                    puts("Possible!");
            }
        }
        else {
            lint ret = gcd(a, b);
            if(n % ret != 0)
                puts("Impossible!");
            else
                puts("Possible!");

        }
    }
    return 0;
}
