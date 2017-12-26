
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define W 13
#define N 5
static int count=0;

struct node;
struct queue_of_node;
struct node{
	int level;
	int profit;
	int weight;
	node* next;
};
struct queue_of_node{
	node* first;
	node* last;
};
const int w[N+1]={0,2,5,7,3,1};
const int p[N+1]={0,20,30,35,12,3};
void initialize(queue_of_node &qnode){
	qnode.first=new node[4];
	qnode.last=new node[4];
 	qnode.first=NULL;
 	qnode.last=NULL;
}
void enqueue(queue_of_node &qnode,node inode){
	node* tnode=new node[4];
	
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


void dequeue(queue_of_node &qnode,node & vnode){
	node* tnode=new node[4];
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
bool empty(queue_of_node &qnode){
	if(qnode.first==NULL){
		return true;
	}
	else{
		return false;
	}
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
void knapsack2(int n, int wk,int &maxprofit){
	int temp;
	queue_of_node Q;
	node u,v;
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
		//printf("w[%d]=%d, p[%d]=%d\n",u.level,w[u.level],u.level,p[u.level]);
		u.weight=v.weight+w[u.level];
		u.profit=v.profit+p[u.level];
		printf("L p= %d, w= %d \n",u.profit,u.weight);
		count++;
		//printf("0 vp= %d, vw= %d \n",v.profit,v.weight);
		if((u.weight<=W) && (u.profit>maxprofit)){
			maxprofit=u.profit;
		}
		if(bound(u)>maxprofit){
			
			enqueue(Q,u);
		}
		//else
			//printf("1 LEVEl : %d\n",u.level);
		u.weight=v.weight;
		u.profit=v.profit;
		printf("R p= %d, uw= %d \n",u.profit,u.weight);
		count++;
		if(bound(u)>maxprofit){
			
			enqueue(Q,u);
		}
		//else
			//printf("2 LEVEl : %d\n",u.level);
		
	}


}
int main(){
	int answer=0;
	knapsack2(N,W,answer);
	printf("\n");
	printf("max profit : %d\n",answer);
	printf("node count : %d\n",count+1);
	return 0;
}