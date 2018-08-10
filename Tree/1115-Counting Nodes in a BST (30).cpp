/*
1115. Counting Nodes in a BST (30)
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than or equal to the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
Both the left and right subtrees must also be binary search trees.
Insert a sequence of numbers into an initially empty binary search tree. Then you are supposed to count the total number of nodes in the lowest 2 levels of the resulting tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=1000) which is the size of the input sequence. Then given in the next line are the N integers in [-1000 1000] which are supposed to be inserted into an initially empty binary search tree.

Output Specification:

For each case, print in one line the numbers of nodes in the lowest 2 levels of the resulting tree in the format:

n1 + n2 = n

where n1 is the number of nodes in the lowest level, n2 is that of the level above, and n is the sum.

Sample Input:
9
25 30 42 16 20 20 35 -5 28
Sample Output:
2 + 4 = 6
*/

#include<stdio.h>
#include<vector>
using namespace std;

struct BSTNode{
    int value;
    BSTNode *left,*right;
};

BSTNode *insertBST(BSTNode *root, int r){
    if(root == NULL){
        root = new BSTNode;
        root->value = r;
        root->left = root->right = NULL;
    }else if(r <= root->value){
        root->left = insertBST(root->left,r);
    }else if(r > root->value){
        root->right = insertBST(root->right,r);
    }
    return root;
}

int maxdepth = -1;
int deepNum[1000];
void preOder(BSTNode *root, int depth){
    if(root == NULL){
        //最大深度只可能是叶节点，且需要最大深度来帮助输出
        if(depth > maxdepth) maxdepth = depth;
        return;
    }
    deepNum[depth]++;
    preOder(root->left,depth + 1);
    preOder(root->right,depth + 1);
}

int main(){
    int n;
    scanf("%d",&n);
    BSTNode *root = NULL;
    for(int i = 0; i < n; i ++){
        int r;
        scanf("%d",&r);
        root = insertBST(root,r);
    }
    preOder(root, 0);
    printf("%d + %d = %d",deepNum[maxdepth-1],deepNum[maxdepth-2],deepNum[maxdepth-1]+deepNum[maxdepth-2]);
    return 0;
}
