
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
using namespace std;
#define W 80
#define N 50
static int breadth_count=0;

struct breadth_node;
struct queue_of_breadth_node;
struct breadth_node{
	int level;
	int profit;
	int weight;
	breadth_node* next;
};
struct queue_of_breadth_node{
	breadth_node* first;
	breadth_node* last;
};
const int breadth_w[N+1]={0,9,6,7,4,5,2,3,1,5,6,4,7,3,8,2,9,1,8,6,4,2,1,3,5,7,6,2,3,4,9,8,7,1,9,5,8
,5,4,3,6,3,2,9,8,6,5,7,3,1,4};
const int breadth_p[N+1]={0,459,300,343,192,235,92,135,44,215,252,164,280,117,304,74,324,35,272,198,128,62,30,87,140,189,156
	,50,72,92,198,168,140,19,162,85,128,75,56,39,72,33,20,81,64,42,30,35,12,3,8};
void initialize(queue_of_breadth_node &qnode){
	qnode.first=new breadth_node[50];
	qnode.last=new breadth_node[50];
 	qnode.first=NULL;
 	qnode.last=NULL;
}
void enqueue(queue_of_breadth_node &qnode,breadth_node inode){
	breadth_node* tnode=new breadth_node[50];
	
	tnode -> level=inode.level;
	tnode -> profit=inode.profit;
	tnode -> weight=inode.weight;
	tnode -> next=NULL;
	if(qnode.first==NULL &&qnode.last==NULL){
		qnode.first=tnode;
		qnode.last=tnode;
	}
	else{
		while(qnode.last->next !=NULL){
			qnode.last=qnode.last ->next;
		}
		qnode.last->next=tnode;
		qnode.last=qnode.last->next;
	}
}


void dequeue(queue_of_breadth_node &qnode,breadth_node & vnode){
	breadth_node* tnode=new breadth_node[50];
	if(qnode.first==NULL &&qnode.last==NULL){
		return ;
	}
	else{
		if(qnode.first==qnode.last){
			vnode.level=qnode.first->level;
			vnode.profit=qnode.first->profit;
			vnode.weight=qnode.first->weight;
			qnode.last=NULL;
			qnode.first=NULL;
		}
		else{
			vnode.level=qnode.first->level;
			vnode.profit=qnode.first->profit;
			vnode.weight=qnode.first->weight;
			tnode=qnode.first;
			qnode.first=qnode.first->next;
			tnode->next=NULL;
		}
	}
}
bool empty(queue_of_breadth_node &qnode){
	if(qnode.first==NULL){
		return true;
	}
	else{
		return false;
	}
}
float breadth_bound(breadth_node u){
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
			if(remain>=breadth_w[j]){
				remain-=breadth_w[j];
				result+=breadth_p[j];
				j++;
			}
			else{
				tmp=(float)remain/(float)breadth_w[j];
				remain=0;
				result+=(float)breadth_p[j]*tmp;
				j++;
			}
			
			
		}
		printf("bound: %.1f\n",result);	
		return result;
	}
		
}
extern void knapsack2(int n, int wk,int &maxprofit){
	int temp;
	queue_of_breadth_node Q;
	breadth_node u,v;
	initialize(Q);
	v.level=0;
	v.profit=0;
	v.weight=0;
	maxprofit=0;
	enqueue(Q,v);
	while(!empty(Q)){
		temp=u.level;
		dequeue(Q,v);
		u.level=v.level+1;
		
		if(temp!=u.level)
			printf("\n");
		printf("LEVEl : %d\n",u.level);
		u.weight=v.weight+breadth_w[u.level];
		u.profit=v.profit+breadth_p[u.level];
		printf("L p= %d, w= %d \n",u.profit,u.weight);
		breadth_count++;
		if((u.weight<=W) && (u.profit>maxprofit)){
			maxprofit=u.profit;
		}
		if(breadth_bound(u)>maxprofit){
			
			enqueue(Q,u);
		}
		u.weight=v.weight;
		u.profit=v.profit;
		printf("R p= %d, uw= %d \n",u.profit,u.weight);
		breadth_count++;
		if(breadth_bound(u)>maxprofit){
			
			enqueue(Q,u);
		}
		
	}


}