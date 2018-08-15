/*
1021. Deepest Root (25)
A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes’ numbers.

Output Specification:

For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print “Error: K components” where K is the number of connected components in the graph.

Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

/*
 此题要明确一个树的性质：从任一结点开始dfs得到的最远结点Xn个，将Xn其中一个结点作为
 根结点进行dfs，得到新的最远结点Ym。此时Ym与Xn并集即为所求
 
 set默认升序
 */
vector<vector<int> > v; //邻接表
int visit[10001];
int maxd;
//存最深层对应的结点
vector<int> d_vec;

void dfs(int a,int d){
    visit[a] = 1;
    if(maxd < d){
        maxd = d;
        d_vec.clear();
        d_vec.push_back(a);
    }else if(maxd == d){
        d_vec.push_back(a);
    }
    for(int i = 0; i < v[a].size(); i ++){
        if(visit[v[a][i]] == 0){
            dfs(v[a][i],d+1);
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    v.resize(n+1);
    for(int i = 0; i < n-1; i ++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt = 0;
    set<int> result;
    int tmpR = 0;
    for(int i = 1; i <= n; i ++){
        if(visit[i] == 0){
            dfs(i,0);
            if(i == 1){ //记录第一次得到的Xn，在d_vec里
                tmpR = d_vec[0];
                for(int j = 0; j < d_vec.size(); j++){
                    result.insert(d_vec[j]);
                }
            }
            cnt++;
        }
    }
    if(cnt >= 2){
        printf("Error: %d components",cnt);
    }else{
        fill(visit, visit+10001, 0);
        dfs(tmpR, 0);
        for(int i = 0; i < d_vec.size(); i ++){
            result.insert(d_vec[i]);
        }
        for(auto it = result.begin(); it != result.end(); it++){
            printf("%d\n",*it);
        }
    }
    return 0;
}
