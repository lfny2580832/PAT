/*
1064. Complete Binary Search Tree (30)
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than or equal to the node’s key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.

Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input:
10
1 2 3 4 5 6 7 8 9 0
Sample Output:
6 3 8 1 5 7 9 0 2 4
*/

#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> seq_vec;
vector<int> level_vec[1000];

//这里的begin、end、root都是在序列中的位置
void getLevelOrder(int begin,int end,int lev){
    if(begin > end) return;
    int root = 0;
    int n = end-begin+1;    //子序列节点个数
    int level = log(n+1)/log(2);    //用除法表示log以2为底n+1
    int lastCnt = n - pow(2, level) + 1;  //最后一行的个数
    int right = 0;  //此时根结点右字数的个数
    if(lastCnt <= pow(2, level-1)){     //根结点的右子树没有多余
        right = pow(2, level-1)-1;
    }else{
        right = pow(2, level-1)-1 + (lastCnt - pow(2, level-1));
    }
    if(right == 0) root = end;
    else root = end-right;
    
    level_vec[lev].push_back(seq_vec[root]);
    getLevelOrder(begin, root-1,lev+1);
    getLevelOrder(root+1, end,lev+1);
}

int main(){
    int n;
    scanf("%d",&n);
    seq_vec.resize(n);
    for(int i = 0; i < n; i ++){
        scanf("%d",&seq_vec[i]);
    }
    sort(seq_vec.begin(), seq_vec.end());
    getLevelOrder(0, n-1,0);
    //注意最后输出
    printf("%d",level_vec[0][0]);
    for(int i = 1; i <= log(n+1)/log(2); i ++){
        for(int j = 0; j < level_vec[i].size(); j++)
            printf(" %d",level_vec[i][j]);
    }
    return 0;
}
