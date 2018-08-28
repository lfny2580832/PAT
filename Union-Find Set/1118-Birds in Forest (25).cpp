/*
1118. Birds in Forest (25)
Some scientists took pictures of thousands of birds in a forest. Assume that all the birds appear in the same picture belong to the same tree. You are supposed to help the scientists to count the maximum number of trees in the forest, and for any pair of birds, tell if they are on the same tree.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number N (<= 104) which is the number of pictures. Then N lines follow, each describes a picture in the format:
K B1 B2 … BK
where K is the number of birds in this picture, and Bi’s are the indices of birds. It is guaranteed that the birds in all the pictures are numbered continuously from 1 to some number that is no more than 104.

After the pictures there is a positive number Q (<= 104) which is the number of queries. Then Q lines follow, each contains the indices of two birds.

Output Specification:

For each test case, first output in a line the maximum possible number of trees and the number of birds. Then for each query, print in a line “Yes” if the two birds belong to the same tree, or “No” if not.

Sample Input:
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7
Sample Output:
2 10
Yes
No
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

/*
 一开始用了两个并查集，一个用来存图片，将图片并起来形成树，一个并查集根据图片设置鸟所属树，但运行超时
 修改后用一张照片的第一个鸟为根鸟来设置并查集，无需管有多少张图片
 */
const int maxn = 10010;
vector<int> ufset(maxn);

void initial(){
    for(int i = 1; i < maxn; i ++)
        ufset[i] = i;
}

//运行超时，需要进行路径压缩
int findRoot(int x){
    int a = x;
    while(x != ufset[x]){
        x = ufset[x];
    }
    //应当把向上查找遇到的点的值都设为根，这样下次查找再碰到就不用逐级向上了
    while(a != ufset[a]) {
        int z = a;
        a = ufset[a];
        ufset[z] = x;
    }
    return x;
}

void Union(int a,int b){
    int fa = findRoot(a);
    int fb = findRoot(b);
    ufset[fa] = fb;
}

int exist[maxn] = {0};

int main(){
    int n = 0;
    scanf("%d",&n);
    initial();
    set<int> birdSet;   //用来统计鸟的数量
    for(int i = 0; i < n; i ++){
        int k,id;
        scanf("%d %d",&k,&id);
        birdSet.insert(id);
        exist[id] = 1;
        for(int j = 0; j < k-1; j ++){
            int a;
            scanf("%d",&a);
            birdSet.insert(a);
            exist[a] = 1;

            Union(a, id);
        }
    }
    //统计树的数量
    set<int> treeSet;
    for(int i = 1; i < maxn; i ++){
        if(exist[i] == 1)
            treeSet.insert(findRoot(i));
    }
    printf("%d %d\n",(int)treeSet.size(),(int)birdSet.size());
    //查询
    int q;
    scanf("%d",&q);
    for(int i = 0; i < q; i ++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(findRoot(a) == findRoot(b)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


