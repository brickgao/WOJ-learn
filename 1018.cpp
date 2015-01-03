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
int init[5010], fin[5010], flag[5010];
vector <int> rec[5010];

int main() {
    while(scanf("%d", &n) != EOF) {
        long long ans = 0;
        int cnt = 0;
        if(n == 0)  return 0;
        memset(flag, -1, sizeof(flag));
        for(int i = 0; i < 5010; ++ i)
            rec[i].clear();
        for(int i = 1; i <= n; ++ i) {
            scanf("%d", &init[i]);
        }
        for(int i = 1; i <= n; ++ i) {
            scanf("%d", &fin[i]);
        }
        int gminn = maxint;
        for(int i = 1; i <= n; ++ i) {
            get_min(gminn, init[i]);
            bool tag = false;
            int pos = i;
            while(flag[pos] == -1) {
                if(!tag) {
                    tag = true;
                    ++ cnt;
                }
                rec[cnt].push_back(pos);
                flag[pos] = cnt;
                for(int j = 1; j <= n; ++ j) {
                    if(init[pos] == fin[j]) {
                        pos = j;
                        break;
                    }
                }
            }
        }
        for(int i = 1; i <= cnt; ++ i) {
            long long cost1 = 0, cost2 = 0, minn = maxint;
            for(int j = 0; j < SZ(rec[i]); ++ j) {
                get_min(minn, (long long)init[rec[i][j]]);
                cost1 += init[rec[i][j]], cost2 += init[rec[i][j]];
            }
            cost1 += minn * (SZ(rec[i]) - 2);
            cost2 += gminn * (SZ(rec[i]) + 1) + minn;
            ans += min(cost1, cost2);
        }
        cout << ans << endl;
    }
    return 0;
}

