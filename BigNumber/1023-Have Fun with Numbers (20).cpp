/*
1023. Have Fun with Numbers (20)
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:

Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:

For each test case, first print in a line “Yes” if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or “No” if not. Then in the next line, print the doubled number.

Sample Input:
1234567899
Sample Output:
Yes
2469135798
*/


#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isPermutation(vector<int> vec, int map[]){
    int map2[10] = {0};
    for(int i = 0; i < vec.size(); i ++){
        int num = vec[i];
        map2[num] ++;
    }
    for(int i = 0; i < 10; i++){
        if(map[i] != map2[i]) return false;
    }
    return true;
}

int main(){
    string s;
    getline(cin, s);
    vector<int> nums_vec;
    int word_map[10] = {0};
    for(int i = 0; i < s.length(); i++){
        int num = s[i] - '0';
        nums_vec.push_back(num);
        word_map[num] ++;
    }
    //进行乘2处理
    int flag = 0;   //进位标志，因为是乘2只有1和0两个值
    for(int i = (int)nums_vec.size()-1; i >= 0; i--){
        int num;    //每位的结果
        int tmp = nums_vec[i] * 2;
        if(tmp >= 10){
            if(flag){
                num = tmp-10+1;
            }else{
                num = tmp-10;
            }
            flag = 1;
        }else{
            if(flag){
                num = tmp+1;    //因为*2只可能编程8或0，所以+1后不用再判断大于10
            }else{
                num = tmp;
            }
            flag = 0;
        }
        nums_vec[i] = num;
    }
    if(isPermutation(nums_vec, word_map)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    if (flag) {
        printf("1");
    }
    for(int i = 0; i < nums_vec.size(); i ++){
        printf("%d",nums_vec[i]);
    }
    return 0;
}







































