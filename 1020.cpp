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

int caseno, n;

int main() {
    while(scanf("%d", &caseno) != EOF) {
        for(int t = 1; t <= caseno; ++ t) {
            vector <int> v;
            if(t != 1)  puts("");
            scanf("%d", &n);
            for(int i = 0; i < n; ++ i) {
                int tmp;
                scanf("%d", &tmp);
                v.push_back(tmp);
            }
            for(int i = n - 1; i > 0; -- i) {
                v[i] = v[i] - v[i - 1];
            }
            sort(v.begin(), v.end());
            bool flag = false;
            cout << "Case " << t << ":" << endl;
            for(int i = 0; i < n; ++ i) {
                if(flag)    cout << " ";
                else        flag = true;
                cout << v[i];
            }
            cout << endl;
        }
    }
    return 0;
}

