/*
1079. Total Sales of Supply Chain (25)
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）– everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one’s supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the total sales from all the retailers.

Input Specification:

Each input file contains one test case. For each case, the first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence their ID’s are numbered from 0 to N-1, and the root supplier’s ID is 0); P, the unit price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:

Ki ID[1] ID[2] … ID[Ki]

where in the i-th line, Ki is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID’s of these distributors or retailers. Kj being 0 means that the j-th member is a retailer, then instead the total amount of the product will be given after Kj. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the total sales we can expect from all the retailers, accurate up to 1 decimal place. It is guaranteed that the number will not exceed 1010.

Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
Sample Output:
42.4
*/

/*
每行输入第一个数为0时，表示该行对应的是零售商的物品存货数量
*/

#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

double P,r;
vector<int> tree_vec[100005];
int inventory[100005] = {0};
double sum = 0;
//其实是图的深搜，但因为是树状图，无需visited数组
void DFS(int v, int depth){
    //访问顶点v,此处只需访问叶节点
    if(tree_vec[v].size() == 0){
        sum += P*pow((1+r/100), depth)*inventory[v];
    }
    //递归访问该顶点下的其他顶点儿子
    for(int i = 0; i < tree_vec[v].size(); i ++){
        DFS(tree_vec[v][i], depth+1);
    }
}

int main(){
    int N;
    scanf("%d %lf %lf\n",&N,&P,&r);
    for(int i = 0; i < N; i ++){
        int n;
        scanf("%d",&n);
        if(n != 0){
            for(int j = 0; j < n; j ++){
                int m;
                scanf("%d",&m);
                tree_vec[i].push_back(m);
            }
        }else{
            int c;
            scanf("%d",&c);
            inventory[i] = c;
        }
    }
    //注意此时的vector已经相当于图里的邻接表了，可以直接用来深搜了，无需再建树
    DFS(0,0);
    printf("%.1lf",sum);
    return 0;
}
