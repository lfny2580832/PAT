/*
1025. PAT Ranking (25)
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank

The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/

#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

struct stu{
    long long id;
    int score,overallRank,loca,locaRank;
};

//按成绩排序，成绩相同按学号排序
bool cmp(stu a,stu b){
    return a.score != b.score ? a.score > b.score : a.id < b.id;
}

vector<stu> all;

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++){
        int m;
        scanf("%d",&m);
        vector<stu> v(m);
        for(int j = 0; j < m; j ++){
            scanf("%lld %d",&v[j].id,&v[j].score);
            v[j].loca = i;
        }
        sort(v.begin(),v.end(),cmp);
        v[0].locaRank = 1;
        all.push_back(v[0]);
        for(int j = 1; j < m; j ++){
            v[j].locaRank = (v[j].score == v[j-1].score)? (v[j-1].locaRank) : (j + 1);
            all.push_back(v[j]);
        }
    }
    sort(all.begin(),all.end(),cmp);
    all[0].overallRank = 1;
    for(int j = 1; j < all.size(); j ++){
        all[j].overallRank = (all[j].score == all[j-1].score)? all[j-1].overallRank : (j+1);
    }
    printf("%d\n",(int)all.size());
    for(int i = 0; i < all.size(); i ++){
        printf("%013lld %d %d %d\n",all[i].id,all[i].overallRank,all[i].loca,all[i].locaRank);
    }
    return 0;
}

