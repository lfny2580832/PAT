/*
1086 Tree Traversals Again (25)（25 分）

An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.

\ Figure 1

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:

6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:

3 4 2 6 5 1
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
 本题只使用先序序列遍历来创建二叉树（因为给了叶节点信息）
 先序创建二叉树要求实时输入结点
 而已知先序序列不同，需要用外部变量来控制vector的遍历
 当然也可以用先序加中序构造二叉树，只不过别的题用过了
 */
typedef struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
}TreeNode;

int i = 0;

int stringToInt(string s){
    int r = 0, d = 1;
    for(int i = (int)s.length()-1; i >= 0; i --){
        r += (s[i] - '0') * d;
        d = d * 10;
    }
    return r;
}

//由前序输入构建二叉树修改而来，由外部变量结合先序控制输入流
TreeNode *create(vector<string> node_data_vec){
    TreeNode *root = new TreeNode;
    if(i >= node_data_vec.size()) return NULL;
    if(node_data_vec[i] == " "){
        root = NULL;
        i++;
    }else{
        root = new TreeNode;
        root->data = stringToInt(node_data_vec[i]);
        i++;
        root->left = create(node_data_vec);
        root->right = create(node_data_vec);
    }
    return root;
}

void postOrderTraversal(TreeNode *root){
    if(!root) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ",root->data);
}

int main(){
    int n;
    scanf("%d\n",&n);
    vector<string> node_data_vec;
    n = n * 2;
    while(n){
        string s;
        getline(cin,s);
        if(s.substr(0,4) == "Push"){
            node_data_vec.push_back(s.substr(5));
        }else{
            node_data_vec.push_back(" ");
        }
        n--;
    }
    TreeNode *root = create(node_data_vec);
    postOrderTraversal(root);
    return 0;
}
