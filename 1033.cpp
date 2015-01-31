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

int main() {
    int a, b, m, n;
    while(scanf("%d%d%d%d", &a, &b, &m, &n) != EOF) {
        int upper_bound = min((a - 1) * (b - 1) - 1, n);
        int ans = 0;
        for(int i = m; i <= upper_bound; ++ i) {
            bool flag = false;
            for(int j = 0; j <= (int)(i / a); ++ j) {
                if((i - j * a) % b == 0) {
                    flag = true;
                    break;
                }
            }
            if(!flag)
                ++ ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}

