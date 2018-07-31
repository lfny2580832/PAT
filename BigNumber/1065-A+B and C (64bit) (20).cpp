/*
1065 A+B and C (64bit) (20)（20 分）

Given three integers A, B and C in [-2^63^, 2^63^], you are supposed to tell whether A+B > C.

Input Specification:

The first line of the input gives the positive number of test cases, T (<=10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.

Output Specification:

For each test case, output in one line "Case #X: true" if A+B&gtC, or "Case #X: false" otherwise, where X is the case number (starting from 1).

Sample Input:

3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
Sample Output:

Case #1: false
Case #2: true
Case #3: false
*/

#include<iostream>
using namespace std;
/*
 主要考察long long 类型及溢出的判断
 无符号整数相加：如果结果小于其中任何一个，则溢出；
 有符号整数相加：
 如果两个正数相加<0，或者两个负数相加>0，（负数在计算机中用补码表示）则溢出。
 */

int main(){
    int n;
    scanf("%d",&n);
    long long a;
    long long b;
    long long c;
    for(int i = 0; i < n; i ++){
        bool flag = true;
        scanf("%lld %lld %lld",&a,&b,&c);
        long long sum = a + b;
        //判断两种溢出情况
        if(a>0 && b>0 && sum<=0) flag = true;    //太大溢出，肯定A+B>C
        else if(a<0 && b<0 && sum>0) flag = false;    //太小溢出，肯定A+B<C
        if(sum > c) flag = true;
        else flag = false;
        //Case #1: false
        if(flag) printf("Case #%d: true\n", i);
        else printf("Case #%d: false\n", i);
    }
    return 0;
}




















