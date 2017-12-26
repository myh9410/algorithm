#include <iostream>
#include <stdio.h>
#include <queue>
#include <ctime>
using namespace std;

#define W 80
#define N 50
const int w[N+1]={0,9,6,7,4,5,2,3,1,5,6,4,7,3,8,2,9,1,8,6,4,2,1,3,5,7,6,2,3,4,9,8,7,1,9,5,8
,5,4,3,6,3,2,9,8,6,5,7,3,1,4};
const int p[N+1]={0,459,300,343,192,235,92,135,44,215,252,164,280,117,304,74,324,35,272,198,128,62,30,87,140,189,156
    ,50,72,92,198,168,140,19,162,85,128,75,56,39,72,33,20,81,64,42,30,35,12,3,8};
static int best_count=0;
struct best_node{
    int level;
    int profit;
    int weight;
    int bound;
};

bool operator<(best_node a, best_node b){
   return a.bound < b.bound;
}
 
float bound(best_node u){
    int j,k;
    int totweight;
    float result,tmp;
    int remain;
    if(u.weight>=W){
        return 0;
    }
    else{
        result=u.profit;
        j=u.level+1;
        totweight=u.weight;
        remain=W-totweight;
        while((j<=N) && (remain>0)){
            if(remain>=w[j]){
                remain-=w[j];
                result+=p[j];
                j++;
            }
            else{
                tmp=(float)remain/(float)w[j];
                remain=0;
                result+=(float)p[j]*tmp;
                j++;
            }
            
            
        }
        printf("bound: %.1f\n",result); 
        return result;
    }
        
}
extern void knapsack3(int n, int wk,int &maxprofit){
    int temp;
    priority_queue<best_node> Q;
    best_node u,v;
    
    v.level=0;
    v.profit=0;
    v.weight=0;
    maxprofit=0;
    v.bound=bound(v);
    Q.push(v);
    while(!Q.empty()){
        temp=u.level;
        v=Q.top();
        Q.pop();
        
        
        
        if(v.bound>maxprofit){
            u.level=v.level+1;
            if(temp!=u.level)
                printf("\n");
            printf("LEVEl : %d\n",u.level);
            u.weight=v.weight+w[u.level];
            u.profit=v.profit+p[u.level];
            printf("L p= %d, w= %d \n",u.profit,u.weight);
            best_count++;
        }
        if((u.weight<=W) && (u.profit>maxprofit)){
            maxprofit=u.profit;
        }
        u.bound=bound(u);
        if(u.bound>maxprofit){
            Q.push(u);
            
        }
        u.weight=v.weight;
        u.profit=v.profit;
        u.bound=bound(u);
        printf("R p= %d, uw= %d \n",u.profit,u.weight);
        best_count++;
        if(u.bound>maxprofit){
            Q.push(u);

        }
        if(Q.top().profit==0){
            break;
        }
        
    }


}