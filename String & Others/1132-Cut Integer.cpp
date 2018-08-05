/*
1132 Cut Integer（20 分）

Cutting an integer means to cut a K digits lone integer Z into two integers of (K/2) digits long integers A and B. For example, after cutting Z = 167334, we have A = 167 and B = 334. It is interesting to see that Z can be devided by the product of A and B, as 167334 / (167 × 334) = 3. Given an integer Z, you are supposed to test if it is such an integer.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 20). Then N lines follow, each gives an integer Z (10 ≤ Z <2
​31
​​ ). It is guaranteed that the number of digits of Z is an even number.

Output Specification:

For each case, print a single line Yes if it is such a number, or No if not.

Sample Input:

3
167334
2333
12345678
Sample Output:

Yes
No
No
*/

#include<stdio.h>
#include<math.h>

bool isSuchNum(int n){
    int size = 0;
    int m = n;
    while(m){
        m = m / 10;
        size ++;
    }
    size = size/2;
    int r = 1;
    while(size){
        r = r * 10;
        size--;
    }
    int a = n % r;
    //注意末尾为0的情况，下面会除0，导致浮点错误
    if(a == 0) return false;
    int b = n / r;
    if(n % (a*b) == 0){
        return true;
    }
    return false;
}

int main(){
    int n;
    scanf("%d\n",&n);
    for(int i = 0; i < n; i ++){
        int a;
        scanf("%d",&a);
        if(isSuchNum(a)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
