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

typedef struct record {
    int t, c;
} record;

bool cmp(record a, record b) {
    return a.c > b.c;
}

int caseno;
bool vis[3010];

int main() {
    while(scanf("%d", &caseno) != EOF) {
        for(int t = 1; t <= caseno; ++ t) {
            vector <record> v;
            if(t != 1)  puts("");
            int n;
            scanf("%d", &n);
            for(int i = 0; i < n; ++ i) {
                record tmp;
                scanf("%d%d", &tmp.t, &tmp.c);
                v.push_back(tmp);
            }
            sort(v.begin(), v.end(), cmp);
            int ans = 0;
            memset(vis, false, sizeof(vis));
            for(int i = 0; i < n; ++ i) {
                bool flag = false;
                for(int j = v[i].t; j >= 1; -- j) {
                    if(!vis[j]) {
                        vis[j] = flag = true;
                        break;
                    }
                }
                if(!flag)
                    ans += v[i].c;
            }
            printf("Case %d:\n%d\n", t, ans);
        }
    }
    return 0;
}

