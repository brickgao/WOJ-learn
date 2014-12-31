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

int m, n, k;
int matrix[200][200];
vector <int> mp[20000];
bool vis[20000];
int mat[20000];

bool crosspath(int k) {
    for(int i = 0; i < int(mp[k].size()); ++ i) {
        int v = mp[k][i];
        if(!vis[v]) {
            vis[v] = true;
            if(mat[v] == -1 || crosspath(mat[v])) {
                mat[v] = k;
                return true;
            }
        }
    }
    return false;
}

int main() {
    while(scanf("%d%d", &m, &n) != EOF) {
        memset(mat, -1, sizeof(mat));
        for(int i = 0; i < 20000; ++ i)
            mp[i].clear();
        for(int i = 0; i < m; ++ i)
            for(int j = 0; j < n; ++ j)
                scanf("%d", &matrix[i][j]);
        scanf("%d", &k);
        for(int i = 0; i < m; ++ i)
            for(int j = 0; j < n; ++ j)
                if(matrix[i][j] == 1)
                    for(int kk = 0; kk < k; ++ kk)
                        mp[i * k + kk].push_back(m * k + j);
        int match = 0;
        for(int i = 0; i < m * k + n; ++ i) {
            if(crosspath(i)) {
                ++ match;
            }
            memset(vis, false, sizeof(vis));
        }
        if(match == n)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

