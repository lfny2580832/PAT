/*
1076. Forwards on Weibo (30)
Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=1000), the number of users; and L (<=6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:

M[i] user_list[i]

where M[i] (<=100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that are followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.

Then finally a positive K is given, followed by K UserID’s for query.

Output Specification:

For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.

Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5
*/

#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*
 第i行代表的是：i用户关注了哪几个用户，如第一行代表：1关注了2，3，4，意味着2、3、4的转推可到达1，据此建图
 超时优化：
 1.邻接表从二重向量到向量数组，不过影响微乎其微(2ms)
 2.主要是要在遍历过程中统计结果(ansCnt)，而不是遍历完再遍历一遍visit，这样会直接导致超时
 注意：
 */
vector<vector<int> > v; //邻接表
int visit[1001];
int N,L;

void BFS(int r){
    fill(visit,visit+1001,0);
    queue<int> q;
    q.push(r);
    visit[r] = 1;
    int curL = 0;	//当前层数，根为0
    //当前层剩下的结点/ 下一层要访问的结点数/ 广搜L层以内遍历的结点数即答案
    int leftCnt = 1,nextCnt = 0,ansCnt = 0;
    while (q.size() && curL < L) {
        int f = q.front();
        q.pop();
        for(int i = 0; i < v[f].size(); i ++){
            if(visit[v[f][i]] == 0){
                q.push(v[f][i]);
                visit[v[f][i]] = 1;		//在此处访问是为了统计ansCnt，同时少算一层
                nextCnt ++;
            }
        }
        leftCnt --;
        if(leftCnt == 0){
			ansCnt += nextCnt;
            leftCnt = nextCnt;
            nextCnt = 0;
            curL ++;
        }
    }
    printf("%d\n",ansCnt);
}

int main(){
    scanf("%d %d",&N,&L);
    v.resize(N+1);
    for(int i = 1; i <= N; i ++){
        int k;
        scanf("%d",&k);
        for(int j = 0; j < k; j++){
            int t;
            scanf("%d",&t);
            v[t].push_back(i);
        }
    }
    int x;
    scanf("%d",&x);
    for(int i = 0; i < x; i ++){
        int a;
        scanf("%d",&a);
        BFS(a);
    }
    return 0;
}
