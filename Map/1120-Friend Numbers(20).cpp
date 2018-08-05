/*
1120 Friend Numbers（20 分）

Two integers are called "friend numbers" if they share the same sum of their digits, and the sum is their "friend ID". For example, 123 and 51 are friend numbers since 1+2+3 = 5+1 = 6, and 6 is their friend ID. Given some numbers, you are supposed to count the number of different frind ID's among them.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N. Then N positive integers are given in the next line, separated by spaces. All the numbers are less than 10
​4
​​ .

Output Specification:

For each case, print in the first line the number of different frind ID's among the given integers. Then in the second line, output the friend ID's in increasing order. The numbers must be separated by exactly one space and there must be no extra space at the end of the line.

Sample Input:

8
123 899 51 998 27 33 36 12
Sample Output:

4
3 6 9 26
*/

#include<stdio.h>
#include<map>
using namespace std;

int digitSum(int n){
    int r = 0;
    while(n){
        r += n % 10;
        n /= 10;
    }
    return r;
}

int main(){
    int n;
    scanf("%d\n",&n);
    map<int,int> num_map;
    for(int i = 0; i < n; i ++){
        int a;
        scanf("%d",&a);
        int ds = digitSum(a);
        num_map[ds]++;
    }
    printf("%d\n",(int)num_map.size());
    map<int,int>::iterator it;
    int i = 0;
    for(it = num_map.begin(); it != num_map.end(); it++){
        printf("%d",it->first);
        i++;
        if(i != num_map.size()) printf(" ");
    }
    return 0;
}
