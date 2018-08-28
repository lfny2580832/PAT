/*
1107. Social Clusters (30)
When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. A “social cluster” is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.
Input Specification:
Each input file contains one test case. For each test case, the first line contains a positive integer N (<=1000), the total number of people in a social network. Hence the people are numbered from 1 to N. Then N lines follow, each gives the hobby list of a person in the format:
Ki: hi[1] hi[2] … hi[Ki]
where Ki (>0) is the number of hobbies, and hi[j] is the index of the j-th hobby, which is an integer in [1, 1000].
Output Specification:
For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in the clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of the line.
Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
Sample Output:
3
4 3 1
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

//此题注意一个圈子里可以有不同爱好，只要圈子里有一个人跟你有一样的爱好，你就属于这个圈子

vector<int> course(1001,0); //course[5] = 3,表示3号用户喜欢课程5
vector<int> ufset(1001);
int isRoot[1001] = {0};

bool cmp(int a,int b){ return a > b; }

void initial(int n){
    for(int i = 1; i <= n; i ++)
        ufset[i] = i;
}

int findRoot(int x){
    while(x != ufset[x])
        x = ufset[x];
    return x;
}

void Union(int a,int b){
    //***a有不同爱好，可能因为前面的爱好已经并入了某圈子，所以要findRoot(a)
    int fa = findRoot(a);
    int fb = findRoot(b);
    //合并子集（合并两个圈子）
    ufset[fa] = fb;
}

int main(){
    int n;
    scanf("%d",&n);
    initial(n);
    for(int i = 1; i <= n; i ++){
        int k;  scanf("%d:",&k);
        for(int j = 0; j < k; j ++){
            int c;  scanf("%d",&c);
            if(course[c] == 0)
                course[c] = i;
            else
                //当course[i]!=0时，表示该课程之前也有人喜欢，合并i和course[c]这两人的圈子
                Union(i,findRoot(course[c]));
        }
    }
    for(int i = 1; i <= n; i ++){
        isRoot[findRoot(i)]++;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(isRoot[i] != 0) cnt++;
    }
    printf("%d\n",cnt);
    sort(isRoot,isRoot+1001,cmp);
    for(int i = 0; i < cnt; i ++){
        printf("%d",isRoot[i]);
        if(i != cnt -1 ) printf(" ");
    }
    return 0;
}
/*
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 4 8 1 5
1: 4
 */
