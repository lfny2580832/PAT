/*
1119. Pre- and Post-order Traversals (30)
Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences, or preorder and inorder traversal sequences. However, if only the postorder and preorder traversal sequences are given, the corresponding tree may no longer be unique.

Now given a pair of postorder and preorder traversal sequences, you are supposed to output the corresponding inorder traversal sequence of the tree. If the tree is not unique, simply output any one of them.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the preorder sequence and the third line gives the postorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first printf in a line “Yes” if the tree is unique, or “No” if not. Then print in the next line the inorder traversal sequence of the corresponding binary tree. If the solution is not unique, any answer would do. It is guaranteed that at least one solution exists. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input 1:
7
1 2 3 4 6 7 5
2 6 7 4 5 3 1
Sample Output 1:
Yes
2 1 6 4 7 3 5
Sample Input 2:
4
1 2 3 4
2 4 3 1
Sample Output 2:
No
2 1 3 4
*/


//
#include<stdio.h>
#include<vector>
using namespace std;

/*
 注意此题输出结果后要换行。。。。。
 */
struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int _val = -1){
        val = _val;
        left = NULL;
        right = NULL;
    }
};
vector<int>in,pre,post;

void inOrder(Node *root){
    if(!root) return;
    inOrder(root->left);
    in.push_back(root->val);
    inOrder(root->right);
}
/*
 前序中第一个位置是根，第二个位置是左或右孩子,后序中最后一个是根，倒数第二个是左或右孩子
 在前序中找后序倒数第二个节点，若在前序的第二个位置之后，则前序该位置节点为右节点
 或者在后序中找前序第二个节点，做和最后根结点之间还有节点，说明前序第二个结点是左结点
 */
bool uni = true;
Node *create(int pre_L,int pre_R,int post_L,int post_R){
    if(pre_L > pre_R) return NULL;
    Node *root = new Node(pre[pre_L]);
    if(pre_L == pre_R){
        return root;
    }
    int k;
    for(k = post_L; k < post_R; k++){
        if(post[k] == pre[pre_L+1]) break;
    }
    if(post_R - k - 1 > 0){
        root->left = create(pre_L+1, pre_L+1+k-post_L, post_L, k);
        root->right = create(pre_L+1+k-post_L+1, pre_R, k+1, post_R-1);
    }else{
        uni = false;
        root->right = create(pre_L+1, pre_R, post_L, post_R-1);
    }
    return root;
}

int main(){
    int n;
    scanf("%d",&n);
    pre.resize(n); post.resize(n);
    for(int i = 0; i < n; i ++){
        scanf("%d",&pre[i]);
    }
    for(int i = 0; i < n; i ++){
        scanf("%d",&post[i]);
    }
    Node *root = create(0, n-1, 0, n-1);
    if(uni) printf("Yes\n");
    else printf("No\n");
    inOrder(root);
    for(int i = 0; i < in.size(); i ++){
        printf("%d",in[i]);
        if(i != in.size()-1) printf(" ");
        else printf("\n");
    }
    return 0;
}

