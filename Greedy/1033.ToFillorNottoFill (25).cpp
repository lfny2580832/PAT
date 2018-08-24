/*
1033 To Fill or Not to Fill (25)（25 分）

With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive numbers: C~max~ (<= 100), the maximum capacity of the tank; D (<=30000), the distance between Hangzhou and the destination city; D~avg~ (<=20), the average distance per unit gas that the car can run; and N (<= 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: P~i~, the unit gas price, and D~i~ (<=D), the distance between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print "The maximum travel distance = X" where X is the maximum possible distance the car can run, accurate up to 2 decimal places.

Sample Input 1:

50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
Sample Output 1:

749.17
Sample Input 2:

50 1300 12 2
7.10 0
7.00 600
Sample Output 2:

The maximum travel distance = 1200.00
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
 贪心策略：设满箱油行驶600m
 1、600m范围内，有目的地 —— 计算到达目的地所需要的油量
 2、600m范围内没加油站，能跑多远跑多远
 3、600m范围内有加油站：
    a、有比当前便宜的加油站，加刚好的油到那个加油站，若有多个便宜的，选最近的那个
    b、没比当前便宜的加油站，加满油，然后找600m范围内最便宜的加油站
 特殊情况：
 1、起点没有加油站
 2、起点即终点
 */

struct gasStation{
    double dis;
    double price;
}station[502];

bool cmp(gasStation a,gasStation b){
    return a.dis < b.dis;
}

int main(){
    double Cmax,D,Davg;
    int N;
    scanf("%lf %lf %lf %d",&Cmax,&D,&Davg,&N);
    for(int i = 0; i < N; i ++){
        scanf("%lf %lf",&station[i].price,&station[i].dis);
    }
    sort(station,station+N,cmp);
    if(D == 0){
        printf("0.00\n");
        return 0;
    }
    if(station[0].dis != 0){
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    //贪心策略
    int curStation = 0;
    double curGas = 0,curCost = 0;
    double range = Cmax * Davg;
    while(1){
        bool hasStation = false;
        bool hasCheaper = false;
        double cheapestPrice = 10000;
        int cheapestPos = 0;
        for(int i = curStation + 1; i < N; i ++){
            //范围内的加油站————————情况3
            if(station[i].dis - station[curStation].dis <= range){
                hasStation = true;
                //最近的便宜加油站———————情况 3.a
                if(station[i].price < station[curStation].price){
                    hasCheaper = true;
                    double dis = station[i].dis - station[curStation].dis;
                    double neededGas = dis/Davg - curGas;
                    //到达该加油站
                    curGas = 0;
                    curCost += (neededGas*station[curStation].price);
                    curStation = i;
                    break;
                }
                //没有更便宜的加油站，找范围里最便宜的，为3.b做准备
                //若上面的条件一直没执行（hascheaper为false）则有用，否则用不到
                if(station[i].price < cheapestPrice){
                    cheapestPrice = station[i].price;
                    cheapestPos = i;
                }
            }else
                break;
        }
        //范围内有但没有比当前更便宜的加油站，且能到达终点————————情况1
        if(hasCheaper == false && (range) >= D - station[curStation].dis){
            double dis = D - station[curStation].dis;
            double neededGas = dis/Davg - curGas;
            curCost += neededGas * station[curStation].price;
            printf("%.2lf\n",curCost);
            return 0;
        }
        //范围内有但没有比当前更便宜的加油站，且无法到达终点，需要去下一站————————情况3.b
        if(hasCheaper == false && hasStation == true){
            //加满油，算价格
            double neededGas = Cmax - curGas;
            curCost += (neededGas * station[curStation].price);
            //去那个较便宜的加油站
            double dis = station[cheapestPos].dis - station[curStation].dis;
            curGas = Cmax - dis/Davg;
            curStation = cheapestPos;
        }
        //范围内没加油站了——————情况2
        else if(hasStation == false){
            printf("The maximum travel distance = %.2lf\n",station[curStation].dis + range);
            return 0;
        }
    }
    return 0;
}
