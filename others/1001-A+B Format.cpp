/*1001 A+B Format (20)（20 分）

Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input

-1000000 9
Sample Output

-999,991
*/

/*
注意，是类似金钱表示法，不是从头开始3个一个逗号
*/
#include<stdio.h>
#include<vector>
#include<cstdlib>

using namespace std;

int main(){
	int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    int sum = m + n;
    if(sum == 0){
        printf("0");
        return 0;
    }else if(sum < 0){
        printf("-");
        sum = -sum;
    }
    vector<int> nums;
    while(sum != 0){
        int i = sum % 10;
        sum = sum / 10;
        nums.push_back(i);
        i++;
    }
    /*
     已知序列 12345  输出12，345，可通过size() % 3得到2，2个数打印完输出逗号，余下的3个一逗号
     */
    int pre_length = nums.size() % 3;
    for(int i = nums.size()-1 ; i >= 0; i --){
        int j = nums.size()-1-i;
        printf("%d", nums[i]);
        //此题就是考边界条件，注意严谨，一位数，两位数到七位数都要测试
        if(pre_length == 0){
            if(((j+1)%3) == 0 && i != 0) printf(",");
        }else{
            if(j == pre_length-1 && (j+1) != nums.size()) printf(",");
            if((j - pre_length +1) % 3 == 0 && j >= 3 && i != 0) printf(",");
        }
    }
    return 0;
}












