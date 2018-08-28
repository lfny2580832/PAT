/*
1057. Stack (30)
Stack is one of the most fundamental data structures, which is based on the principle of Last In First Out (LIFO). The basic operations include Push (inserting an element onto the top position) and Pop (deleting the top element). Now you are supposed to implement a stack with an extra operation: PeekMedian — return the median value of all the elements in the stack. With N elements, the median value is defined to be the (N/2)-th smallest element if N is even, or ((N+1)/2)-th if N is odd.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<= 105). Then N lines follow, each contains a command in one of the following 3 formats:

Push key
Pop
PeekMedian
where key is a positive integer no more than 105.

Output Specification:

For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian command, print in a line the corresponding returned value. If the command is invalid, print “Invalid” instead.

Sample Input:
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
Sample Output:
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid
*/

//关于树状数组 https://www.youtube.com/watch?v=WbafSgetDDk
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;

stack<int> st;
vector<int> BIT;
int n;
int maxn = 100010;

int lowbit(int x){
    return x & (-x);
}

void update(int x,int v){
    for(int i = x; i < maxn; i += lowbit(i))
        BIT[i] += v;
}

int getSum(int x){
    int sum = 0;
    for(int i = x; i >= 1; i -= lowbit(i))
        sum += BIT[i];
    return sum;
}

//k是中位数的位置，树状数组中前m项和为k时，代表位置m前有k个数，输出left（最小的满足条件的值即为所求）
void peekMid(){
    int left = 1, right = maxn, mid, k = ((int)st.size()+1)/2;
    while(left < right){
        mid = (left + right) / 2;
        if(getSum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n",left);
}

int main(){
    int temp;
    scanf("%d",&n);
    BIT.resize(maxn,0);    //树状数组下标必须从1开始
    char str[15];
    for(int i = 0; i < n; i ++){
        scanf("%s",str);
        if(str[1] == 'u'){
            scanf("%d",&temp);
            st.push(temp);
            update(temp,1);     //每次push相当于 BIT[temp] += 1,表该位置前数字的个数+1
        }else if(str[1] == 'o'){
            if (!st.empty()) {
                update(st.top(), -1);
                printf("%d\n",st.top());
                st.pop();
            }else printf("Invalid\n");
        }else{
            if(!st.empty())
                peekMid();
            else
                printf("Invalid\n");
        }
    }
    return 0;
}
