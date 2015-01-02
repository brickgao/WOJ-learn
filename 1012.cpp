//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int m, n;
char mp[2010][2010];
int rec[2010][2010];
int sum[2010] = {};
int pre[2010] = {};

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i = 0; i < n; ++ i)
            scanf("%s", mp[i]);
        for(int i = 0; i < n; ++ i)
            for(int j = m - 1; j >= 0; -- j) {
                if(mp[i][j] == 'w')
                    if(j == m - 1)  rec[i][j] = 1;
                    else            rec[i][j] = rec[i][j + 1] + 1;
                else
                    rec[i][j] = 0;
            }
        LL ans = 0;
        for(int i = 0; i < m; ++ i) {
            sum[0] = rec[0][i];
            pre[0] = 0;
            ans += sum[0];
            for(int j = 1; j < n; ++ j) {
                if(rec[j][i] >= rec[j - 1][i]) {
                    sum[j] = sum[j - 1] + rec[j][i];
                    pre[j] = 0;
                }
                else {
                    pre[j] = pre[j - 1] + 1;
                    int p = j - pre[j];
                    while(p > 0 && rec[p - 1][i] >= rec[j][i]) {
                        p = p - pre[p - 1] - 1;
                    }
                    if(p <= 0) {
                        sum[j] = (j + 1) * rec[j][i];
                        pre[j] = 0;
                    }
                    else {
                        sum[j] = sum[p - 1] + rec[j][i] * (j - p + 1);
                        pre[j] = j - p - 1;
                    }
                }
                ans += sum[j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
