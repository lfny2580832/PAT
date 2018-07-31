/*
1008 Elevator (20)（20 分）提问

The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

Output Specification:

For each test case, print the total time on a single line.

Sample Input:

3 2 3 1
Sample Output:

41
*/

#include<stdio.h>
#include<vector>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int tmp;
    vector<int> vec;
    vec.push_back(0);
    for(int i = 0; i < n; i++){
        scanf("%d",&tmp);
        vec.push_back(tmp);
    }
    int up = 0,down = 0;
    for(int i = 1; i < vec.size(); i++){
        tmp = vec[i] - vec[i-1];
        if(tmp > 0) up += tmp;
        else down += -tmp;
    }
    int result = up * 6 + down * 4 + ((int)vec.size()-1) * 5;
    printf("%d",result);
    return 0;
}





















