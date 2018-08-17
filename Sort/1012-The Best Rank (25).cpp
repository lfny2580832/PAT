/*
1012. The Best Rank (25)
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C – C Programming Language, M – Mathematics (Calculus or Linear Algebra), and E – English. At the mean time, we encourage students by emphasizing on their best ranks — that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A – Average of 4 students are given as the following:

StudentID C M E A
310101 98 85 88 90
310102 70 95 88 84
310103 82 87 94 88
310104 91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input

Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output

For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output “N/A”.

Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output
1 C
1 M
1 E
1 A
3 A
N/A
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

/*
 此题重点是如何设置数据结构才方便
 四舍五入：int会自己截掉小数，所以加0.5之后再截断小数就是四舍五入
 */

struct student{
    int id,best;    //best是最好排名对应socre数组中的下标
    int score[4],rank[4];
}stu[2001];

/*如id为123456，在结构体存储在第4个位置,则exist[123456] = 4*/
int exist[1000000];

int lesson = 0;

bool cmp(student a,student b){
    return a.score[lesson] > b.score[lesson];
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i ++){
        scanf("%d %d %d %d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;
        stu[i].best = 0;
    }
    //每门分数进行一次排序，然后设置rank
    for(lesson = 0; lesson <= 3; lesson ++){
        sort(stu,stu+n,cmp);
        //排序后stu[0]即为这门课分数最高的学生，给他设这门课的rank为1
        stu[0].rank[lesson] = 1;
        //设置之后同学的名次，注意名次可并列，三个第1的话没有第2、3名只有第4名
        for(int i = 1; i < n; i ++){
            stu[i].rank[lesson] = i + 1;
            if(stu[i].score[lesson] == stu[i-1].score[lesson]){
                stu[i].rank[lesson] = stu[i-1].rank[lesson];
            }
        }
    }
    //每个学生找到名次最好的排名，将下标存到best里
    for(int i = 0; i < n; i ++){
        //因为输出时要根据exist[i]是否为0来输出（第一位是0，其他空位也是0，没法判断），所以右移一位
        exist[stu[i].id] = i + 1;
        int min = stu[i].rank[0];
        for(int j = 1; j <= 3; j ++){
            if(stu[i].rank[j] < min){
                min = stu[i].rank[j];
                stu[i].best = j;
            }
        }
    }
    char c[5] = {'A','C','M','E'};
    for(int i = 0; i < m; i ++){
        int id;
        scanf("%d",&id);
        int pos = exist[id];
        if(pos){
            int best = stu[pos-1].best;
            printf("%d %c\n",stu[pos-1].rank[best],c[best]);
        }else{
            printf("N/A\n");
        }
    }
    return 0;
}
