/*
1004. Counting Leaves (30)
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] … ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID’s of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output “0 1” in a line.

Sample Input
2 1
01 1 02
Sample Output
0 1
*/

#include<stdio.h>
#include<vector>
#include<map>
using namespace std;

/*
 注意题目要求求的是每层的叶结点（leaf node）个数
 */
vector<int> tree_vec[100];
int nl_map[100];    //记录每个深度有多少叶结点
int maxdepth;   //记录最大深度，不然不好输出
void dfs(int r,int d){
    //统计非叶结点个数
    if(tree_vec[r].size() == 0){
        nl_map[d] ++;
        if(d > maxdepth) maxdepth = d;
    }
    for(int i = 0; i < tree_vec[r].size(); i ++){
        dfs(tree_vec[r][i],d + 1);
    }
}

int main(){
    int n,m;    //总节点数，非叶结点数
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; i ++){
        int k,q;
        scanf("%d %d",&k,&q);
        for(int j = 0; j < q; j ++){
            int c;
            scanf("%d",&c);
            tree_vec[k].push_back(c);
        }
    }
    dfs(1,0);
    for(int i = 0; i <= maxdepth; i ++){
        printf("%d",nl_map[i]);
        if(i != maxdepth) printf(" ");
    }
    return 0;
}

