/*
1096 Consecutive Factors (20)（20 分）

Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3*5*6*7, where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors.

Input Specification:

Each input file contains one test case, which gives the integer N (1<N<2^31^).

Output Specification:

For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest sequence of the consecutive factors in the format "factor[1]*factor[2]*...*factor[k]", where the factors are listed in increasing order, and 1 is NOT included.

Sample Input:

630
Sample Output:

3
5*6*7
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long int num, temp;
    cin >> num;
    int first = 0, len = 0, maxn = sqrt(num);
    //如当i = 10时
    for (int i = 2; i <= maxn; i++){
        int j;
        //连乘积
        temp = 1;
        //num & (10 * 11 * 12) == 0，10*11*12即为答案
        for (j = i; j <= maxn; j++){
            temp = temp * j;
            if (num % temp != 0) break;
        }
        if (j - i > len){
            len = j - i;
            first = i;
        }
    }
    if (first == 0) cout << 1 << endl << num;
    else {
        cout << len << endl;
        for (int i = 0; i < len; i++){
            cout << first + i;
            if (i != len - 1) cout << '*';
        }
    }
    return 0;
}
