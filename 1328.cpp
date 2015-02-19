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
    map <char, char> dict;
    dict['1'] = '`', dict['2'] = '1';
    dict['3'] = '2', dict['4'] = '3';
    dict['5'] = '4', dict['6'] = '5';
    dict['7'] = '6', dict['8'] = '7';
    dict['9'] = '8', dict['0'] = '9';
    dict['-'] = '0', dict['='] = '-';
    dict['W'] = 'Q', dict['E'] = 'W';
    dict['W'] = 'Q', dict['E'] = 'W';
    dict['R'] = 'E', dict['T'] = 'R';
    dict['Y'] = 'T', dict['U'] = 'Y';
    dict['I'] = 'U', dict['O'] = 'I';
    dict['P'] = 'O', dict['['] = 'P';
    dict[']'] = '[', dict['\\'] = ']';
    dict['S'] = 'A', dict['D'] = 'S';
    dict['F'] = 'D', dict['G'] = 'F';
    dict['H'] = 'G', dict['J'] = 'H';
    dict['K'] = 'J', dict['L'] = 'K';
    dict[';'] = 'L', dict['\''] = ';';
    dict['X'] = 'Z', dict['C'] = 'X';
    dict['V'] = 'C', dict['B'] = 'V';
    dict['N'] = 'B', dict['M'] = 'N';
    dict[','] = 'M', dict['.'] = ',';
    dict['/'] = '.';
    char s[100000];
    while(gets(s) != NULL) {
        int len = strlen(s);
        for(int i = 0; i < len; ++ i) {
            if(dict[s[i]] != 0)
                s[i] = dict[s[i]];
        }
        puts(s);
    }
    return 0;
}
