/*
1020 Tree Traversals (25)（25 分）

Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:

7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:

4 1 6 3 5 7 2
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
}TNode;

//post[a,b],in[c,d]
TNode* postInCreate(vector<int> post_vec,vector<int> in_vec,int a, int b, int c, int d){
    TNode* root = new TNode;
    root->data = post_vec[b];
    int pos = 0;
    //找到根结点在中序序列中的位置
    for(int i = c; i <= d; i ++){
        if(in_vec[i] == root->data){
            pos = i;
            break;
        }
    }
    //根据中序序列判断左右字段长度（前/后序也可以，写着麻烦）
    int l_len = pos - c;
    int r_len = d - pos;
    if(l_len)
        root->left = postInCreate(post_vec, in_vec, a, a + l_len-1, c, c + l_len-1);
    else
        root->left = NULL;
    if(r_len)
        root->right = postInCreate(post_vec, in_vec, b- r_len ,b - 1, d - r_len + 1 , d);
    else
        root->right = NULL;
    return root;
}

void levelOrderTraversal(TNode *root){
    queue<TNode *> Q;
    Q.push(root);
    while(Q.size()){
        TNode *node = Q.front();
        printf("%d",node->data);
        Q.pop();
        if(node->left) Q.push(node->left);
        if(node->right) Q.push(node->right);
        if(Q.size()) printf(" ");
    }
}

int main(){
    vector<int> post_vec,in_vec;
    int n;
    scanf("%d\n",&n);
    for(int i = 0; i < n; i ++){
        int tmp;
        scanf("%d",&tmp);
        post_vec.push_back(tmp);
    }
    cin.get();
    for(int i = 0; i < n; i ++){
        int tmp;
        scanf("%d",&tmp);
        in_vec.push_back(tmp);
    }
    TNode *root = postInCreate(post_vec, in_vec, 0, n-1, 0, n-1);
    levelOrderTraversal(root);
    return 0;
}
