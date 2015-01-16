//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
typedef long long LL;
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}


int main() {
    LL n, m;
    while(cin >> n >> m && (n != 0 && m != 0)) {
        LL ans = 0;
        for(int i = 2; i <= n; ++ i) {
            ans = (ans + m) % i;
        }
        cout << ans + 1 << endl;
    }
    return 0;
}

