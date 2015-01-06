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


bool is[100010];
int prm[100010];

int getprm(int n){
    int i, j, k = 0;
    int s, e = (int)(sqrt(0.0 + n) + 1);
    memset(is, 1, sizeof(is));
    prm[k++] = 2; is[0] = is[1] = 0;
    for (i = 4; i < n; i += 2) is[i] = 0;
    for (i = 3; i < e; i += 2) if (is[i]) {
        prm[k ++] = i;
        for (s = i * 2, j = i * i; j < n; j += s) is[j] = 0;
    }
    for ( ; i < n; i += 2) if (is[i]) prm[k ++] = i;
    return k;
}

int getsum(LL a) {
    LL tmp = a;
    int ret = 0;
    while(tmp != 0) {
        ret += tmp % 10;
        tmp /= 10;
    }
    return ret;
}

int main() {
    int len = getprm(50010);
    LL n;
    while(cin >> n) {
        if(n == 0)  return 0;
        if(n < 50010 && is[n]) {
            puts("No");
            continue;
        }
        int p = 0;
        int sum1 = getsum(n), sum2 = 0;
        while(p < len) {
            if(n % prm[p] != 0) {
                ++ p;
                continue;
            }
            sum2 += getsum(prm[p]);
            n /= prm[p];
        }
        if(n != 1 && sum2 == 0) {
            puts("No");
            continue;
        }
        if(n != 1)
            sum2 += getsum(n);
        if(sum1 == sum2)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}

