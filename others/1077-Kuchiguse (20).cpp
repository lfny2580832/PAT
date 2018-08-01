/*
The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:

Itai nyan~ (It hurts, nyan~)

Ninjin wa iyada nyan~ (I hate carrots, nyan~)

Now given a few lines spoken by the same character, can you find her Kuchiguse?

Input Specification:

Each input file contains one test case. For each case, the first line is an integer N (2<=N<=100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.

Output Specification:

For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write "nai".

Sample Input 1:

3
Itai nyan~
Ninjin wa iyadanyan~
uhhh nyan~
Sample Output 1:

nyan~
Sample Input 2:

3
Itai!
Ninjinnwaiyada T_T
T_T
Sample Output 2:

nai
*/
#include<iostream>
#include<string>
using namespace std;

string findSuffix(string s1, string s2){
    string suffix;
    if(s1.length() > s2.length()){
        s2.insert(0,s1.length()-s2.length(),'#');
    }else if(s2.length() > s1.length())
        s1.insert(0,s2.length()-s1.length(),'#');
    for(int i = (int)s1.length()-1; i >= 0; i --){
        if(s1[i] == s2[i])
            suffix.insert(suffix.begin(),s1[i]);
        else{
            break;
        }
    }
    return suffix;
}

int main(){
    int n;
    //若用scanf("%d\n",&n),注意此处回车符号，若没有则会用于下面的字符串输入，下面cin.get()同理，为吸收回车
    cin >> n;
    cin.get();
    string suffix;
    bool tag = false;
    for(int i = 0; i < n; i ++){
        string s;
        //别忘了cin输入字符串，遇到空格即停止
        getline(cin, s);
        if(tag){
            suffix = findSuffix(suffix, s);
        }else{
            suffix = s;
            tag = true;
        }
    }
    if(!suffix.length()) printf("nai");
    cout << suffix;
    return 0;
}

