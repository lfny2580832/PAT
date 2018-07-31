/*
1005 Spell It Right (20)（20 分）提问

Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10^100^).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:

12345
Sample Output:

one five
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    string n;
    getline(cin, n);
    int length = (int)n.length();
    int sum = 0,i;
    for(int i = 0; i < length; i++){
        sum += n[i] - '0';
    }
    if(!sum) printf("zero");
    vector<int> vec;
    while(sum){
        i = sum % 10;
        sum = sum / 10;
        vec.push_back(i);
    }
    for(i = (int)vec.size()-1; i >= 0; i --){
        if(vec[i] == 0) printf("zero");
        else if(vec[i] == 1) printf("one");
        else if(vec[i] == 2) printf("two");
        else if(vec[i] == 3) printf("three");
        else if(vec[i] == 4) printf("four");
        else if(vec[i] == 5) printf("five");
        else if(vec[i] == 6) printf("six");
        else if(vec[i] == 7) printf("seven");
        else if(vec[i] == 8) printf("eight");
        else printf("nine");
        if(i != 0) printf(" ");
    }
    return 0;
}









