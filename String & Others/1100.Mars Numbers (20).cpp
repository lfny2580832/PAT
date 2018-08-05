/*
1100 Mars Numbers (20)（20 分）

People on Mars count their numbers with base 13:

Zero on Earth is called "tret" on Mars.
The numbers 1 to 12 on Earch is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (< 100). Then N lines follow, each contains a number in [0, 169), given either in the form of an Earth number, or that of Mars.

Output Specification:

For each number, print in a line the corresponding number in the other language.

Sample Input:

4
29
5
elo nov
tam
Sample Output:

hel mar
may
115
13
*/

#include<iostream>
#include<string>
using namespace std;

/*
有一个case通不过
*/

bool isNum(string s){
   if(s[0] - '0' <= 9 && s[0] - '0' >= 0) return true;
   return false;
}

//string化为int
int transToInt(string s){
   int r = 0,d = 1;
   for(int i = (int)s.length() - 1; i >= 0; i --){
       r = r + (s[i] - '0') * d;
       d = d * 10;
   }
   return r;
}

/*
jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
*/
string low[12] = {"jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string high[12] = {"tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

//地球数字化为火星字符串
string earthToMars(int s){
   string r;
   if(!s) r = "tret";
   else if(s > 13){
       int h = s/13 -1;
       int l = s%13 -1;
       if(l < 0) r = high[h];
       else r = high[h] + " " + low[l];
   }
   else r = low[s-1];
   return r;
}

//火星字符串化为地球数字
int marsToEarth(string s){
   int a = 0,b = 0; //a是低位，b是高位
   if(s.length() == 3){
       for(int i = 0; i < 12; i ++){
           if(low[i] == s){
               a = i+1;
               break;
           }else if(high[i] == s) b = i+1;
       }
       return (a)? a : b*13;
   }else{
       for(int i = 0; i < 12; i ++){
           if(high[i] == s.substr(0,3)) b = i+1;
           if(low[i] == s.substr(4,6)) a = i+1;
       }
       return a + b*13;
   }
}

int main(){
   int n;
   cin >> n;
   cin.get();
   for(int i = 0; i < n; i ++){
       string s;
       getline(cin,s);
       if(isNum(s)){
           //若是地球数字
           int r = transToInt(s);
           cout << earthToMars(r) << endl;
       }else{
           //若是火星字符串
           int r = marsToEarth(s);
           cout << r << endl;
       }
   }
   return 0;
}
