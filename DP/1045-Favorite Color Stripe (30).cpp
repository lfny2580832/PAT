/*
最长上升子序列LIS：https://www.youtube.com/watch?v=CE2b_-XfVDk 
1045. Favorite Color Stripe (30)
Eva is trying to make her own color stripe out of a given one. She would like to keep only her favorite colors in her favorite order by cutting off those unwanted pieces and sewing the remaining parts together to form her favorite color stripe.

It is said that a normal human eye can distinguish about less than 200 different colors, so Eva’s favorite colors are limited. However the original stripe could be very long, and Eva would like to have the remaining favorite stripe with the maximum length. So she needs your help to find her the best result.

Note that the solution might not be unique, but you only have to tell her the maximum length. For example, given a stripe of colors {2 2 4 1 5 5 6 3 1 1 5 6}. If Eva’s favorite colors are given in her favorite order as {2 3 1 5 6}, then she has 4 possible best solutions {2 2 1 1 1 5 6}, {2 2 1 5 5 5 6}, {2 2 1 5 5 6 6}, and {2 2 3 1 1 5 6}.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=200) which is the total number of colors involved (and hence the colors are numbered from 1 to N). Then the next line starts with a positive integer M (<=200) followed by M Eva’s favorite color numbers given in her favorite order. Finally the third line starts with a positive integer L (<=10000) which is the length of the given stripe, followed by L colors on the stripe. All the numbers in a line are separated by a space.

Output Specification:

For each test case, simply print in a line the maximum length of Eva’s favorite stripe.

Sample Input:
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
Sample Output:
7
*/

//此题将喜欢的颜色序列赋予顺序，将给的总颜色用顺序下标代替，即完全转换为最长上升子序列问题（求给定序列某个序列最长的长度）

#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<int,int> order;  //用来将input的颜色转换为颜色顺序
vector<int> input;

int LIS(){
    int len = (int)input.size();
    vector<int> dp(len);
    fill(dp.begin(),dp.end(),1);
    for(int i = 1; i < len; i ++){
        for(int j = 0; j < i; j ++){
            if(input[j] <= input[i]){
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
    }
    int max = 0;
    for(int i = 0; i < len; i ++){
        if(dp[i] > max) max = dp[i];
    }
    return max;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0; i < k; i ++){
        int a;
        scanf("%d",&a);
        order[a] = i+1;
    }
    scanf("%d",&k);
    for(int i = 0; i < k; i ++){
        int a;
        scanf("%d",&a);
        if(order.find(a) != order.end()){
            input.push_back(order[a]);
        }
            
    }
    printf("%d",LIS());
    return 0;
}
