/*
1035 Password (20)（20 分）

To prepare for PAT, the judge sometimes has to generate random passwords for the users. The problem is that there are always some confusing passwords since it is hard to distinguish 1 (one) from l (L in lowercase), or 0 (zero) from O (o in uppercase). One solution is to replace 1 (one) by @, 0 (zero) by %, l by L, and O by o. Now it is your job to write a program to check the accounts generated by the judge, and to help the juge modify the confusing passwords.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N (<= 1000), followed by N lines of accounts. Each account consists of a user name and a password, both are strings of no more than 10 characters with no space.

Output Specification:

For each test case, first print the number M of accounts that have been modified, then print in the following M lines the modified accounts info, that is, the user names and the corresponding modified passwords. The accounts must be printed in the same order as they are read in. If no account is modified, print in one line "There are N accounts and no account is modified" where N is the total number of accounts. However, if N is one, you must print "There is 1 account and no account is modified" instead.

Sample Input 1:

3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa
Sample Output 1:

2
Team000002 RLsp%dfa
Team000001 R@spodfa
Sample Input 2:

1
team110 abcdefg332
Sample Output 2:

There is 1 account and no account is modified
Sample Input 3:

2
team110 abcdefg222
team220 abcdefg333
Sample Output 3:

There are 2 accounts and no account is modified
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct userInfo{
    string account;
    string password;
    bool isModified;
};

bool needModify(string s){
    for(int i = 0; i < s.length(); i ++){
        if(s[i] == '1' || s[i] == '0' || s[i] == 'l' || s[i] == 'O'){
            return true;
        }
    }
    return false;
}

string modify(string s){
    string ns = s;
    for(int i = 0; i < s.length(); i ++){
        if (s[i] == '1') ns[i] = '@';
        else if(s[i] == '0') ns[i] = '%';
        else if(s[i] == 'l') ns[i] = 'L';
        else if(s[i] == 'O') ns[i] = 'o';
        else ns[i] = s[i];
    }
    return ns;
}

int main(){
    int n;
    scanf("%d",&n);
    vector<userInfo> user_vec;
    int modify_num = 0; //需要修改的数量
    for(int i = 0; i < n; i ++){
        string acc;
        cin >> acc;
        string paw;
        cin >> paw;
        userInfo u;
        if(needModify(paw)) {
            string new_paw = modify(paw);
            u = {acc,new_paw,true};
            modify_num ++;
        }else{ 
            u = {acc,paw,false};
        }
        user_vec.push_back(u);
    }
    if(!modify_num){
        if(user_vec.size() == 1) printf("There is 1 account and no account is modified");
        else printf("There are %d accounts and no account is modified",(int)user_vec.size());
        return 0;
    }
    printf("%d\n",(int)modify_num);
    for(int i = 0; i < user_vec.size(); i ++){
        userInfo u = user_vec[i];
        if(u.isModified){
            cout << u.account + ' ' << u.password << endl;
        }
    }
    return 0;
}
