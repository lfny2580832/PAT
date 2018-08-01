/*
1081 Rational Sum (20)（20 分）

Given N rational numbers in the form "numerator/denominator", you are supposed to calculate their sum.

Input Specification:

Each input file contains one test case. Each case starts with a positive integer N (<=100), followed in the next line N rational numbers "a1/b1 a2/b2 ..." where all the numerators and denominators are in the range of "long int". If there is a negative number, then the sign must appear in front of the numerator.

Output Specification:

For each test case, output the sum in the simplest form "integer numerator/denominator" where "integer" is the integer part of the sum, "numerator" < "denominator", and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.

Sample Input 1:

5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:

3 1/3
Sample Input 2:

2
4/3 2/3
Sample Output 2:

2
Sample Input 3:

3
1/3 -1/6 1/8
Sample Output 3:

7/24
*/

/*
rational Number 有理数  numerator/denominator 分子/分母
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
 无需先存到vector里再进行计算，直接输入时就跟总和相加即可
 */

//辗转相除法求最大公约数
long gcd(long a,long b){
    while(b){
        long r = b;
        b = a % b;
        a = r;
    }
    return a;
}

//两个分数相加
pair<long, long> sumRnum(long a1,long b1,long a2,long b2){
    long ra,rb;
    if(a1 == 0){
        ra = a2;
        rb = b2;
        return make_pair(ra, rb);
    }
    long gmax = gcd(b1, b2);
    ra = (a1 * b2 + a2 * b1)/gmax;
    rb = (b1 * b2)/gmax;
    long gmax2 = gcd(ra, rb);
    if(gmax2 != 1){
        ra = ra/gmax2;
        rb = rb/gmax2;
    }
    return make_pair(ra, rb);
}

int main(){
    int n;
    cin >> n;
    cin.get();
    long suma = 0,sumb = 0;
    for(int i = 0; i < n; i ++){
        long a1,b1;
        char tmp;
        cin >> a1 >> tmp >> b1;
        pair<long, long> p = sumRnum(suma, sumb, a1, b1);
        suma = p.first;
        sumb = p.second;
    }
    //输出范式
    if(suma == 0){
        printf("0");
        return 0;
    }
    if(suma < 0){
        printf("-");
        suma = -suma;
    }
    if(suma < sumb) {
        printf("%ld/%ld",suma,sumb);
    }else if (suma % sumb == 0) printf("%ld",suma/sumb);
    else{
        printf("%ld %ld/%ld",suma/sumb,suma%sumb,sumb);
    }
    return 0;
}
