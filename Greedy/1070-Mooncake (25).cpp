/*
1070. Mooncake (25)
Mooncake is a Chinese bakery product traditionally eaten during the Mid-Autumn Festival. Many types of fillings and crusts can be found in traditional mooncakes according to the regions culture. Now given the inventory amounts and the prices of all kinds of the mooncakes, together with the maximum total demand of the market, you are supposed to tell the maximum profit that can be made.
Note: partial inventory storage can be taken. The sample shows the following situation: given three kinds of mooncakes with inventory amounts being 180, 150, and 100 thousand tons, and the prices being 7.5, 7.2, and 4.5 billion yuans. If the market demand can be at most 200 thousand tons, the best we can do is to sell 150 thousand tons of the second kind of mooncake, and 50 thousand tons of the third kind. Hence the total profit is 7.2 + 4.5/2 = 9.45 (billion yuans).

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (<=1000), the number of different kinds of mooncakes, and D (<=500 thousand tons), the maximum total demand of the market. Then the second line gives the positive inventory amounts (in thousand tons), and the third line gives the positive prices (in billion yuans) of N kinds of mooncakes. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the maximum profit (in billion yuans) in one line, accurate up to 2 decimal places.

Sample Input:
3 200
180 150 100
7.5 7.2 4.5
Sample Output:
9.45
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

/*
 在多个整数组成的数字排列，将每个整数当成一个元素，与后面一个交换，看整体是不是变得更小
 冒泡排序，排序规则是a+b < b+a，则a在b前面，可以自己写也可以用cmp
 */

bool cmp(string a,string b){
    return a+b < b+a;
}

int main(){
    int n;
    scanf("%d",&n);
    vector<string> v(n);
    for(int i = 0; i < n; i ++){
        cin >> v[i];
    }
    sort(v.begin(),v.end(),cmp);
    string result;
    for(int i = 0; i < n; i ++){
        result += v[i];
    }
    //防止出现00054这种情况
    while(result[0] == '0'){
        result = result.substr(1,result.length()-1);
    }
    if(result.length() == 0) cout << 0;
    cout << result;
    return 0;
}