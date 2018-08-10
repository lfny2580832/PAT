/*
Input Specification:

Each input file contains several test cases. The first line gives an integer K (1<K≤200). Then K lines follow, each gives a configuration in the format "N Q
​1
​​  Q
​2
​​  ... Q
​N
​​ ", where 4≤N≤1000 and it is guaranteed that 1≤Q
​i
​​ ≤N for all i=1,⋯,N. The numbers are separated by spaces.

Output Specification:

For each configuration, if it is a solution to the N queens problem, print YES in a line; or NO if not.

Sample Input:
*/

#include<stdio.h>
#include<map>
using namespace std;

/*
 原想法：
 参考八皇后解决问题，直接将八个数字构造成八个矩阵坐标，然后每个坐标按八个方向遍历，看是否在一条直线即可
 坐标无所谓顺序，用map保存，还能查找，一举两得，但是会超时
 修改后：
 以空间换时间，设置行、列、对角线数组
 */

//bool isSolution(map<pair<int, int>,int> cd_map){
//    //左、右、下、上、左下、左上、右下、右上 八个方向
//    int dx[] = {-1,1,0,0,-1,-1,1,1};
//    int dy[] = {0,0,-1,1,-1,1,-1,1};
//    int n = (int)cd_map.size();
//    map<pair<int, int>,int> ::iterator it;
//    for(it = cd_map.begin(); it != cd_map.end(); it++){
//        int x = it->first.first;
//        int y = it->first.second;
//        for(int i = 1; i < n; i ++){
//            for(int k = 0; k < 8; k ++){
//                int new_x = x + i * dx[k];
//                int new_y = y + i * dy[k];
//                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n){
//                    if(cd_map.find(make_pair(new_x, new_y)) != cd_map.end()) return false;
//                }
//            }
//        }
//    }
//    return true;
//}

const int maxn=1000+5;

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i ++){
        int m;
        scanf("%d",&m);
        int row[maxn] = {0};
        int col[maxn] = {0};
        int diagonal[maxn*2] = {0};
        bool flag = true;
        for(int j = 1; j <= m; j++){
            int x;
            scanf("%d",&x);
            row[j] ++;
            col[x] ++;
            diagonal[j+x-1] ++;
            if(row[j]>1)
                flag=false;
            if(col[x]>1)
                flag=false;
            if(diagonal[j+x-1]>1)
                flag=false;
        }
        if(flag){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

