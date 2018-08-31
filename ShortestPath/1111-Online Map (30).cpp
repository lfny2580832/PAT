/*
1111. Online Map (30)
Input our current position and a destination, an online map can recommend several paths. Now your job is to recommend two paths to your user: one is the shortest, and the other is the fastest. It is guaranteed that a path exists for any request.

Input Specification:

Each input file contains one test case. For each case, the first line gives two positive integers N (2 <= N <= 500), and M, being the total number of streets intersections on a map, and the number of streets, respectively. Then M lines follow, each describes a street in the format:

V1 V2 one-way length time

where V1 and V2 are the indices (from 0 to N-1) of the two ends of the street; one-way is 1 if the street is one-way from V1 to V2, or 0 if not; length is the length of the street; and time is the time taken to pass the street.

Finally a pair of source and destination is given.

Output Specification:

For each case, first print the shortest path from the source to the destination with distance D in the format:

Distance = D: source -> v1 -> … -> destination

Then in the next line print the fastest path with total time T:

Time = T: source -> w1 -> … -> destination

In case the shortest path is not unique, output the fastest one among the shortest paths, which is guaranteed to be unique. In case the fastest path is not unique, output the one that passes through the fewest intersections, which is guaranteed to be unique.

In case the shortest and the fastest paths are identical, print them in one line in the format:

Distance = D; Time = T: source -> u1 -> … -> destination

Sample Input 1:
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5
Sample Output 1:
Distance = 6: 3 -> 4 -> 8 -> 5
Time = 3: 3 -> 1 -> 5
Sample Input 2:
7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5
Sample Output 2:
Distance = 3; Time = 4: 3 -> 2 -> 5
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

const int maxValue = 0x7fffffff;

//oneway是1的时候代表单向，看错这个浪费半天时间

struct edge{
    int distance = maxValue,time = maxValue;
}g[501][501];

vector<int> dist;
vector<int> timee;
vector<int> timePath;
vector<int> distPath;
vector<int> s;
vector<int> dpathCopy;
vector<int> tpathCopy;
int n,m,b,e;

void initVec(){
    dist.resize(n); timePath.resize(n);
    distPath.resize(n); s.resize(n);
    timee.resize(n);
    fill(s.begin(),s.end(),0);
    fill(distPath.begin(),distPath.end(),-1);
    fill(timePath.begin(),timePath.end(),-1);
    fill(dist.begin(),dist.end(),maxValue);
    fill(timee.begin(),timee.end(),maxValue);
}

vector<int> outputPathVec(vector<int> path){
    int x = e;
    vector<int> st;
    st.push_back(x);
    while(path[x] != -1){
        x = path[x];
        st.push_back(x);
    }
    return st;
}

void findDistPath(){
    initVec();
    //初始化数组
    for(int i = 0; i < n; i ++){
        if(g[b][i].distance < maxValue){
            dist[i] = g[b][i].distance;
            timee[i] = g[b][i].time;
            distPath[i] = b;
        }
    }
    s[b] = 1;
    for(int i = 0; i < n-1; i ++){
        //先找已经get最短路径的点u
        int min = maxValue, u = b;
        for(int j = 0; j < n; j ++){
            if(dist[j] < min && s[j] == 0){
                min = dist[j];
                u = j;
            }
        }
        s[u] = 1;
        for(int k = 0; k < n; k ++){
            if(s[k] == 0 && g[u][k].distance < maxValue){
                if(dist[u]+g[u][k].distance < dist[k]){
                    dist[k] = dist[u] + g[u][k].distance;
                    timee[k] = timee[u] + g[u][k].time;
                    distPath[k] = u;
                }else if(dist[u]+g[u][k].distance == dist[k]){
                    if(timee[u] + g[u][k].time < timee[k]){
                        timee[k] = timee[u] + g[u][k].time;
                        distPath[k] = u;
                    }
                }

            }
        }
    }
    dpathCopy = distPath;
}

void findTimePath(){
    initVec();
    vector<int> nodeNum(n,0);
    for(int i = 0; i < n; i ++){
        if(g[b][i].time < maxValue){
            timee[i] = g[b][i].time;
            timePath[i] = b;
        }
    }
    s[b] = 1;
    for(int i = 0; i < n-1; i ++){
        int min = maxValue, u = b;
        for(int j = 0; j < n; j ++){
            if(timee[j] < min && s[j] == 0){
                min = timee[j];
                u = j;
            }
        }
        s[u] = 1;
        for(int k = 0; k < n; k ++){
            if(s[k] == 0 && g[u][k].time < maxValue){
                if(timee[u] + g[u][k].time < timee[k]){
                    timee[k] = timee[u] + g[u][k].time;
                    timePath[k] = u;
                    nodeNum[k] = nodeNum[u] + 1;
                }
                else if(timee[u]+g[u][k].time == timee[k]){
                    if(nodeNum[u]+1 < nodeNum[k]){
                        timePath[k] = u;
                        nodeNum[k] = nodeNum[u] + 1;
                    }
                }
            }
        }
    }
    tpathCopy = timePath;
}

void printVec(vector<int> path){
    for(int i = (int)path.size()-1; i >= 0; i --){
        printf("%d",path[i]);
        if(i != 0) printf(" -> ");
    }
}

void output(){
    vector<int> doutput = outputPathVec(dpathCopy);
    vector<int> toutput = outputPathVec(tpathCopy);

    int d = 0;
    for(int i = (int)doutput.size()-1; i >= 0; i --){
        int a = doutput[i], b = doutput[i-1];
        if(i - 1 >= 0)
            d += g[a][b].distance;
    }
    int t = 0;
    for(int i = (int)toutput.size()-1; i >= 0; i --){
        int a = toutput[i], b = toutput[i-1];
        if(i - 1 >= 0)
            t += g[a][b].time;
    }
    bool isEqual = true;
    if(toutput.size() != doutput.size()) isEqual = false;
    else{
        for(int i = 0; i < doutput.size(); i ++){
            if(doutput[i] != toutput[i]) isEqual = false;
        }
    }
    if (isEqual) {
        printf("Distance = %d; Time = %d: ",d,t);
        printVec(doutput);
    }else{
        printf("Distance = %d: ",d);
        printVec(doutput); printf("\n");
        printf("Time = %d: ",t);
        printVec(toutput);
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0; i < m; i ++){
        int a,b,c,d,t;
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&t);
        g[a][b].distance = d;   g[a][b].time = t;
        if(i != 1){
            g[b][a].distance = d;
            g[b][a].time = t;
        }
    }
    scanf("%d %d",&b,&e);
    findDistPath();
    findTimePath();
    output();
    return 0;
}

