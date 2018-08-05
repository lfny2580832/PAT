/*
1112 Stucked Keyboard（20 分）

On a broken keyboard, some of the keys are always stucked. So when you type some sentences, the characters corresponding to those keys will appear repeatedly on screen for k times.

Now given a resulting string on screen, you are supposed to list all the possible stucked keys, and the original string.

Notice that there might be some characters that are typed repeatedly. The stucked key will always repeat output for a fixed k times whenever it is pressed. For example, when k=3, from the string thiiis iiisss a teeeeeest we know that the keys i and e might be stucked, but s is not even though it appears repeatedly sometimes. The original string could be this isss a teest.

Input Specification:

Each input file contains one test case. For each case, the 1st line gives a positive integer k (1<k≤100) which is the output repeating times of a stucked key. The 2nd line contains the resulting string on screen, which consists of no more than 1000 characters from {a-z}, {0-9} and _. It is guaranteed that the string is non-empty.

Output Specification:

For each test case, print in one line the possible stucked keys, in the order of being detected. Make sure that each key is printed once only. Then in the next line print the original string. It is guaranteed that there is at least one stucked key.

Sample Input:

3
caseee1__thiiis_iiisss_a_teeeeeest
Sample Output:

ei
case1__this_isss_a_teest
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

/*
 此题要注意，若重复次数为3，
 1.字符串中出现abbbba时，b不是坏键，因为坏键出现次数必定为3的倍数
 2.只出现一次aaa时，也要输出，因为无法证明它不是坏键（此处卡过case）
 3.注意跳步用的是输入的t，不是某个确定的值
 */

int main(){
    int t;
    cin >> t;
    cin.get();
    string s;
    getline(cin,s);
    map<char,int> stucked_map;
    int cnt = 1;
    s.push_back('\n');
    for(int i = 1; i < s.length(); i ++){
        if(s[i] == s[i-1]){
            cnt ++;
            continue;
        }
        if(cnt % t == 0){
            if(stucked_map[s[i-1]] != -1){
                stucked_map[s[i-1]] += cnt /t;
            }
        }else{
            stucked_map[s[i-1]] = -1;
        }
        cnt = 1;
    }
    //output the first line
    map<char,int> tmp_map = stucked_map;
    for(int i = 0; i < s.length(); i ++){
        if(tmp_map[s[i]] > 0){
            cout << s[i];
            tmp_map[s[i]] = 0;
        }
    }
    cout << endl;
    //output the second line
    for(int i = 0; i < s.length()-1; i ++){
        if(stucked_map[s[i]] > 0){
            i = i + t-1;
        }
        cout << s[i];
    }
    return 0;
}

