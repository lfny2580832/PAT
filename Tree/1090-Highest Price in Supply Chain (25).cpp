/*
1090 Highest Price in Supply Chain (25)（25 分）

A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.

Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=10^5^), the total number of the members in the supply chain (and hence they are numbered from 0 to N-1); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then the next line contains N numbers, each number S~i~ is the index of the supplier for the i-th member. S~root~ for the root supplier is defined to be -1. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the highest price we can expect from some retailers, accurate up to 2 decimal places, and the number of retailers that sell at the highest price. There must be one space between the two numbers. It is guaranteed that the price will not exceed 10^10^.

Sample Input:

9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:

1.85 2
*/

/*
建树时，下标代表供应链中的成员，下标表示的数字代表该成员的上级（父节点）
*/
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

vector<int> tree_vec[100005];
//两个变量初试都应为0，否则case不过
int deepMax = 0, maxNum = 0;
//其实是图的深搜，但因为是树状图，无需visited数组
void DFS(int v, int depth){
    //访问顶点v,此处只需访问叶节点
    if(tree_vec[v].size() == 0){
        if(depth > deepMax){
            deepMax = depth;
            maxNum = 1;
        }else if(depth == deepMax)
            maxNum ++;
    }
    //递归访问该顶点下的其他顶点儿子
    for(int i = 0; i < tree_vec[v].size(); i ++){
        DFS(tree_vec[v][i], depth+1);
    }
}

int main(){
    int N;
    double P,r;
    scanf("%d %lf %lf",&N,&P,&r);
    int head = 0;
    for(int i = 0; i < N; i ++){
        int index;
        scanf("%d",&index);
        if(index != -1) tree_vec[index].push_back(i);
        else head = i;
    }
    //注意此时的vector已经相当于图里的邻接表了，可以直接用来深搜了，无需再建树
    DFS(head,0);
    printf("%.2lf %d",P * pow(1+r/100, deepMax),maxNum);
    return 0;
}
