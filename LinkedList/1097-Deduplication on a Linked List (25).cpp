/*
1097. Deduplication on a Linked List (25)
Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys. That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept. At the mean time, all the removed nodes must be kept in a separate list. For example, given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the removed list -15→15.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, and a positive N (<= 105) which is the total number of nodes. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the position of the node, Key is an integer of which absolute value is no more than 104, and Next is the position of the next node.

Output Specification:

For each case, output the resulting linked list first, then the removed list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
Sample Output:
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
*/

#include<stdio.h>
#include<vector>
#include<map>
#include<cstdlib>

using namespace std;

int next_arr[100000];    //存放地址为下标的节点的下一个地址
int data_arr[100000];    //存放地址为下标的节点数据
bool exist_arr[100005] = {false};  //存放数据为下标的节点是否已经存在

int main(){
    int head,n;
    scanf("%d %d",&head,&n);
    int add,data,next;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d",&add,&data,&next);
        data_arr[add] = data;
        next_arr[add] = next;
    }
    int L1 = -1, L2 = -1, E1 = -1, E2 = -1; //L为头结点，E为尾节点，用来进行尾插法，L1存储前半部分数组，L2存储后半部分重复数组
    while(head != -1){
        if(exist_arr[abs(data_arr[head])]){ //遍历过程中发现该数据绝对值已存在
            //添加到L2
            if(L2 == -1){
                L2 = E2 = head;
            }else{
                next_arr[E2] = head;    //表示E2->next = head;
                E2 = head;
            }
        }else{
            exist_arr[abs(data_arr[head])] = true;
            //添加到L1
            if(L1 == -1){    //如果是第一个节点
                L1 = E1 = head;
            }else{
                next_arr[E1] = head;
                E1 = head;
            }
        }
        head = next_arr[head];
    }
    if(E1 != -1){   //如果链表不为空
        next_arr[E1] = -1;
        for(head = L1; head != -1; head = next_arr[head]){
            printf("%05d %d ",head, data_arr[head]);
            if(next_arr[head] != -1){
                printf("%05d\n",next_arr[head]);
            }else{
                printf("-1\n");
            }
        }
    }
    if(E2 != -1){
        next_arr[E2] = -1;
        for(head = L2; head != -1; head = next_arr[head]){
            printf("%05d %d ",head, data_arr[head]);
            if(next_arr[head] != -1){
                printf("%05d\n",next_arr[head]);
            }else{
                printf("-1\n");
            }
        }
    }
    return 0;
}
