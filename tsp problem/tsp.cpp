#include <queue>
#include <cstdio>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;


#define INFIN 999999
struct node
{
	
	int level = 0;
	int bound = 0;
	int path[8];
	bool move[8];

	node() { 
		for (int i = 0; i < 8; i++) { 
			path[i] = -1; move[i] = false; } 
		}
} ;
int matrix=8;
int array[8][8]=
		{{INFIN,5,8,INFIN,INFIN,INFIN,INFIN,INFIN},
        {INFIN,INFIN,4,INFIN,4,INFIN,INFIN,INFIN},
        {INFIN,INFIN,INFIN,2,INFIN,INFIN,5,INFIN},
        {INFIN,INFIN,INFIN,INFIN,INFIN,INFIN,7,7},
        {1,INFIN,INFIN,INFIN,INFIN,INFIN,INFIN,INFIN},
        {INFIN,6,INFIN,INFIN,2,INFIN,INFIN,INFIN},
        {INFIN,INFIN,INFIN,3,INFIN,8,INFIN,INFIN},
        {INFIN,INFIN,INFIN,INFIN,INFIN,5,4,INFIN}};


template <class C>
void copyArr(C * array1, C * array2, int matrix){ 
	int i = 0;
	while(i<matrix){
		array1[i] = array2[i]; 
		i++;
	} 
};

struct comp{
	bool operator() (node b1, node b2){
	 return b2.bound < b1.bound;
	}
} ;

int Length(node & u, const int matrix){
	
	int l = 0, i = 1;
	while(i<matrix){ 
		l += array[u.path[i - 1]][u.path[i]]; 
		i++;
	}
	l += array[u.path[i - 1]][u.path[0]];

	return l;
}

priority_queue<node, vector<node>, comp> Q;

int Bound(node & u, const int matrix)
{
	node f, l;

	int bound = 0, t = -1,i=1;
	while( u.path[i] != -1){

		bound += array[u.path[i - 1]][u.path[i]];
		l.path[i - 1] = u.path[i - 1];
		l.move[u.path[i - 1]] = true;

		f.path[i - 1] = u.path[i];
		f.move[u.path[i]] = true;

		t = u.path[i];
		i++;
	}
	for (int i = 0, temp = 0; i < matrix; i++){
		temp = INFIN;
		if (l.move[i] != true)
		{
			for (int j = 0; j < matrix; j++)
			{
				if (i == t && j == 0) { 
					continue; }
				if (f.move[j] != true && array[i][j] != 0)
					{ if (temp > array[i][j]) 
						{ temp = array[i][j];	} 
					}
			}
			bound += temp;
		}
	}
	return bound;
}

int TSP(int * b, const int matrix){
	node u, v;
	v.move[0] = true;
	v.level = 0;
	v.path[0] = 0;
	v.bound = Bound(v, matrix);

	Q.push(v);

	int result = 999999;
 
	while (! Q.empty()){
		int i = 0;
		v = Q.top(); 
		Q.pop();
		if (v.bound < result){
			u.level = v.level + 1; 	//level up
			while(i<matrix){
				if (v.move[i] == false){
					copyArr(u.path, v.path, matrix);
					copyArr(u.move, v.move, matrix);
					u.path[u.level] = i;
					u.move[i] = true;
					//printf("L2 		%d \n",u.path[u.level]+1);
					if (u.level == matrix - 2){
						int remind = 1;
						while(remind < matrix){
							remind++;
							if (u.move[remind] != true){
								break; 
							}
						}

						u.path[matrix - 1] = remind;
						u.move[remind] = true;
						//printf("R1		%d \n",u.path[u.level]+1);

						int nMin = Length(u, matrix);
						if (result > nMin)
						{
							result = nMin;
							copyArr(b, u.path, matrix);
							//printf("R2		%d \n",u.path[u.level]+1);
						}
					}
					else
					{
						u.bound = Bound(u, matrix);
						if (result > u.bound){
							Q.push(u); 
						}
					}
				}
			i++;
			}
		}
	}

	return result;
}
int main(void){
	clock_t tspt;
	tspt = clock();
	int Array[8];
	printf("%d\n", TSP(Array, matrix));
	for (int i = 0; i < matrix; i++)
	{ printf( "%d\n", Array[i] + 1); }
	printf( "%d\n", 1);
	tspt = clock()-tspt;
	printf("tsp -> time :%f\n",((float)tspt)/(CLOCKS_PER_SEC));
}
