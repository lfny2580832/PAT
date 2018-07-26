/*
1048. Find Coins (25)
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 105 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=105, the total number of coins) and M(<=103, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the two face values V1 and V2 (separated by a space) such that V1 + V2 = M and V1 <= V2. If such a solution is not unique, output the one with the smallest V1. If there is no solution, output “No Solution” instead.

Sample Input 1:
8 15
1 2 8 7 2 4 11 15
Sample Output 1:
4 11
Sample Input 2:
7 14
1 8 7 2 4 11 15
Sample Output 2:
No Solution*/

#include<iostream>
using namespace std;

/*
大数组得定义成全局变量，这样会保存在堆上
若定义在函数中（如main函数），则是局部变量，定义在动态分配的栈上，大数组容易栈溢出
*/
int nums[1001];

int main(){
    int m,n; //个数 和
    scanf("%d %d",&m,&n);
    //建立数值、数量的散列表
    int temp;
    for(int i = 0; i < m; i++){
        scanf("%d",&temp);
        nums[temp]++;
    }
    for(int i = 0; i < 1001; i ++){
        if(nums[i]){
            nums[i]--;
            if(n > i && nums[n-i]){
                printf("%d %d", i, n - i);
                return 0;
            }
            nums[i]++;
        }
    }
    printf("No Solution");
    return 0;
}
















