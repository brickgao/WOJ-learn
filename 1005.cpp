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
    int ca;
    int dp[200000];
    int rec[200][2];
    int total;
    while(scanf("%d", &ca) != EOF) {
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < ca; ++ i) {
            scanf("%d%d", &rec[i][0], &rec[i][1]);
        }
        scanf("%d", &total);
        for(int i = 0; i < ca; ++ i) {
            for(int j = total; j >= rec[i][0]; -- j) {
                get_max(dp[j], dp[j - rec[i][0]] + rec[i][1]);
            }
        }
        int ans = -1;
        for(int i = 0; i <= total; ++ i) {
            get_max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

