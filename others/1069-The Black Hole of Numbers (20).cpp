/*
1069 The Black Hole of Numbers (20)（20 分）

For any 4-digit integer except the ones with all the digits being the same, if we sort the digits in non-increasing order first, and then in non-decreasing order, a new number can be obtained by taking the second number from the first one. Repeat in this manner we will soon end up at the number 6174 -- the "black hole" of 4-digit numbers. This number is named Kaprekar Constant.

For example, start from 6767, we'll get:

7766 - 6677 = 1089\ 9810 - 0189 = 9621\ 9621 - 1269 = 8352\ 8532 - 2358 = 6174\ 7641 - 1467 = 6174\ ... ...

Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range (0, 10000).

Output Specification:

If all the 4 digits of N are the same, print in one line the equation "N

N = 0000". Else print each step of calculation in a line until 6174 comes out as the difference. All the numbers must be printed as 4-digit numbers.
Sample Input 1:

6767
Sample Output 1:

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:

2222
Sample Output 2:

2222 - 2222 = 0000
*/

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

//这题莫名其妙有个case通不过

int cmp(int a,int b){
    return a > b;
}

int transVectoInt(vector<int> vec){
    int r = 1;
    int result = 0;
    for(int i = (int)vec.size()-1; i >=0; i --){
        result += vec[i] * r;
        r = r * 10;
    }
    return result;
}

//flag 1 为升序，0为降序
int sortNum(int num,bool flag){
    vector<int> sort_vec;
    while(num){
        int i = num % 10;
        num = num / 10;
        sort_vec.push_back(i);
    }
    for(int i = (int)sort_vec.size(); i < 4; i ++) sort_vec.push_back(0);
    if(flag) sort(sort_vec.begin(), sort_vec.end(), cmp);
    else sort(sort_vec.begin(), sort_vec.end()); //默认降序
    return transVectoInt(sort_vec);
}

int main(){
    int num = 0;    //num属于[1,9999]
    scanf("%d",&num);
    while(num != 6174 && num != 0){
        int inc = sortNum(num, 1);
        int dec = sortNum(num, 0);
        num = inc - dec;
        printf("%04d - %04d = %04d\n",inc,dec,num);
    }
    return 0;
}
