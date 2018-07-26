﻿/*1007. Maximum Subsequence Sum (25)
Given a sequence of K integers { N1, N2, …, NK }.A continuous subsequence is defined to be { Ni, Ni+1, …, Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/

/*
解析：
状态dp[i] 表示以i为结尾的最大子序列的长度
状态转移方程：dp[i] = max(dp[i-1]+nums[i],nums[i])
dp[] = {-10,1,3,6,10,5,-17,3,10,-11}
若dp[i]为前者，begin不变
若dp[i]为后者，begin设为nums[i]
在设置状态的循环中进行大小的比较，若遇到和更大的子序列，更新end为nums[i]
*/
#include<stdio.h>
#include<vector>

using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	vector<int> nums(n);
	int begin = 0, end = n-1;
	int dp = nums[0];
	int max_index = -1;
	int sum = 0;
	for(int i = 0; i < n; i ++){
		scanf("%d",&nums[i]);
		dp = dp + nums[i];
		if(dp < 0){
			dp = 0;
			max_index = i + 1;
		}else if(dp > sum){
			sum = dp;
			begin = max_index;
			end = i;
		}
	}
	if(sum < 0) sum = 0;
	printf("%d %d %d", sum,nums[begin],nums[end]);
	return 0;
}





















