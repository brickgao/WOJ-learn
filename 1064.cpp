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

int main() {
    while(scanf("%d", &n) != EOF) {
        int mark[1100] = {};
        for(int i = 0; i < n; ++ i) {
            int tmp;
            scanf("%d", &tmp);
            mark[tmp] = 1;
        }
        bool flag = false;
        for(int i = 0; i < 1000; ++ i) {
            if(mark[i]) {
                if(flag)    printf(" ");
                else        flag = true;
                printf("%d", i);
            }
        }
        puts("");
    }
    return 0;
}

