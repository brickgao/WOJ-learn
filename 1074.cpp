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

int t;

int main() {
    while(scanf("%d", &t) != EOF) {
        for(int T = 0; T < t; ++ T) {
            int n;
            vector <int> v;
            map <long long, int> dict;
            scanf("%d", &n);
            for(int i = 0; i < n; ++ i) {
                int tmp;
                scanf("%d", &tmp);
                v.push_back(tmp);
                ++ dict[tmp];
            }
            sort(v.begin(), v.end());
            bool tag = false;
            int ans = -1;
            for(int i = SZ(v) - 1; i >= 0; -- i) {
                for(int j = i - 1; j >= 0; -- j) {
                    if(dict[v[i] - v[j]] >= 1) {
                        if(v[i] - v[j] == v[j] && dict[v[j]] == 1)
                            continue;
                        tag = true;
                        ans = v[i];
                        break;
                    }
                }
                if(tag) {
                    break;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

