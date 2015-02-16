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

const int M = 100000;
const int N = 100000;

bool is[M];
int prm[N];
int total, n;
lint lower = 0;
vector <int> v;

int getprm(int n){
    int i, j, k = 0;
    int s, e = (int)(sqrt(0.0 + n) + 1);
    memset(is, 1, sizeof(is));
    prm[k++] = 2; is[0] = is[1] = 0;
    for (i = 4; i < n; i += 2) is[i] = 0;
    for (i = 3; i < e; i += 2) if (is[i]) {
        prm[k++] = i;
        for (s = i * 2, j = i * i; j < n; j += s) is[j] = 0;
    }
    for ( ; i < n; i += 2) if (is[i]) prm[k++] = i;
    return k;
}

bool isprime(lint num) {
    if(num < M)
        return is[num];
    else {
        for(int i = 0; i < total; ++ i) {
            if(num % prm[i] == 0)
                return false;
        }
        return true;
    }
}

void dfs(int n, lint num) {
    lint new_num = num * 10L + n;
    if(isprime(new_num)) {
        if(new_num > lower)
            v.push_back(new_num);
        else {
            dfs(1, new_num);
            dfs(3, new_num);
            dfs(7, new_num);
            dfs(9, new_num);
        }
    }
}

int main() {
    total = getprm(M);
    while(scanf("%d", &n) != EOF) {
        lower = 1;
        for(int i = 0; i < n - 1; ++ i)
            lower *= 10L;
        v.clear();
        int beg[4] = {2, 3, 5, 7};
        if(n == 1) {
            puts("2");
            puts("3");
            puts("5");
            puts("7");
            continue;
        }
        for(int i = 0; i < 4; ++ i) {
            dfs(1, beg[i]);
            dfs(3, beg[i]);
            dfs(7, beg[i]);
            dfs(9, beg[i]);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < SZ(v); ++ i) {
            cout << v[i] << endl;
        }
    }
    return 0;
}
