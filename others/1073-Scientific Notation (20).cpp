/*
1073 Scientific Notation (20)（20 分）

Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9]"."[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.

Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.

Input Specification:

Each input file contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.

Output Specification:

For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros,

Sample Input 1:

+1.23400E-03
Sample Output 1:

0.00123400
Sample Input 2:

-1.2E+10
Sample Output 2:

-12000000000
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
Sample Input 1:
+1.23400E-03
Sample Output 1:
0.00123400
Sample Input 2:
-1.2E+10
Sample Output 2:
-12000000000
*/

int findEx(string s){
    string r;
    bool flag = false;
    for (int i = 0; i < s.length(); i++) {
        if(flag){
            r = r + s[i];
        }
        if(s[i] == 'E') flag = true;
    }
    int ex = 0;   //小数点往前/往后移动ex位
    int d = 1;
    for(int i = (int)r.length()-1; i >= 1; i--){
        ex += (r[i]-'0') * d;
        d = d * 10;
    }
    if(r[0] == '-'){
        ex = - ex;
    }
    return ex;
}

//1.23400
string findBase(string s){
    string r;
    for(int i = 1; i < s.length(); i ++){
        if(s[i] == 'E') break;
        r = r + s[i];
    }
    return r;
}
//在base的基础上，左移或右移ex位
string constructString(string base, int ex){
    vector<char> char_vec;
    for(int i = 0; i < base.length(); i ++){
        char_vec.push_back(base[i]);
    }
    int base_len = (int)base.length();
    if(ex > 0){
        //小数点右移
        if(base_len - 2 > ex){
            //小数点直接右移即可
            for(int i = 2; i < 2 + ex; i ++){
                char_vec[i-1] = char_vec[i];
            }
            char_vec[1+ex] = '.';
        }else{
            //无需小数点，数字左移，然后添加多余的0
            for(int i = 2; i < base_len; i++){
                char_vec[i-1] = char_vec[i];
            }
            //为避免输出最后的. 直接pop掉，减少vec长度
            if(base_len-2 == ex) char_vec.pop_back();
            else{
                char_vec[base_len-1] = '0';
                for(int i = 0; i < ex-(base_len-2)-1; i ++){
                    char_vec.push_back('0');
                }
            }
        }
    }else{
        //小数点左移，左边加ex个0，小数点左移ex位
        for(int i = 0; i < -ex; i ++){
            char_vec.insert(char_vec.begin(),'0');
        }
        for(int i = -ex; i >= 1; i --){
            char_vec[i+1] = char_vec[i];
        }
        char_vec[1] = '.';
    }
    string result;
    for(int i = 0; i < char_vec.size(); i ++){
        result += char_vec[i];
    }
    return result;
}

int main(){
    string s;
    cin >> s;
    if(s[0] == '-') cout << "-";
    string base = findBase(s);
    int ex = findEx(s); //正数为小数点往右移ex位，负数为左移ex位
    string result = constructString(base,ex);
    cout << result;
    return 0;
}
