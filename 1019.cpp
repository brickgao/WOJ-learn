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

map <string, int> day_dict;
int n;
string course_name[100], day[100], time_section[100];
int class_number[100];

int main() {
    day_dict["MON"] = 1;
    day_dict["TUE"] = 2;
    day_dict["WED"] = 3;
    day_dict["THU"] = 4;
    day_dict["FRI"] = 5;
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; ++ i) {
            char ch;
            course_name[i] = "";
            while(1) {
                ch = getchar();
                if(ch == ':')   break;
                if(!isalpha(ch) && !(ch == ' '))  continue;
                course_name[i] += ch;
            }
            cin >> day[i] >> time_section[i] >> class_number[i];
        }
        puts("+-----+-----------+-----------+-----------+-----------+-----------+");
		puts("|     |    MON    |    TUE    |    WED    |    THU    |    FRI    |");
		puts("+-----+-----------+-----------+-----------+-----------+-----------+");
		puts("|                          Morning                                |");
		puts("+-----+-----------+-----------+-----------+-----------+-----------+");
        for(int i = 1; i <= 4; ++ i) {
            printf("|  %d  |", i);
            for(int j = 1; j <= 5; ++ j) {
                bool flag = false;
                for(int k = 0; k < n; ++ k) {
                    if(day_dict[day[k]] == j && class_number[k] == i && time_section[k] == "Morning") {
                        if(SZ(course_name[k]) % 2 == 0) {
                            string tmp = "", space = "";
                            for(int t = 0; t < (10 - SZ(course_name[k])) / 2; ++ t)
                                space += " ";
                            tmp += space;
                            course_name[k] += " ";
                            tmp += course_name[k];
                            tmp += space;
                            cout << tmp << "|";
                        }
                        else {
                            string tmp = "", space = "";
                            for(int t = 0; t < (11 - SZ(course_name[k])) / 2; ++ t)
                                space += " ";
                            tmp += space;
                            tmp += course_name[k];
                            tmp += space;
                            cout << tmp << "|";
                        }
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                    cout << "           |";
            }
            puts("\n+-----+-----------+-----------+-----------+-----------+-----------+");
        }
        puts("|                         Afternoon                               |"); 
		puts("+-----+-----------+-----------+-----------+-----------+-----------+");
        for(int i = 1; i <= 3; ++ i) {
            printf("|  %d  |", i);
            for(int j = 1; j <= 5; ++ j) {
                bool flag = false;
                for(int k = 0; k < n; ++ k) {
                    if(day_dict[day[k]] == j && class_number[k] == i && time_section[k] == "Afternoon") {
                        if(SZ(course_name[k]) % 2 == 0) {
                            string tmp = "", space = "";
                            for(int t = 0; t < (10 - SZ(course_name[k])) / 2; ++ t)
                                space += " ";
                            tmp += space;
                            course_name[k] += " ";
                            tmp += course_name[k];
                            tmp += space;
                            cout << tmp << "|";
                        }
                        else {
                            string tmp = "", space = "";
                            for(int t = 0; t < (11 - SZ(course_name[k])) / 2; ++ t)
                                space += " ";
                            tmp += space;
                            tmp += course_name[k];
                            tmp += space;
                            cout << tmp << "|";
                        }
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                    cout << "           |";
            }
            puts("\n+-----+-----------+-----------+-----------+-----------+-----------+");
        }
        puts("");
    }
    return 0;
}

