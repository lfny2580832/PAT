/*
1046 Shortest Distance (20)（20 分）

The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.

Input Specification:

Each input file contains one test case. For each case, the first line contains an integer N (in [3, 10^5^]), followed by N integer distances D~1~ D~2~ ... D~N~, where D~i~ is the distance between the i-th and the (i+1)-st exits, and D~N~ is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (<=10^4^), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 10^7^.

Output Specification:

For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

Sample Input:

5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:

3
10
7
*/

#include<stdio.h>
#include<vector>

using namespace std;

/*
一个环上有n个结点，每个结点之间距离不同，求两个结点之间最短的距离
即结果要么是两个结点之间距离之和，要么是总距离-两个结点之间距离之和
5 1 2 4 14 9
3
1 3
2 5
4 1
 */
vector<int> dis_vec;    //存储每个结点与原点的距离
int sum = 0;

int shortiest(int a,int b){
    int dis,redis;
    if(a > b){
        dis = dis_vec[a-1] - dis_vec[b-1];
    }else{
        dis = dis_vec[b-1] - dis_vec[a-1];
    }
    redis = sum - dis;
    return (dis > redis)? redis : dis;
}

int main(){
    int n;
    scanf("%d",&n);
    dis_vec.push_back(0);
    for(int i = 0; i < n; i ++){
        int d;
        scanf("%d",&d);
        sum += d;
        dis_vec.push_back(sum);
    }
    int m;
    scanf("%d",&m);
    for(int i = 0; i < m; i ++){
        int a,b;
        scanf("%d %d",&a,&b);
        int result = shortiest(a, b);
        printf("%d\n",result);
    }
    return 0;
}
