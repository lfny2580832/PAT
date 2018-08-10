/*
1102. Invert a Binary Tree (25)
The following is from Max Howell @twitter:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
Now it’s your turn to prove that YOU CAN invert a binary tree!

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=10) which is the total number of nodes in the tree — and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node from 0 to N-1, and gives the indices of the left and right children of the node. If the child does not exist, a “-” will be put at the position. Any pair of children are separated by a space.

Output Specification:

For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
*/

#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

typedef struct TreeNode{
    int left,right;
}TreeNode;

vector<TreeNode> tree;

void levelOrderTraversal(int head){
    queue<int> Q;
    Q.push(head);
    while(Q.size()){
        printf("%d",Q.front());
        int left = tree[Q.front()].left;
        if(left != -1) Q.push(left);
        int right = tree[Q.front()].right;
        if(right != -1) Q.push(right);
        Q.pop();
        if(Q.size()) printf(" ");
    }
}

vector<int> inOrderSequence;
//构造中序序列，因为递归不方便省去最后一个空格
void inOrder(int head){
    //左
    int left = tree[head].left;
    if(left != -1){
        inOrder(tree[head].left);
    }
    //根
    inOrderSequence.push_back(head);
    //右
    int right = tree[head].right;
    if(right != -1){
        inOrder(right);
    }
}

//打印中序序列
void inOrderTraversal(int head){
    inOrder(head);
    for(int i = 0; i < inOrderSequence.size(); i ++){
        printf("%d",inOrderSequence[i]);
        if(i != (int)inOrderSequence.size()-1) printf(" ");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    tree.resize(n); //写这句话可以不经过push直接用下标访问vector
    int son[10] = {0};
    for(int i = 0; i < n; i ++){
        char c1,c2;
        //此处不能加\n，需要getchar()
        scanf("%c %c",&c1,&c2);
        getchar();
        if(c2 == '-') tree[i].left = -1;
        else {
            int c = c2 - '0';
            tree[i].left = c;
            son[c] ++;
        }
        if(c1 == '-') tree[i].right = -1;
        else {
            int c = c1 - '0';
            tree[i].right = c;
            son[c] ++;
        }
    }
    int head = 0;
    //某个结点均不在其他结点的左右孩子里，说明是根结点
    for(int i = 0; i < n; i ++){
        if(son[i] == 0){
            head = i;
            break;
        }
    }
    levelOrderTraversal(head);
    printf("\n");
    inOrderTraversal(head);
    return 0;
}
