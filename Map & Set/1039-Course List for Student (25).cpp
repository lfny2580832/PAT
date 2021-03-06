/*
1039. Course List for Student (25)
Zhejiang University has 40000 students and provides 2500 courses. Now given the student name lists of all the courses, you are supposed to output the registered course list for each student who comes for a query.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=40000), the number of students who look for their course lists, and K (<=2500), the total number of courses. Then the student name lists are given for the courses (numbered from 1 to K) in the following format: for each course i, first the course index i and the number of registered students Ni (<= 200) are given in a line. Then in the next line, Ni student names are given. A student name consists of 3 capital English letters plus a one-digit number. Finally the last line contains the N names of students who come for a query. All the names and numbers in a line are separated by a space.

Output Specification:

For each test case, print your results in N lines. Each line corresponds to one student, in the following format: first print the student’s name, then the total number of registered courses of that student, and finally the indices of the courses in increasing order. The query results must be printed in the same order as input. All the data in a line must be separated by a space, with no extra space at the end of the line.

Sample Input:
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
Sample Output:
ZOE1 2 4 5
ANN0 3 1 2 5
BOB5 5 1 2 3 4 5
JOE4 1 2
JAY9 4 1 2 4 5
FRA8 3 2 4 5
DON2 2 4 5
AMY7 1 5
KAT3 3 2 4 5
LOR6 4 1 2 4 5
NON9 0
*/

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

/*
 注意此题容易超时
 1.(最重要的一点)别用自带map库，用vector数组作map。因此下标需要字符串转int
 2.输出时再进行排序
 */

const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> class_map[maxn];

int getId(char *name) {
    int id = 0;
    for(int i = 0; i < 3; i++)
        id = 26 * id + (name[i] - 'A');
    id = id * 10 + (name[3] - '0');
    return id;
}

int main(){
    int n,m,c,s,id;
    char name[5];
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; i ++){
        scanf("%d %d",&c,&s);
        for(int i = 0; i < s; i ++){
            scanf("%s",name);
            id = getId(name);
            class_map[id].push_back(c);
        }
    }
    for(int i = 0; i < n; i ++){
        scanf("%s",name);
        id = getId(name);
        sort(class_map[id].begin(), class_map[id].end());
        printf("%s %d",name,(int)class_map[id].size());
        if(class_map[id].size()) printf(" ");
        vector<int> c_vec = class_map[id];
        for(int i = 0; i < c_vec.size(); i ++){
            printf("%d",c_vec[i]);
            if(i != c_vec.size()-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
