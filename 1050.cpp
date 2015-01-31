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
const int MAXN = 110;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct Line {
    int u, v, c;
    bool operator < (const Line &cmp) const {
        return c < cmp.c;
    }
} Line;

Line l[MAXN * MAXN];
bool vis[MAXN * MAXN];
int parent[MAXN], rk[MAXN];
int n, m, ans;

void makeset(int n) {
    for(int i = 1; i <= n; ++ i) {
        parent[i] = i;
        rk[i] = 0;
    }
}

int getparent(int x) {
    if(parent[x] == x)  return x;
    else {
        parent[x] = getparent(parent[x]);
        return parent[x];
    }
}

void unionset(int x, int y) {
    if(rk[x] > rk[y])
        parent[y] = x;
    else {
        parent[x] = y;
        if(rk[x] == rk[y])
            ++ rk[y];
    }
}

void MST() {
    int cnt = 0;
    ans = 0;
    memset(vis, false, sizeof(vis));
    sort(l, l + m);
    makeset(n);
    for(int i = 0; i < m; ++ i) {
        int x = getparent(l[i].u);
        int y = getparent(l[i].v);
        if(x != y) {
            unionset(x, y);
            ++ cnt;
            ans += l[i].c;
            vis[i] = true;
            if(cnt == n - 1)    break;
        }
    }
    return;
}

int main() {
    int t;
    while(scanf("%d", &t) != EOF) {
        for(int T = 0; T < t; ++ T) {
            scanf("%d", &n);
            m = n * (n - 1);
            int cnt = 0;
            for(int i = 1; i <= n; ++ i)
                for(int j = 1; j <= n; ++ j) {
                    scanf("%d", &l[cnt].c);
                    l[cnt].u = i;
                    l[cnt ++].v = j;
                }
            MST();
            printf("%d\n", ans);
        }
    }
    return 0;
}

