/*
1030. Travel Plan (30)
A traveler’s map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:

City1 City2 Distance Cost

where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:

For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

/*
 有些答案还要djkstra+dfs，其实只要是求最短路径里满足某种条件的
 都能直接用djkstra搞定
 */

const int maxValue = 0x7fffffff;

struct edge{
    int dist = maxValue,cost = 0;
}g[501][501];

vector<int> dist;
vector<int> path;
vector<int> cost;
vector<int> set;

void initVec(int n){
    dist.resize(n);
    set.resize(n);
    cost.resize(n);
    path.resize(n);
    fill(dist.begin(),dist.end(),maxValue);
}

//输出s到d的路径
void outputPath(int s,int d){
    int x = d;
    vector<int> st;
    st.push_back(x);
    while(path[x] != -1){
        x = path[x];
        st.push_back(x);
    }
    for(int i = (int)st.size()-1; i >= 0; i --){
        printf("%d ",st[i]);
    }
}

int main(){
    int n,m,s,d;
    scanf("%d %d %d %d",&n,&m,&s,&d);
    initVec(n);
    for(int i = 0; i < m; i ++){
        int a,b,w,c;
        scanf("%d %d %d %d",&a,&b,&w,&c);
        g[a][b].dist = g[b][a].dist = w;
        g[a][b].cost = g[b][a].cost = c;
    }
    //初始化距离、路径数组
    for(int i = 0; i < n; i ++){
        dist[i] = g[s][i].dist;
        cost[i] = g[s][i].cost;
        set[i] = 0;
        if(dist[i] < maxValue) path[i] = s;
        else path[i] = -1;
    }
    dist[s] = 0;    set[s] = 1;
    //进行n-1次循环即可，一次确定一个点的最短路径
    for(int i = 0; i < n-1 ; i ++){
        int min = maxValue;
        int u = s;  //选一个已经get最短路径的点u
        for(int j = 0; j < n; j++){
            if(set[j] == 0 && dist[j] < min){
                min = dist[j];
                u = j;
            }
        }
        set[u] = 1;
        for(int k = 0; k < n; k ++){
            if(set[k] != 1 && g[u][k].dist < maxValue){
                if(dist[u] + g[u][k].dist < dist[k]){
                    dist[k] = dist[u] + g[u][k].dist;
                    //*********************
                    cost[k] = cost[u] + g[u][k].cost;
                    //*********************
                    path[k] = u;
                }else if(dist[u] + g[u][k].dist == dist[k]){
                    //*********************
                    if(cost[u] + g[u][k].cost < cost[k]){
                        path[k] = u;
                        cost[k] = cost[u] + g[u][k].cost;
                    }
                    //*********************
                }
            }
        }
    }
    outputPath(s,d);
    printf("%d %d",dist[d],cost[d]);
    return 0;
}
