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
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

vector <int> mp[200010];
bool vis[200010];

typedef struct rec {
    int p, v;
} rec;

int bfs(int root, int f) {
    if(root == f)   return 0;
    queue <rec> q;
    rec tmp;
    tmp.p = root, tmp.v = -1;
    q.push(tmp);
    while(!q.empty()) {
        rec u = q.front();
        vis[u.p] = true;
        q.pop();
        if(u.p == f)
            return u.v;
        else {
            for(int i = 0; i < int(mp[u.p].size()); ++ i) {
                int v = mp[u.p][i];
                if(!vis[v]) {
                    tmp.p = v, tmp.v = u.v + 1;
                    q.push(tmp);
                }
            }
        }
    }
    return -1;
}

int main() {
    int m, n;
    while(scanf("%d%d", &m, &n) != EOF) {
        for(int i = 0; i < m; ++ i)
            mp[i].clear();
        for(int i = 0; i < n; ++ i) {
            int u, v;
            scanf("%d%d", &u, &v);
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int t;
        scanf("%d", &t);
        for(int i = 0; i < t; ++ i) {
            int u, v;
            scanf("%d%d", &u, &v);
            memset(vis, false, sizeof(vis));
            printf("%d\n", bfs(u, v));
        }
    }
    return 0;
}

