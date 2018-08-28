/*
1114. Family Property (25)
This time, you are supposed to help us collect the data for family-owned property. Given each person’s family members, and the estate（房产）info under his/her own name, we need to know the size of each family, and the average area and number of sets of their real estate.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=1000). Then N lines follow, each gives the infomation of a person who owns estate in the format:

ID Father Mother k Child1 … Childk M_estate Area

where ID is a unique 4-digit identification number for each person; Father and Mother are the ID’s of this person’s parents (if a parent has passed away, -1 will be given instead); k (0<=k<=5) is the number of children of this person; Childi’s are the ID’s of his/her children; M_estate is the total number of sets of the real estate under his/her name; and Area is the total area of his/her estate.

Output Specification:

For each case, first print in a line the number of families (all the people that are related directly or indirectly are considered in the same family). Then output the family info in the format:

ID M AVG_sets AVG_area

where ID is the smallest ID in the family; M is the total number of family members; AVG_sets is the average number of sets of their real estate; and AVG_area is the average area. The average numbers must be accurate up to 3 decimal places. The families must be given in descending order of their average areas, and in ascending order of the ID’s if there is a tie.

Sample Input:
10
6666 5551 5552 1 7777 1 100
1234 5678 9012 1 0002 2 300
8888 -1 -1 0 1 1000
2468 0001 0004 1 2222 1 500
7777 6666 -1 0 2 300
3721 -1 -1 1 2333 2 150
9012 -1 -1 3 1236 1235 1234 1 100
1235 5678 9012 0 1 50
2222 1236 2468 2 6661 6662 1 300
2333 -1 3721 3 6661 6662 6663 1 100
Sample Output:
3
8888 1 1.000 1000.000
0001 15 0.600 100.000
5551 4 0.750 100.000
*/


#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

//info数组用来存储信息
struct PersonInfo{
    int id,fid,mid,cnt,area;
    int child[10];
}info[1000];

//家庭信息，用来输出
struct FamilyInfo{
    int id,people;
    double cnt,area;
    bool exist = false;  //true说明这是个有效被统计家庭（10000个元素里只有几个家庭）
}family[10000];

//并查集，以id为索引(4位整数)
vector<int> ufset(10000);
int showed[10000] = {0};

int findRoot(int id){
    while(id != ufset[id])
        id = ufset[id];
    return id;
}

//id小的当做父节点
void Union(int a,int b){
    int fa = findRoot(a);
    int fb = findRoot(b);
    if(fa > fb)
        ufset[fa] = fb;
    else if(fa < fb)
        ufset[fb] = fa;
}

bool cmp(FamilyInfo a, FamilyInfo b){
    if(a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < 10000; i ++)
        ufset[i] = i;
    for(int i = 0; i < n; i ++){
        int k;
        scanf("%d %d %d %d",&info[i].id,&info[i].fid,&info[i].mid,&k);
        showed[info[i].id] = 1;
        if(info[i].fid != -1){
            showed[info[i].fid] = 1;
            Union(info[i].fid, info[i].id);
        }
        if(info[i].mid != -1){
            showed[info[i].mid] = 1;
            Union(info[i].mid, info[i].id);
        }
        for(int j = 0; j < k; j++){
            scanf("%d",&info[i].child[j]);
            showed[info[i].child[j]] = 1;
            Union(info[i].child[j], info[i].id);
        }
        scanf("%d %d",&info[i].cnt,&info[i].area);
    }
    //把一个家庭所有成员的数据加到根成员上
    for(int i = 0; i < n; i ++){
        int id = findRoot(info[i].id);
        family[id].id = id;
        family[id].cnt += info[i].cnt;
        family[id].area += info[i].area;
        family[id].exist = true;
    }
    int cnt = 0;
    for(int i = 0; i < 10000; i ++){
        if(showed[i] == 1)  //统计出现过的id（人数）
            family[findRoot(i)].people++;
        if(family[i].exist == true)
            cnt ++;
    }
    for(int i = 0; i < 10000; i ++){
        if(family[i].exist){
            family[i].cnt = (family[i].cnt * 1.0 / family[i].people);
            family[i].area = (family[i].area * 1.0 / family[i].people);
        }
    }
    sort(family,family+10000,cmp);
    printf("%d\n",cnt);
    for(int i = 0; i < cnt; i ++){
        printf("%04d %d %.3lf %.3lf\n",family[i].id,family[i].people,family[i].cnt,family[i].area);
    }
    return 0;
}
