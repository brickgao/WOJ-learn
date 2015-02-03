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

char s[100000];
string r_s;

int main() {
    while(cin >> r_s) {
        if(r_s == "ENDOFINPUT")
            return 0;
        getchar();
        gets(s);
        int len = strlen(s);
        for(int i = 0; i < len; ++ i) {
            if(isalpha(s[i])) {
                if(s[i] >= 'A' && s[i] <= 'Z')
                    s[i] = 'A' + (s[i] - 'A' + 21) % 26;
            }
        }
        puts(s);
        cin >> r_s;
    }
    return 0;
}

