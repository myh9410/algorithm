#include <iostream>
#include <stdio.h>
#include <time.h>
#include <queue>
using namespace std;

#define W 13
#define N 5
const int w[N+1]={0,2,5,7,3,1};
const int p[N+1]={0,20,30,35,12,3};
static int count=0;
struct queue_of_node;
struct node{
    int level;
    int profit;
    int weight;
    int bound;
};
 
bool operator<(node a, node b){
   return a.bound < b.bound;
}
 
float bound(node u){
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
void knapsack3(int n, int wk,int &maxprofit){
    int temp;
    priority_queue<node> Q;
    node u,v;
    v.level=0;
    v.profit=0;
    v.weight=0;
    maxprofit=0;
    v.bound=bound(v);
    cout<<v.bound;
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
            count++;
        }
        
        
        //printf("0 vp= %d, vw= %d \n",v.profit,v.weight);
        if((u.weight<=W) && (u.profit>maxprofit)){
            maxprofit=u.profit;
        }
        u.bound=bound(u);
        if(u.bound>maxprofit){
            Q.push(u);
            
        }
        //else
            //printf("1 LEVEl : %d\n",u.level);
        u.weight=v.weight;
        u.profit=v.profit;
        u.bound=bound(u);
        printf("R p= %d, uw= %d \n",u.profit,u.weight);
        count++;
        if(u.bound>maxprofit){
            Q.push(u);

        }
        //else
            //printf("2 LEVEl : %d\n",u.level);
        if(Q.top().profit==0){
            break;
        }
        
    }


}
int main(){
    clock_t bestt;
    bestt = clock();
    int answer=0;
    knapsack3(N,W,answer);
    bestt = clock()-bestt;
    printf("\n");
    printf("max profit : %d\n",answer);
    printf("node count : %d\n",count+1);
    printf("best    first search -> time : %f milliseconds\n",((float)bestt)/(CLOCKS_PER_SEC/1000));
    return 0;
}
