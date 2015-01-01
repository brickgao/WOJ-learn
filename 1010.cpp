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
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int n;

int main() {
    while(scanf("%d", &n) != EOF) {
        if(n <= 0)  return 0;
        int maxn;
        scanf("%d", &maxn);
        for(int i = 1; i < n; ++ i) {
            int tmp;
            scanf("%d", &tmp);
            get_max(maxn, tmp);
        }
        while(maxn < 0)
            maxn += 2006;
        maxn = maxn % 2006;
        for(int i = 0; i < n - 1; ++ i) {
            maxn *= 2;
            maxn %= 2006;
        }
        cout << maxn << endl;
    }
    return 0;
}
