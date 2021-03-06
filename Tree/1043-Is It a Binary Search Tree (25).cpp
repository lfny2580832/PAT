/*
1043 Is It a Binary Search Tree (25)（25 分）

A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.

Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in a line "YES" if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or "NO" if not. Then if the answer is "YES", print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:

7
8 6 5 7 10 8 11
Sample Output 1:

YES
5 7 6 8 11 10 8
Sample Input 2:

7
8 10 11 8 6 7 5
Sample Output 2:

YES
11 8 10 7 5 6 8
Sample Input 3:

7
8 6 8 5 10 9 11
Sample Output 3:

NO
*/

#include<stdio.h>
#include<vector>
using namespace std;

struct Node{
    int val;
    Node *left,*right;
};

Node *root = new Node;
vector<int> seq_vec,postOrder;
bool isMirror;

void getpost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) {
        while(i <= tail && seq_vec[root] > seq_vec[i]) i++;
        while(j > root && seq_vec[root] <= seq_vec[j]) j--;
    } else {
        while(i <= tail && seq_vec[root] <= seq_vec[i]) i++;
        while(j > root && seq_vec[root] > seq_vec[j]) j--;
    }
    if(i - j != 1) return;
    
    //后序遍历，前面的计算只是为拿到参数，不满足条件的直接当成空树
    getpost(root + 1, j);
    getpost(i, tail);
    postOrder.push_back(seq_vec[root]);
}

int main(){
    int n;
    scanf("%d",&n);
    seq_vec.resize(n);
    for(int i = 0; i < n; i ++){
        scanf("%d",&seq_vec[i]);
    }
    getpost(0, n - 1);
    if(postOrder.size() != n) {
        isMirror = true;
        postOrder.clear();
        getpost(0, n - 1);
    }
    if(postOrder.size() == n) {
        printf("YES\n%d", postOrder[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", postOrder[i]);
    } else {
        printf("NO");
    }
    return 0;
}
