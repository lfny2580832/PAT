/*
1034. Head of a Gang (30)
One way that the police finds the head of a gang is to check people’s phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A “Gang” is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threthold, respectively. Then N lines follow, each in the following format:

Name1 Name2 Time

where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.

Output Specification:

For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.

Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3
Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
*/

#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

/*
 设置数组上限一定要按题目来
 此题用两个map来进行string和int的转换
 计算总权重后要把这条边去掉 Graph设0
 weight数组用来找团伙的头
 结果用map存储，顺便可以按字母排序
 */

int N,K;
//通过两个map做string和int的转换，不用靠ASCII转
map<string,int> stringToInt;
map<int,string> intToString;

#define maxn 2001
int Graph[maxn][maxn],weight[maxn],visit[maxn];

int id = 1;
int nameToId(string s){
    if(stringToInt[s] == 0){
        stringToInt[s] = id;
        intToString[id] = s;
        return id++;    //返回id后才自增
    }else{
        return stringToInt[s];
    }
}

void dfs(int v, int &head,int &memCnt, int &totalWeight){
    visit[v] = 1;
    memCnt ++;
    //各节点的weight在输入时已确定，dfs时比较即可
    if(weight[v] > weight[head]) head = v;
    //深搜时计算团伙权重
    for(int i = 1; i < id; i ++){
        if(Graph[v][i] > 0){
            totalWeight += Graph[v][i];
            Graph[v][i] = Graph[i][v] = 0;
            if(visit[i] == 0){
                dfs(i, head, memCnt, totalWeight);
            }
        }
    }
}

// 结果 <团伙的头,团伙人数>
map<string,int> ans;

void findGangs(){
    //id正好比节点多1
    for(int i = 1; i < id; i ++){
        if(visit[i] == 0){
            int memCnt = 0, totalWeight = 0; //每个团伙中的人数，团伙电话权重
            int head = i;   //暂时让i当head，dfs后head为结果
            dfs(i,head,memCnt,totalWeight);
            if(totalWeight > K && memCnt > 2){
                ans[intToString[head]] = memCnt;
            }
        }
    }
}

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i ++){
        string s1,s2;
        int w;
        cin >> s1 >> s2 >> w;
        int id1 = nameToId(s1);
        int id2 = nameToId(s2);
        //weight为了找头目
        weight[id1] += w;
        weight[id2] += w;
        Graph[id1][id2] += w;
        Graph[id2][id1] += w;
    }
    //找团伙
    findGangs();
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}














