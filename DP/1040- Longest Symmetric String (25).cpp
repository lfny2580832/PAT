/*
1040 Longest Symmetric String (25)（25 分）提问

Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given "Is PAT&TAP symmetric?", the longest symmetric sub-string is "s PAT&TAP s", hence you must output 11.

Input Specification:

Each input file contains one test case which gives a non-empty string of length no more than 1000.

Output Specification:

For each test case, simply print the maximum length in a line.

Sample Input:

Is PAT&TAP symmetric?
Sample Output:

11
*/

/*
难点在定义状态。
我们用二维数组dp[i][j]来代表字符串从i到j是否为回文串，是为1，否为0
当s[i] = s[j]时，dp[i][j]的状态显然与dp[i+1][j-1]直接相关：
若i+1到j-1是回文串，则该子串左右的数也相同时，更大的子串i-j仍为回文；
若i+1到j-1不是回文，则i-j即使相等也不是回文。

故状态转移方程为：
若s[i] = s[j] ,dp[i][j] = dp[i+1][j-1]

边界条件：
d[i][i] = 1;（也可理解为求子串长L=1时的状态）

状态转移过程：
L=2时，判断d[i][j]与d[i][j+1]
L=3时，根据d[i][j]与d[i][j+2]
.....
相当于先算主对角线，再算主对角线右侧的对角线，根据已知条件可以计算出剩下的对角线
例：
PAT&TAP
状态转移矩阵：
1 0 0 0 0 0 1 0 0 0 
  1 0 0 0 1 0 0 0 0 
    1 0 1 0 0 0 0 0 
      1 0 0 0 0 0 0 
        1 0 0 0 0 0 
          1 0 0 0 0 
            1 0 0 0 
              1 0 0 
                1 0 
                  1 
最右上侧的1离主对角线的距离即为结果7
*/


#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int length = (int)s.length();
    int dp[1000][1000];
    int result = 1;
    //设置边界条件,子串长L=1和2时的情况，设置dp主对角线及主对角线右侧一位
    for(int i = 0; i < length; i ++){
        dp[i][i] = 1;
        if(s[i] == s[i+1] && i < length-1){
            dp[i][i+1] = 1;
            result = 2;
        }
    }
    //状态转移
    for(int L = 3; L <= length; L++){
        for(int i = 0; i+L-1 < length; i ++){
            //i~j是长度为L的子串，设置dp主对角线右侧两位及以上
            int j = i + L -1;
            if(s[i] == s[j]){
                //dp[i+1][j-1]位于dp[i][j]斜下方，已知
                dp[i][j] = dp[i+1][j-1];
                //先写状态转移，输出矩阵无误后再加变量result计算长度
                if(dp[i][j] == 1){
					//表示d[i][i+L-1]是回文串，即有长度为L的回文子串
                    result = L;
                }
            }else{
                dp[i][j] = 0;
            }
        }
    }
    printf("%d",result);
    return 0;
}






























