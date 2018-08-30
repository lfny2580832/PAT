/*
1003. Emergency (25)
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) – the number of cities (and the cities are numbered from 0 to N-1), M – the number of roads, C1 and C2 – the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

/*
 注意参数数组的初始化经历三个阶段：
 1.设置起点的参数
 2.设置起点连接点的参数
 3.循环遍历设置参数
 */

const int maxValue = 0x7fffffff;
int g[501][501];
vector<int> secures;    //每个城市的救援队员人数
vector<int> dist;
vector<int> path;
vector<int> s;
vector<int> pathNum;    //到城市i的最短路径的个数
vector<int> allSecures;    //到城市i的路径上的救援队员人数之和

void initVec(int n){
    secures.resize(n);dist.resize(n);path.resize(n);
    s.resize(n);pathNum.resize(n);secures.resize(n);
    allSecures.resize(n);
    fill(g[0],g[0]+501*501,maxValue);
    fill(dist.begin(),dist.end(),maxValue);
}

int main(){
    int n,m,c1,c2;
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    initVec(n);
    for(int i = 0; i < n; i ++){
        scanf("%d",&secures[i]);
    }
    for(int i = 0; i < m; i ++){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        g[a][b] = g[b][a] = w;
    }
    //初始化c1城市的各项参数
    dist[c1] = 0;
    pathNum[c1] = 1;  allSecures[c1] = secures[c1];
    //初始化dis数组
    for(int i = 0; i < n; i ++){
        dist[i] = g[c1][i];
        //起点的连接点进行参数初始化
        if(dist[i] < maxValue && i != 0){
            pathNum[i] = pathNum[c1];
            allSecures[i] = secures[i] + allSecures[c1];
        }
        s[i] = 0;
    }
    s[c1] = 1;
    //进行n-1次循环即可，一次确定一个点的最短路径
    for(int i = 0; i < n-1 ; i ++){
        //选一个当前最短路径的顶点
        int min = maxValue;
        int u = c1;  //
        for(int j = 0; j < n; j++){
            if(s[j] == 0 && dist[j] < min){
                min = dist[j];
                u = j;
            }
        }
        s[u] = 1;
        //以u为基点再看u连接的城市
        for(int k = 0; k < n; k ++){
            if(s[k] != 1 && g[u][k] < maxValue){
                if(dist[u] + g[u][k] < dist[k]){
                    dist[k] = dist[u] + g[u][k];
                    //*********************
                    pathNum[k] = pathNum[u];
                    allSecures[k] += allSecures[u] + secures[k];
                    //*********************
                }else if(dist[u] + g[u][k] == dist[k]){
                    //*********************
                    //假设到u有10条最短路径，u还没尝试到k时，k有20条路径，则当u到k也是k最短路径时，到k的最短路径有10+20条
                    pathNum[k] = pathNum[u] + pathNum[k];
                    if(allSecures[u] + secures[k] > allSecures[k]){
                        allSecures[k] = secures[k] + allSecures[u];
                    }
                    //*********************
                }
            }
        }
    }
    printf("%d %d",pathNum[c2],allSecures[c2]);
    return 0;
}
