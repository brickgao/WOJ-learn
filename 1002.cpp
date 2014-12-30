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
    string stmp, head;
    int cnt = 0;
    bool flag = false;
    while(cin >> stmp) {
        if(stmp[0] >= '0' && stmp[0] <= '9') {
            if(flag)
                cout << head << " " << cnt << endl;
            else
                flag = true;
            head = stmp;
            cnt = 0;
        }
        else {
            bool isword = false;
            for(int i = 0; i < int(stmp.length()); ++ i) {
                if(isalpha(stmp[i])) {
                    isword = true;
                    break;
                }
            }
            if(isword)
                ++ cnt;
        }
    }
    cout << head << " " << cnt << endl;
    return 0;
}

