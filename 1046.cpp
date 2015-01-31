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
    int t;
    while(scanf("%d", &t) != EOF) {
        for(int T = 0; T < t; ++ T) {
            int n, arr[4000], cnt = 0;
            scanf("%d", &n);
            for(int i = 0; i < n; ++ i)
                scanf("%d", &arr[i]);
            for(int i = 0; i < n - 1; ++ i) {
                for(int j = 0; j < n - i - 1; ++ j) {
                    if(arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                        ++ cnt;
                    }
                }
            }
            printf("%d\n", cnt);
        }
    }
    return 0;
}

