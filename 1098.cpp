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

int main() {
    while(scanf("%d\n", &t) != EOF) {
        for(int T = 0; T < t; ++ T) {
            int cnt_d = 0, cnt_z = 0;
            char s[100010];
            bool mark[2][100010] = {};
            gets(s);
            int len = strlen(s);
            for(int i = 0; i < len; ++ i) {
                if(i + 10 <= len) {
                    string tmp = "";
                    for(int j = 0; j < 10; ++ j)
                        tmp += s[i + j];
                    if(tmp == "dongfangxu") {
                        mark[0][i + 10] = true;
                    }
                }
            }
            for(int i = 0; i < len; ++ i) {
                if(i + 3 <= len) {
                    string tmp = "";
                    for(int j = 0; j < 3; ++ j)
                        tmp += s[i + j];
                    if(tmp == "zap") {
                        mark[1][i + 3] = true;
                    }
                }
            }
            int dp[2][100010] = {};
            for(int i = 10; i <= len; ++ i) {
                if(mark[0][i]) {
                    dp[0][i] = dp[0][i - 10] + 1;
                }
                get_max(cnt_d, dp[0][i]);
            }
            for(int i = 3; i <= len; ++ i) {
                if(mark[1][i])
                    dp[1][i] = dp[1][i - 3] + 1;
                get_max(cnt_z, dp[1][i]);
            }
            if(cnt_z > cnt_d)
                puts("zap!");
            else
                puts("dongfangxu!");
        }
    }
    return 0;
}

