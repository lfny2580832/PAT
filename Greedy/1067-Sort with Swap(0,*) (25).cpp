/*
1067. Sort with Swap(0,*) (25)
Given any permutation of the numbers {0, 1, 2,…, N-1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}

Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:

Each input file contains one test case, which gives a positive N (<=105) followed by a permutation sequence of {0, 1, …, N-1}. All the numbers in a line are separated by a space.

Output Specification:

For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10 3 5 7 2 6 4 9 0 8 1
Sample Output:
9
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

//应该用map存储下标，input[0] = 2,表示0在下标为2的位置

vector<int> input;

int wrongPos(int k,int n){
    for(; k < n; k ++)
        if(input[k] != k) return k;
    return -1;
}

int main(){
    int n;
    scanf("%d",&n);
    input.resize(n);
    int left = n - 1,tmp;
    for(int i = 0; i < n; i ++){
        scanf("%d",&tmp);
        input[tmp] = i;
        if(tmp != 0 && tmp == i) left--;
    }
    int index = 1,cnt = 0,k = 1;
    while(left > 0){
        //若0已就位，从小到大找不match的进行交换
        if(input[0] == 0){
            index = wrongPos(k,n);
            if(index == -1) break;  //每个位置都match
            swap(input[0],input[index]);
            left--;
            cnt ++;
        }
        else{
            index = input[0];
            swap(input[0], input[index]);
            cnt ++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
