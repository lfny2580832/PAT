/*
1094. The Largest Generation (25)
A family hierarchy is usually presented by a pedigree tree where all the nodes on the same level belong to the same generation. Your task is to find the generation with the largest population.

Input Specification:

Each input file contains one test case. Each case starts with two positive integers N (<100) which is the total number of family members in the tree (and hence assume that all the members are numbered from 01 to N), and M (<N) which is the number of family members who have children. Then M lines follow, each contains the information of a family member in the following format:

ID K ID[1] ID[2] … ID[K]

where ID is a two-digit number representing a family member, K (>0) is the number of his/her children, followed by a sequence of two-digit ID’s of his/her children. For the sake of simplicity, let us fix the root ID to be 01. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the largest population number and the level of the corresponding generation. It is assumed that such a generation is unique, and the root level is defined to be 1.

Sample Input:
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
Sample Output:
9 4
*/

#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;

vector<int> tree_vec[100];
map<int,int> depth_map;
int n,m;

// int level[100] = {0};   //下标对应结点的深度
// void levelOrder(int head){
//     queue<int> q;
//     q.push(head);
//     level[head] = 1;
//     while(q.size()){
//         int index = q.front();
//         q.pop();
        
//         for(int i = 0; i < tree_vec[index].size(); i ++){
//             level[tree_vec[index][i]] = level[index] + 1;
//             q.push(tree_vec[index][i]);
//         }
//     }
//     int cnt = 1,d = 1,max = 1;
//     for(int i = 1; i < n; i ++){
//         if(level[i] == level[i-1]){
//             cnt ++;
//         }else{
//             cnt = 1;
//         }
//         if(cnt > max){
//             max = cnt;
//             d = level[i];
//         }
//     }
//     printf("%d %d",max,d);
// }

void dfs(int head,int depth){
    depth_map[depth] ++;
    for(int i = 0; i < tree_vec[head].size(); i ++)
        dfs(tree_vec[head][i], depth + 1);
}

int main(){
    scanf("%d %d",&n,&m);
    getchar();
    for(int i = 0; i < m; i ++){
        int f,k;
        scanf("%d %d",&f,&k);
        for(int i = 0; i < k; i ++){
            int p;
            scanf("%d",&p);
            tree_vec[f].push_back(p);
        }
    }
    dfs(1,1);
    map<int,int>::iterator it;
    int num = 1,depth = 1;
    for(it = depth_map.begin(); it != depth_map.end(); it++){
        if(it->second > num){
            num = it->second;
            depth = it->first;
        }
    }
    printf("%d %d",num,depth);
    return 0;
}

