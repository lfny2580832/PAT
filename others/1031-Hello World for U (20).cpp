/*
1031 Hello World for U (20)（20 分）

Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example, "helloworld" can be printed as:

h  d
e  l
l  r
lowo
That is, the characters must be printed in the original order, starting top-down from the left vertical line with n~1~ characters, then left to right along the bottom line with n~2~ characters, and finally bottom-up along the vertical line with n~3~ characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n~1~ = n~3~ = max { k| k <= n~2~ for all 3 <= n~2~ <= N } with n~1~

n~2~ + n~3~ - 2 = N.
Input Specification:

Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

Output Specification:

For each test case, print the input string in the shape of U as specified in the description.

Sample Input:

helloworld!
Sample Output:

h   !
e   d
l   l
lowor
*/


#include<iostream>
#include<string>
using namespace std;

/*
题目要求尽可能squared，说明n1、n2、n3应当尽可能接近，所以除3后再操作
n1 + n2 + n3 = N + 2;
n1 = n3 <= n2 
*/

int main(){
    string s;
    getline(cin,s);
    int n = (int)s.length();
    int base = (n + 2) / 3;
    int rest = (n + 2) % 3;
    int n2 = base + rest;    //n2最大，分成三部分后剩下的加到n2上
    int n1 = base;
    for(int i = 0; i < n1-1; i ++){
        printf("%c", s[i]);
        for(int j = 0; j < n2-2; j++){
            printf(" ");
        }
        printf("%c\n", s[n-1-i]);
    }
    for(int i = n1-1; i < n1-1+n2; i ++){
        printf("%c", s[i]);
    }
    return 0;
}
































