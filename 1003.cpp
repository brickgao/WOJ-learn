//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

map <string, int> dict;
int mp1[100], mp2[100];

int main() {
    dict.clear();
    dict["Adam"] = 1;       mp1[1] = 0;     mp2[1] = 930;
    dict["Seth"] = 3;       mp1[3] = 1;     mp2[3] = 920;
    dict["Enosh"] = 4;      mp1[4] = 3;     mp2[4] = 905;
    dict["Kenan"] = 5;      mp1[5] = 4;     mp2[5] = 910;
    dict["Mahalalel"] = 6;  mp1[6] = 5;     mp2[6] = 895;
    dict["Jared"] = 7;      mp1[7] = 6;     mp2[7] = 962;
    dict["Enoch"] = 8;      mp1[8] = 7;     mp2[8] = 365;
    dict["Methuselah"] = 9; mp1[9] = 8;     mp2[9] = 969;
    dict["Lamech"] = 10;    mp1[10] = 9;    mp2[10] = 777;
    dict["Noah"] = 11;      mp1[11] = 10;   mp2[11] = -1;
    dict["Shem"] = 12;      mp1[12] = 11;   mp2[12] = -1;
    dict["Ham"] = 13;       mp1[13] = 11;   mp2[13] = -1;
    dict["Japheth"] = 14;   mp1[14] = 11;   mp2[14] = -1;
    string s1, s2;
    while(cin >> s1 >> s2) {
        if(dict[s1] == 0 || dict[s2] == 0) {
            cout << "No enough information" << endl << "No enough information" << endl;
        }
        else {
            int n1 = dict[s1], n2 = dict[s2];
            if(n1 == n2)
                cout << "No" << endl;
            else {
                while(n2 != 0 && n2 != n1)
                    n2 = mp1[n2];
                if(n1 == n2)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
            if(mp2[dict[s1]] == -1 || mp2[dict[s2]] == -1)
                cout << "No enough information" << endl;
            else {
                if(mp2[dict[s1]] > mp2[dict[s2]])
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
        }
    }
    return 0;
}

