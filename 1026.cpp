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

int t;
int mp[1010][1010], dp[1010][1010];

int main() {
    while(scanf("%d", &t) != EOF) {
        for(int T = 1; T <= t; ++ T) {
            int n;
            if(T != 1)  puts("");
            scanf("%d", &n);
            for(int i = 1; i <= n; ++ i)
                for(int j = 1; j <= n; ++ j)
                    scanf("%d", &mp[i][j]);
            for(int i = 1; i <= n; ++ i)
                for(int j = 1; j <= n; ++ j)
                    dp[i][j] = max(max(dp[i - 1][j], dp[i - 1][j - 1]), dp[i - 1][j + 1]) + mp[i][j];
            int ans = 0;
            for(int i = 1; i <= n; ++ i)
                get_max(ans, dp[n][i]);
            printf("Case %d:\n%d\n", T, ans);
        }
    }
    return 0;
}

