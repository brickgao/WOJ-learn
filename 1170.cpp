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
    map <int, int> dict;
    vector <int> v;
    int tmp;
    while(scanf("%d", &tmp) != EOF) {
        if(tmp == 0)    break;
        if(dict[tmp] == 1)  continue;
        else                dict[tmp] = 1;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < SZ(v); ++ i) {
        if(i != 0)  printf(" ");
        printf("%d", v[i]);
    }
    return 0;
}

