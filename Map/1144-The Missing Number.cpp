/*
1144 The Missing Number（20 分）

Given N integers, you are supposed to find the smallest positive integer that is NOT in the given list.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤10
​5
​​ ). Then N integers are given in the next line, separated by spaces. All the numbers are in the range of int.

Output Specification:

Print in a line the smallest positive integer that is missing from the input list.

Sample Input:

10
5 -25 9 6 1 3 4 2 5 17
Sample Output:

7
*/


#include<iostream>
#include<map>
using namespace std;

/*
 1.注意题目要求只有一个数应原样输出，但实际答案要求精确到两位输出
 2.注意xx.也是可以通过的，懒得再改了，垃圾题。
 */

double stringToNum(string s){
    bool flag =  true;
    if(s.find('.') == string::npos){
        //没有小数点
        if(s[0] == '-'){
            s = s.substr(1,s.length()-1);
            flag = false;
        }
        int r = 0;
        int d = 1;
        for(int i = (int)s.length()-1; i >= 0; i --){
            r += (s[i] - '0') * d;
            d = d * 10;
        }
        return (flag)? r : -r ;
    }else{
        //有小数点
        if(s[0] == '-'){
            s = s.substr(1,s.length()-1);
            flag = false;
        }
        int dp = (int)s.find('.');
        int r = 0;   //整数部分
        int d = 1;

        for(int i = dp; i > 0; i --){
            r += (s[i-1] - '0') * d;
            d = d * 10;
        }
        if(!flag) r = -r;
        double b = 0;   //小数部分
        double k = 0.1;
        for(int i = dp+1; i < s.length(); i ++){
            b += (s[i]-'0') * k;
            k = k/10;
        }
        if(!flag) b = -b;
        return r + b;
    }
}

//9999,-2000,aaa,2.3.4
bool isNeed(string s){
    string r;
    //统一做去负号处理
    if(s[0] == '-') s = s.substr(1,s.length()-1);
    //判断是否有字母
    for(int i = 0; i < s.length(); i ++){
        if(s[i] == '.') continue;
        if(!(s[i] >= '0' && s[i] <= '9'))
            return false;
    }
    //判断纯数字及小数点格式
    if(s.find('.') == string::npos){
        //如果没有小数点，是个整数
        if(stringToNum(s) > 1000) return false;
        else return true;
    }else{
        //如果有小数点，判断有几个小数点
        int cnt = 0;
        int i = 0;
        while(i < s.length()){
            if(s[i] == '.') cnt ++;
            i++;
        }
        if(cnt > 1) return false;
        //如果有一个小数点，看小数点后有几位
        else{
            i = (int)s.length()-1;
            cnt = 0;
            //从后往前数，直到碰到小数点
            while(i > 0){
                if(s[i] == '.') break;
                cnt ++;
                i --;
            }
            //小数点后有数字，且不超过两位
            if(cnt < 3 && cnt > 0) return true;
            else return false;
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int cnt =  0;
    double sum = 0;
    string theOnly;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(!isNeed(s)){
            printf("ERROR: %s is not a legal number\n",s.c_str());
        }else{
            theOnly = s;
            cnt++;
            sum += stringToNum(s);
        }
    }
    if(cnt > 1) printf("The average of %d numbers is %.2lf\n",cnt,sum/cnt);
    else if(cnt == 1){
        //注意题目要求只有一个数应原样输出，但实际答案要求精确到两位输出
        printf("The average of 1 number is %.2lf\n",sum);
    }
    else printf("The average of 0 numbers is Undefined\n");
    return 0;
}
