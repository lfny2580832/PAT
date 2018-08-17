/*
1091. Acute Stroke (30)
One important factor to identify acute stroke (急性脑卒中) is the volume of the stroke core. Given the results of image analysis in which the core regions are identified in each MRI slice, your job is to calculate the volume of the stroke core.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: M, N, L and T, where M and N are the sizes of each slice (i.e. pixels of a slice are in an M by N matrix, and the maximum resolution is 1286 by 128); L (<=60) is the number of slices of a brain; and T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be counted).

Then L slices are given. Each slice is represented by an M by N matrix of 0’s and 1’s, where 1 represents a pixel of stroke, and 0 means normal. Since the thickness of a slice is a constant, we only have to count the number of 1’s to obtain the volume. However, there might be several separated core regions in a brain, and only those with their volumes no less than T are counted. Two pixels are “connected” and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red pixels are connected to the blue one.
Figure 1
Output Specification:

For each case, output in a line the total volume of the stroke core.

Sample Input:
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
Sample Output:
26
*/

#include<stdio.h>
#include<queue>
using namespace std;

/*
 长宽高为M,N,L的一块组织，计算癌细胞的体积
 访问后将map置0，省去用visit数组判断
 */
struct cell{
    int x,y,z;
    cell(int _x,int _y,int _z) : x(_x),y(_y),z(_z){}
};

int M,N,L,T;

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int map[1286][128][60];

int totalVolume = 0;
void bfs(int x, int y , int z){
    queue<cell> q;
    q.push(cell(x,y,z));
    map[x][y][z] = 0;
    int volume = 1;
    while(q.size()){
        cell tmp = q.front();
        q.pop();
        for(int i = 0; i < 6; i ++){
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            int nz = tmp.z + dz[i];
            if(nx<M && nx>=0 && ny<N && ny>=0 && nz<L && nz>=0 && map[nx][ny][nz] == 1){
                q.push(cell(nx,ny,nz));
                map[nx][ny][nz] = 0;
                volume ++;
            }
        }
    }
    if(volume >= T) totalVolume += volume;
}

int main(){
    scanf("%d %d %d %d",&M,&N,&L,&T);
    for(int i = 0; i < L; i ++)
        for(int j = 0; j < M; j ++)
            for(int k = 0; k < N; k ++)
                scanf("%d",&map[j][k][i]);
    for(int i = 0; i < L; i ++)
        for(int j = 0; j < M; j ++)
            for(int k = 0; k < N; k ++)
                if(map[j][k][i] == 1) bfs(j, k, i);
    printf("%d",totalVolume);
    return 0;
}
