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
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int INF = 0x1fffffff;
const int MAXN = 1010;
const int MAXM = 10010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct Status {
    int pos, len, h;
    bool operator < (const Status &cmp) const {
        if(cmp.len + cmp.h == len + h)  return cmp.len < len;
        else                            return cmp.len + cmp.h < len + h;
    }
} Status;

typedef struct Edge {
    int v, next, w;
} Edge;

Edge node[MAXM + MAXN], in_node[MAXM + MAXN];
int dis[MAXN];
bool vis[MAXN];
int n, m, k, ednum, inednum;

void add(int u, int v, int c) {
    ++ ednum;
    node[ednum].next = node[u].next;
    node[u].next = ednum;
    node[ednum].v = v;
    node[ednum].w = c;
}

void in_add(int u, int v, int c) {
    ++ inednum;
    in_node[inednum].next = in_node[u].next;
    in_node[u].next = inednum;
    in_node[inednum].v = v;
    in_node[inednum].w = c;
}

bool spfa(int root) {
    queue <int> q;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; ++ i) dis[i] = INF;
    vis[root] = true;
    dis[root] = 0;
    q.push(root);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int son = in_node[u].next; son != -1; son = in_node[son].next) {
            int v = in_node[son].v;
            int w = in_node[son].w;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return true;
}

int kth_path(int s, int t, int k) {
    if(dis[s] == INF)   return -1;
    if(s == t)  ++ k;
    priority_queue <Status> q;
    Status now;
    now.pos = s, now.len = 0, now.h = dis[s];
    q.push(now);
    int cnt = 0;
    while(!q.empty()) {
        Status top = q.top(); q.pop();
        if(top.pos == t) ++ cnt;
        if(cnt == k)    return top.len;
        for(int i = node[top.pos].next; i != -1; i = node[i].next) {
            Status tmp;
            tmp.pos = node[i].v, tmp.len = node[i].w + top.len, tmp.h = dis[node[i].v];
            q.push(tmp);
        }
    }
    return -1;
}
int main() {
    while(scanf("%d%d%d", &n, &m, &k) != EOF) {
        ednum = n, inednum = n;
        for(int i = 0; i <= m + n; ++ i) {
            node[i].next = in_node[i].next = - 1;
        }
        for(int i = 0; i < m; ++ i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            in_add(v, u, w);
        }
        spfa(n);
        int ans = kth_path(1, n, k);
        printf("%d\n", ans);
    }
    return 0;
}

