/*
The ranklist of PAT is generated from the status list, which shows the scores of the submittions. This time you are supposed to generate the ranklist for PAT.

Input Specification:

Each input file contains one test case. For each case, the first line contains 3 positive integers, N (<=10^4^), the total number of users, K (<=5), the total number of problems, and M (<=10^5^), the total number of submittions. It is then assumed that the user id's are 5-digit numbers from 00001 to N, and the problem id's are from 1 to K. The next line contains K positive integers p[i] (i=1, ..., K), where p[i] corresponds to the full mark of the i-th problem. Then M lines follow, each gives the information of a submittion in the following format:

user_id problem_id partial_score_obtained

where partial_score_obtained is either -1 if the submittion cannot even pass the compiler, or is an integer in the range [0, p[problem_id]]. All the numbers in a line are separated by a space.

Output Specification:

For each test case, you are supposed to output the ranklist in the following format:

rank user_id total_score s[1] ... s[K]

where rank is calculated according to the total_score, and all the users with the same total_score obtain the same rank; and s[i] is the partial score obtained for the i-th problem. If a user has never submitted a solution for a problem, then "-" must be printed at the corresponding position. If a user has submitted several solutions to solve one problem, then the highest score will be counted.

The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, users must be sorted in nonincreasing order according to the number of perfectly solved problems. And if there is still a tie, then they must be printed in increasing order of their id's. For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT be shown on the ranklist. It is guaranteed that at least one user can be shown on the ranklist.

Sample Input:

7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0
Sample Output:

1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int full[6];

struct stu{
    int id,overallScore = 0,ACnum = 0,rank;
    vector<int> score;    //每道问题的分数
    bool pass = false;      //有没有通过一道题，有一道题通过就true并输出
};

vector<stu> v;

bool cmp(stu a, stu b){
    if(a.overallScore != b.overallScore)
        return a.overallScore > b.overallScore;
    else if(a.ACnum != b.ACnum)
        return a.ACnum > b.ACnum;
    else
        return a.id < b.id;
}

int main(){
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    v.resize(n+1);
    for(int i = 1; i <= n; i ++){
        v[i].score.resize(k+1,-1);
    }
    for(int i = 1; i <= k; i ++){
        scanf("%d",&full[i]);
    }
    for(int i = 0; i < m; i ++){
        int id,k,s;
        scanf("%d %d %d",&id,&k,&s);
        v[id].id = id;
        v[id].score[k] = max(v[id].score[k],s);
        if(s >= 0){
            v[id].pass = true;
        }else if(v[id].score[k] == -1){  //没过编译，用-2代替，只用来判断输出时是0还是-
            v[id].score[k] = -2;
        }
    }
    //计算各学生总分和AC数，排序要看AC数
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= k; j ++){
            if(v[i].score[j] >= 0)
                v[i].overallScore += v[i].score[j];
            if(v[i].score[j] == full[j])
                v[i].ACnum ++;
        }
    }
    //排序
    sort(v.begin()+1,v.end(),cmp);
    //设置名次
    for(int i = 1; i <= n; i ++){
        v[i].rank = i;
        if(i != 1 && v[i].overallScore == v[i-1].overallScore)
            v[i].rank = v[i-1].rank;
    }
    //输出
    for(int i = 1; i <= n; i ++){
        if(v[i].pass){
            printf("%d %05d %d",v[i].rank,v[i].id,v[i].overallScore);
            for(int j = 1; j <= k; j++){
                if(v[i].score[j] >= 0)
                    printf(" %d",v[i].score[j]);
                else if(v[i].score[j] == -1)
                    printf(" -");
                else
                    printf(" 0");
            }
            printf("\n");
        }
    }
    return 0;
}


