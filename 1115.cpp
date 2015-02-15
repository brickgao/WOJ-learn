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
#define filn freopen("in.txt", "r", stdin)
#define flout freopen("out.txt", "w", stdout)
#define pb push_back
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
    string input_string;
    while(cin >> input_string) {
        lint m = 0, n = 0;
        for(int i = 1; i < int(input_string.size()); ++ i) {
            if(input_string[i] == 'C') {
                ++ i;
                for(; i < int(input_string.size()); ++ i) {
                    m *= 10;
                    m += input_string[i] - '0';
                }
                break;
            }
            n *= 10;
            n += input_string[i] - '0';
        }
        if(m == 0 && n == 0)
            return 0;
        string s = "";
        int tmp = 0;
        while(m > 0) {
            tmp = m % 26;
            if(tmp == 0)
                tmp = 26;
            m = (m - tmp) / 26;
            s = char('A' + tmp - 1) + s;
        }
        cout << s << n << endl;
    }
    return 0;
}
