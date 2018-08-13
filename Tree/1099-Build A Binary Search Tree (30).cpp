/*
1099. Build A Binary Search Tree (30)
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than or equal to the node’s key.
Both the left and right subtrees must also be binary search trees.
Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2.
Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100) which is the total number of nodes in the tree. The next N lines each contains the left and the right children of a node in the format “left_index right_index”, provided that the nodes are numbered from 0 to N-1, and 0 is always the root. If one child is missing, then -1 will represent the NULL child pointer. Finally N distinct integer keys are given in the last line.

Output Specification:

For each test case, print in one line the level order traversal sequence of that tree. All the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:
58 25 82 11 38 67 45 73 42
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Node{
    int left,right,value;
};

vector<Node> tree_vec;
vector<int> seq_vec;
int i = 0;

void inOder(int v){
    if(v == -1) return;
    inOder(tree_vec[v].left);
    //按从小到大顺序给中序遍历的结点赋值，由于此处是递归，所以应由外部变量i来控制输入流
    tree_vec[v].value = seq_vec[i];
    i++;
    inOder(tree_vec[v].right);
}

void levelOrder(int v){
    queue<int> q;
    q.push(v);
    vector<int> print_vec;
    while(q.size()){
        Node node = tree_vec[q.front()];
        print_vec.push_back(node.value);
        if(node.left != -1) q.push(node.left);
        if(node.right != -1) q.push(node.right);
        q.pop();
    }
    for(int i = 0; i < print_vec.size(); i ++){
        printf("%d",print_vec[i]);
        if(i != print_vec.size()-1) printf(" ");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    tree_vec.resize(n);
    seq_vec.resize(n);
    for(int i = 0; i < n; i ++){
        scanf("%d %d",&tree_vec[i].left,&tree_vec[i].right);
    }
    for(int i = 0; i < n; i ++){
        scanf("%d",&seq_vec[i]);
    }
    sort(seq_vec.begin(), seq_vec.end());
    inOder(0);
    levelOrder(0);
    return 0;
}
