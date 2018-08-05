/*
1002 A+B for Polynomials (25)（25 分）提问

This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 a~N1~ N2 a~N2~ ... NK a~NK~, where K is the number of nonzero terms in the polynomial, Ni and a~Ni~ (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output

3 2 1.5 1 2.9 0 3.2*/

/*
2 1 2.4 0 3.2
2个非零项，2.4x^1 + 3.2x^0
*/

/*
注意此题测试用例：
测试用例:
3 999 5 100 -5 0 -0.5
4 100 5 10 -1 3 5.7 0 10
对应输出应该为:
4 999 5.0 10 -1.0 3 5.7 0 9.5
要去掉为0的项目
*/

#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    /*
     一开始是这么定义的，<k,{N1,N2....}> 项次幂，系数
     后来发现直接用<e,c>即可，相同次幂下的系数直接相加后设为value即可
     */
    map<int, double ,greater<int> > ecmap;
    int num;
    int e;    //项次幂exponent
    double c;     //系数coeffcient
    int empty = 0;  //空子项个数
    for(int i = 0;i < 2;i++){
        scanf("%d",&num);
        for(int j = 0; j < num; j++){
            scanf("%d",&e);
            scanf("%lf",&c);
            if(ecmap.find(e) == ecmap.end()){
                ecmap[e] = c;
            }else{
                ecmap[e] = ecmap[e] + c;
            }
        }
    }
    map<int, double > ::iterator it;
    for(it = ecmap.begin(); it != ecmap.end(); it++){
        if(it->second == 0) empty++;
    }
    printf("%d", (int)ecmap.size()-empty);
    for(it = ecmap.begin(); it != ecmap.end(); it++){
        if(it->second != 0) printf(" %d %.1lf",it->first,it->second);
    }
    return 0;
}


















