/*
1058 A+B in Hogwarts (20)（20 分）

If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 10^7^], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).

Input Specification:

Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the input.

Sample Input:

3.2.1 10.16.27
Sample Output:

14.1.28
*/

#include<iostream>
#include<string>
using namespace std;

struct money{
    int Galleon,Sickle,Knut;
};

//注意若int数组不设置初始值，在某些编译器会计算出错！

money reverseStrtoMoney(string s){
    int m[3] = {0};
    int j = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
            int num = s[i] - '0';
            m[j] = m[j]*10 + num;
        }else{
            j = j+1;
        }
    }
    money r = {m[0],m[1],m[2]};
    return r;
}

money addMoney(money a, money b){
    money r;
    int flag;   //进位标识符
    int knut = a.Knut + b.Knut;
    if(knut > 28) {
        knut = knut - 29;
        flag = 1;
    }else flag = 0;
    r.Knut = knut;

    int Sickle = a.Sickle + b.Sickle;
    if(flag) Sickle += 1;
    if(Sickle > 16){
        Sickle = Sickle - 17;
        flag = 1;
    }else flag = 0;
    r.Sickle = Sickle;

    int Galleon = a.Galleon + b.Galleon;
    if(flag) Galleon += 1;
    r.Galleon = Galleon;
    return r;
}

int main(){
    string str1,str2;
    //cin遇到空格即输入完成，getline遇到回车才完成
    cin >> str1 >> str2;
    money a = reverseStrtoMoney(str1);
    money b = reverseStrtoMoney(str2);
    money c = addMoney(a, b);
    printf("%d.%d.%d",c.Galleon,c.Sickle,c.Knut);
    return 0;
}
