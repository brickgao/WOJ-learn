//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct node {
    int v, c;
} node;

typedef struct record {
    int p;
    LL cost;
} record;

vector <node> mp[50010];
bool vis[50010];
int maxnp = -1;

int bfs(int u) {
    queue <record> q;
    record tmp;
    LL maxn = -1;
    memset(vis, false, sizeof(vis));
    tmp.p = u, tmp.cost = 0;
    vis[u] = true;
    q.push(tmp);
    while(!q.empty()) {
        tmp = q.front();
        q.pop();
        int p = tmp.p;
        LL cost = tmp.cost;
        if(get_max(maxn, cost))
            maxnp = p;
        for(int i = 0; i < SZ(mp[p]); ++ i) {
            int v = mp[p][i].v, c = mp[p][i].c;
            if(!vis[v]) {
                tmp.p = v, tmp.cost = cost + c;
                vis[v] = true;
                q.push(tmp);
            }
        }
    }
    return maxn;
}

int main() {
    int t;
    while(scanf("%d", &t) != EOF) {
        for(int T = 1; T <= t; ++ T) {
            if(T != 1)  puts("");
            for(int i = 0; i < 50010; ++ i)
                mp[i].clear();
            int n;
            LL ans = 0;
            scanf("%d", &n);
            for(int i = 0; i < n - 1; ++ i) {
                int u, v, c;
                node tmp;
                scanf("%d%d%d", &u, &v, &c);
                ans += c * 2;
                tmp.v = v, tmp.c = c;
                mp[u].push_back(tmp);
                tmp.v = u;
                mp[v].push_back(tmp);
            }
            maxnp = -1;
            bfs(1);
            ans -= bfs(maxnp);
            printf("Case %d:\n", T);
            cout << ans << endl;
        }
    }
    return 0;
}

