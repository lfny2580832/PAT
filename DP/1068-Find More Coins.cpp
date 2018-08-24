/*
1068. Find More Coins (30)
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she must pay the exact amount. Since she has as many as 104 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find some coins to pay for it.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=104, the total number of coins) and M(<=102, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the face values V1 <= V2 <= … <= Vk such that V1 + V2 + … + Vk = M. All the numbers must be separated by a space, and there must be no extra space at the end of the line. If such a solution is not unique, output the smallest sequence. If there is no solution, output “No Solution” instead.

Note: sequence {A[1], A[2], …} is said to be “smaller” than sequence {B[1], B[2], …} if there exists k >= 1 such that A[i]=B[i] for all i < k, and A[k] < B[k].

Sample Input 1:
8 9
5 9 8 7 2 3 4 1
Sample Output 1:
1 3 5
Sample Input 2:
4 8
7 2 4 3
Sample Output 2:
No Solution
*/
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

/*
 本质问题是01背包问题，此题将每个硬币的重量=价值好做
 */

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    int V[N];
    int dp[N][M+1];
    for(int i = 0; i < N; i++){
        scanf("%d", &V[i]);
    }
    sort(V, V + N, greater<int>());
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            if(V[i] > j){
                if(i > 0){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = 0;
                }
            }else{
                if(i > 0){
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-V[i]] + V[i]);
                }else{
                    dp[i][j] = V[i];
                }
            }
        }
    }
    if(dp[N - 1][M] == M){
        while(M){
            int i = N - 1;
            while(M - V[i] != (i > 0? dp[i - 1][M - V[i]]: 0)) i--;
            printf("%d", V[i]);
            M -= V[i];
            N = i;
            if(M != 0) printf(" ");
        }
    } else printf("No Solution");
    return 0;
}
