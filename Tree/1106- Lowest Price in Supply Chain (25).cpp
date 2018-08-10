/*
1106. Lowest Price in Supply Chain (25)
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）– everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one’s supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the lowest price a customer can expect from some retailers.

Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence their ID’s are numbered from 0 to N-1, and the root supplier’s ID is 0); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:

Ki ID[1] ID[2] … ID[Ki]

where in the i-th line, Ki is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID’s of these distributors or retailers. Kj being 0 means that the j-th member is a retailer. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the lowest price we can expect from some retailers, accurate up to 4 decimal places, and the number of retailers that sell at the lowest price. There must be one space between the two numbers. It is guaranteed that the all the prices will not exceed 1010.

Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0
Sample Output:
1.8362 2
*/

/*
题目比较难读懂，主要是不知道树是怎么输入的。
如第0行有三个结点2、3、5，则0的儿子有2、3、5
第1行是结点9，则1的儿子是9
第2行是结点4，则2的儿子是4
…………
因为供应商使用自然数表示的，因此输入里的下标就代表供应商结点（用0到n来表示）
建好的树：
0
	2	4
		
	3	7
		
	5	6	8
		
		1	9
		
			
*/
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;

/*
 此题坑较多：
 1.case很大，deepMin应写到最大
 2.剪枝在某些case可减少1-10ms的时间
 3.少用vector<vector<int> > vec这样的大向量，
   应选用vector<int> vec[n] 这样的向量数组，
   否则会
 4.若先提取出来会运行超时，应直接访问按二维数组下标去访问
   vector<int> child = tree_vec[v];
   DFS(child[i], depth+1);
 5.大数组应写成全局变量，否则可能会导致栈溢出
 */

vector<int> tree_vec[100005];
int deepMin = 99999999, minNum = 1;
//其实是图的深搜，但因为是树状图，无需visited数组
void DFS(int v, int depth){
    //剪枝，超过的没必要继续搜他们的儿子了
    if(deepMin < depth) return;
    //访问顶点v,此处只需访问叶节点
    if(tree_vec[v].size() == 0){
        if(depth < deepMin){
            deepMin = depth;
            minNum = 1;
        }else if(depth == deepMin)
            minNum ++;
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
    for(int i = 0; i < N; i ++){
        int n;
        scanf("%d",&n);
        for(int j = 0; j < n; j ++){
            int tmp;
            scanf("%d",&tmp);
            tree_vec[i].push_back(tmp);
        }
    }
    //注意此时的vector已经相当于图里的邻接表了，可以直接用来深搜了，无需再建树
    DFS(0,0);
    printf("%.4lf %d",P * pow(1+r/100, deepMin),minNum);
    return 0;
}


























