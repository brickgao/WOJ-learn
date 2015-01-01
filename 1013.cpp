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
    string s;
    while(cin >> s) {
        vector <string> rec;
        rec.clear();
        for(int i = 0; i < int(s.size()); ++ i) {
            string tmp = "";
            for(int j = i; j < int(s.size()); ++ j)
                tmp += s[j];
            for(int j = 0; j < i; ++ j)
                tmp += s[j];
            rec.push_back(tmp);
        }
        sort(rec.begin(), rec.end());
        cout << rec[0] << endl;
    }
    return 0;
}

