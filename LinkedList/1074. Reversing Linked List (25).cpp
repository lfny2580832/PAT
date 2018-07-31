/*
1074. Reversing Linked List (25)
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 105) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.
Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/

#include<stdio.h>
#include<vector>
using namespace std;

struct ListNode{
    int add;
    int data;
    int next;
};

ListNode node[100000];
vector<ListNode> node_vec;

int main(){
    int n,k,head;
    scanf("%d %d %d",&head,&n,&k);
    int add,data,next;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d",&add,&data,&next);
        node[add] = {add,data,next};
    }
    while(head != -1){
        node_vec.push_back(node[head]);
        head = node[head].next;
    }
    int size = (int)node_vec.size();
    int times = size / k;
    int remain = size % k;  //剩下无需逆置的个数
    //下面代码写的很恶心，不过懒得改了，恶心但是看着思路比较清晰，就当练习if了
    //先把能前面能逆置的部分逆置
    for(int i = 1; i <= times; i++){
        for(int j = i * k - 1; j >= (i-1) * k ; j--){
            if(j == (i-1)*k){
                if(remain){
                    if(i == times)
                        printf("%05d %d %05d\n",node_vec[j].add,node_vec[j].data,node_vec[size-remain].add);
                    else
                        printf("%05d %d %05d\n",node_vec[j].add,node_vec[j].data,node_vec[j+2*k-1].add);
                }else{
                    if(i == times)
                        //此处测试用例出过问题
                        printf("%05d %d -1\n",node_vec[j].add,node_vec[j].data);
                    else
                        printf("%05d %d %05d\n",node_vec[j].add,node_vec[j].data,node_vec[j+2*k-1].add);
                }
            }else
                printf("%05d %d %05d\n",node_vec[j].add,node_vec[j].data,node_vec[j-1].add);
        }
    }
    //最后输出剩下的，此处测试用例出过问题
    int last = remain;
    while(last-1 > 0){
        printf("%05d %d %05d\n",node_vec[size-last].add,node_vec[size-last].data,node_vec[size-last].next);
        last --;
    }
    //若不用last代替，没法输出最后一个-1
    if(remain) printf("%05d %d -1\n",node_vec[size-1].add,node_vec[size-1].data);
    return 0;
}





