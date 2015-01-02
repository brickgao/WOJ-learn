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
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

LL c[30][30];
int n;
LL dp[30];

void init() {
    for(int i = 0; i < 30; i ++) {
        c[i][0] = c[i][i] = 1LL;
        for(int j = 1; j < i; j ++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

int main() {
    init();
    while(scanf("%d", &n) != EOF) {
        memset(dp, 0, sizeof(dp));
        dp[0] = dp[1] = 1;
        for(int i = 1; i < n; ++ i) {
            int t = i / 3;
            for(int j = 1; j <= t; ++ j) {
                dp[i + 1] += dp[j * 3 - 1] * dp[i + 1 - j * 3] * c[i][j * 3 - 1];
            }
            if(i % 3 != 0)
                dp[i + 1] += dp[i];
        }
        cout << dp[n] << endl;
    }
    return 0;
}

