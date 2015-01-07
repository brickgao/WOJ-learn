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

string s;

int main() {
    while(cin >> s) {
        if(s == "$")    return 0;
        string ans = "";
        for(int i = 0; i < SZ(s); ++ i) {
            ans += 'A' + (((s[i] - 'A' - (i + 1)) % 26 + 26) % 26);
        }
        cout << ans << endl;
    }
    return 0;
}

