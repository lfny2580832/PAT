/*
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (< 10^5^) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:

The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:

For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:

73 10
23 2
23 10
-2
Sample Output:

Yes
Yes
No
*/


#include<stdio.h>
#include<vector>
using namespace std;

/*
 注意：reversible number with radix D ，其中radix指进制，23以2为进制的倒数是11101 表示29
 此题要求23、29都为素数时输出yes
 */

bool isPrime(int n){
    if(n < 2) return false;    //0和1不是质数
    for(int i = 2; i < n/2; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int reverse(int n,int d){
    //先转换为d进制
    vector<int> vec;
    while(n){
        int i = n % d;
        n = n / d;
        vec.push_back(i);
    }
    int result = 0;
    int r = 1;
    for(int i = (int)vec.size()-1; i >= 0 ; i--){
        result += vec[i] * r;
        r = r * d;
    }
    return result;
}

int main(){
    int n,d;
    while(1){
        scanf("%d",&n);
        if(n < 0) break;
        scanf("%d",&d);
        if(isPrime(n) && isPrime(reverse(n,d))){
            printf("Yes\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
