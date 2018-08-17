/*
1063. Set Similarity (25)
Given two sets of integers, the similarity of the sets is defined to be Nc/Nt*100%, where Nc is the number of distinct common numbers shared by the two sets, and Nt is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

Input Specification:

Each input file contains one test case. Each case first gives a positive integer N (<=50) which is the total number of sets. Then N lines follow, each gives a set with a positive M (<=104) and followed by M integers in the range [0, 109]. After the input of sets, a positive integer K (<=2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.

Output Specification:

For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:
50.0%
33.3%
*/

#include<stdio.h>
#include<set>
#include<vector>
using namespace std;

vector<set<int> > v;

void query(int a,int b){
    int nc = 0;
    int nt = (int)v[b].size();
    for(auto it = v[a].begin(); it != v[a].end(); it ++){
        if(v[b].find(*it) != v[b].end())
            nc++;
        else
            nt ++;
    }
    double r = (double)nc/nt * 100;
    printf("%.1lf%%\n",r);
}

int main(){
    int n;
    scanf("%d",&n);
    v.resize(n+1);
    for(int i = 1; i <= n; i ++){
        int k;
        scanf("%d",&k);
        for(int j = 0; j < k; j ++){
            int a;
            scanf("%d",&a);
            v[i].insert(a);
        }
    }
    int m;
    scanf("%d",&m);
    for(int i = 0; i < m; i ++){
        int a,b;
        scanf("%d %d",&a,&b);
        query(a,b);
    }
    return 0;
}
