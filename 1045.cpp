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
    while(scanf("%d\n", &t) != EOF) {
        for(int T = 0; T < t; ++ T) {
            char s[100000];
            gets(s);
            if(s[0] >= 'a' && s[0] <= 'z')
                s[0] = s[0] - 'a' + 'A';
            int len = strlen(s);
            for(int i = 1; i < len; ++ i)
                if(s[i] >= 'A' && s[i] <= 'Z' && s[i - 1] != ' ')
                    s[i] = s[i] - 'A' + 'a';
            puts(s);
        }
    }
    return 0;
}

