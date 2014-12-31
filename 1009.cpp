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
    int v, cost;
    char data;
} record;

int m, n, plovers, slovers;
int road[4100][5];
char word[4100];
vector <record> mp[110];
bool vis[110];
int dis[110];
char rec[110];

string get_path() {
    string stmp = "", ans = "";
    int fa[110];
    memset(fa, -1, sizeof(fa));
    dis[0] = 0;
    vis[0] = true;
    fa[0] = -1;
    for(int i = 0; i < int(mp[0].size()); ++ i) {
        record vp = mp[0][i];
        dis[vp.v] = vp.cost;
        rec[vp.v] = vp.data;
        fa[vp.v] = 0;
    }
    for(int i = 1; i < n; ++ i) {
        int minn = maxint, recmin = -1;
        for(int j = 0; j < n; ++ j)
            if(!vis[j] && minn > dis[j])
                minn = dis[j], recmin = j;
        vis[recmin] = true;
        stmp += rec[recmin];
        for(int j = 0; j < int(mp[recmin].size()); ++ j) {
            record vp = mp[recmin][j];
            if(!vis[vp.v] && dis[vp.v] > minn + vp.cost)
                dis[vp.v] = minn + vp.cost, rec[vp.v] = vp.data, fa[vp.v] = recmin;
        }
    }
    int r = fa[n - 1];
    while(r != -1) {
        ans = stmp[r] + ans;
        r = fa[r];
    }
    return ans;
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i = 0; i < 110; ++ i) {
            mp[i].clear();
            dis[i] = maxint;
            rec[i] = '*';
        }
        for(int i = 0; i < m; ++ i)
            scanf("%d %d %d %d %d %c", &road[i][0], &road[i][1], &road[i][2], &road[i][3], &road[i][4], &word[i]);
        scanf("%d %d", &plovers, &slovers); 
        for(int i = 0; i < m; ++ i) {
            if(road[i][2] < plovers && road[i][3] < slovers) {
                record tmp;
                tmp.v = road[i][1], tmp.cost = road[i][4], tmp.data = word[i];
                mp[road[i][0]].push_back(tmp);
            }
        }
        memset(vis, false, sizeof(vis));
        cout << get_path() << endl;
    }
    return 0;
}

