//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}


int main() {
    int t;
    while(scanf("%d", &t) != EOF) {
        for(int T = 0; T < t; ++ T) {
            map <int, int> dict;
            int n, building_size[10010];
            scanf("%d", &n);
            for(int i = 0; i < n; ++ i) {
                scanf("%d", &building_size[i]);
                ++ dict[building_size[i]];
            }
            int ans = -1;
            for(int i = 0; i < n; ++ i)
                get_max(ans, dict[building_size[i]]);
            printf("%d\n", ans);
        }
    }
    return 0;
}

