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

int main() {
    int n;
    int rec[10010];
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; ++ i) {
            rec[i] = 20000;
        }
        for(int i = 0; i < 8; ++ i) {
            for(int j = 0; j < n; ++ j) {
                int tmp;
                scanf("%d", &tmp);
                get_min(rec[j], tmp);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++ i)
            ans += rec[i];
        cout << ans << endl;
    }
    return 0;
}

