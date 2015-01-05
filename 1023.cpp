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
    int t;
    while(scanf("%d", &t) != EOF) {
        for(int T = 1; T <= t; ++ T) {
            if(T != 1)  puts("");
            int n, p, a[110];
            double sum[110][110], dp[110], rec[110][110];
            for(int i = 0; i < 110; ++ i)
                for(int j = 0; j < 110; ++ j)
                    sum[i][j] = rec[i][j] = 0.0;
            scanf("%d%d", &n, &p);
            for(int i = 1; i <= n; ++ i)
                scanf("%d", &a[i]);
            for(int i = 1; i <= n; ++ i) {
                for(int j = i; j <= n; ++ j) {
                    if(j == i)  sum[i][j] = a[j];
                    else        sum[i][j] = sum[i][j - 1] + a[j];
                }
            }
            for(int i = 1; i <= n; ++ i) {
                for(int j = i; j <= n; ++ j) {
                    double mid = sum[i][j] / (j - i + 1);
                    for(int k = i; k <= j; ++ k) {
                        rec[i][j] += (a[k] - mid) * (a[k] - mid);
                    }
                }
            }
            for(int i = 0; i < 110; ++ i)
                dp[i] = 1e35;
            dp[0] = 0;
            for(int i = 1; i <= n; ++ i) {
                for(int j = 0; j < i; ++ j) {
                    if(i - j < p)   continue;
                    get_min(dp[i], dp[j] + rec[j + 1][i]);
                }
            }
            printf("Case %d:\n%.2f\n", T, dp[n]);
        }
    }
    return 0;
}

