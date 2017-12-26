#include <stdio.h>
#include <iostream>     
#include <algorithm>
#include <string.h>
#include <limits>
#include <chrono>
#include <ctime>
using namespace std;

int array2[(1<<24)+18][18];
#define INF 987654321
int main() {
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
   
    
    int i,j,n,answer,k,p;
     //int array[5][5]={{0 ,6 ,6, 10, 8},{3 ,0, 12, 7 ,6},{8 ,7 ,0 ,14 ,20},{5 ,13, 9 ,0 ,8},{9 ,8 ,10, 6 ,0}};
   //int array[9][9]={{0,1,6,4,5,9,3,3,1},{5,0,5,6,2,7,6,9,6},{4,2,0,3,2,3,5,9,5},{8,1,6,0,4,3,2,5,1},{9,7,7,9,0,2,1,1,8},{6,7,5,6,1,0,1,7,1},{2,5,8,7,9,8,0,7,2},{1,2,9,1,9,6,7,0,5},{3,5,3,5,8,9,5,8,0}};
    n=18; 
     int array[18][18]={
    {0, 10, 2, 3, 4, 5, 9, 10, 1, 5, 5, 6, 9, 1, 8, 10, 10, 3}, 
{3, 0, 4, 3, 2, 7, 1, 1, 10, 9, 9, 9, 10, 5, 9, 1, 1, 6},
{1, 3, 0, 8, 10, 2, 7, 5, 9, 4, 8, 7, 2, 1, 4, 8, 1, 7}, 
{3, 6, 1, 0, 9, 7, 2, 5, 10, 2, 4, 2, 2, 10, 7, 5, 2, 10}, 
{8, 1, 9, 6, 0, 10, 10, 6, 1, 7, 4, 4, 9, 5, 10, 9, 5, 2}, 
{5, 2, 4, 8, 4, 0, 1, 4, 9, 6, 7, 2, 7, 6, 1, 6, 3, 3}, 
{7, 5, 4, 4, 9, 2, 0, 1, 1, 3, 5, 2, 2, 4, 7, 8, 9, 6}, 
{2, 3, 1, 3, 9, 8, 6, 0, 9, 3, 10, 3, 5, 5, 7, 8, 5, 10},
{5, 5, 1, 2, 3, 9, 2, 7, 0, 7, 10, 7, 8, 7, 5, 8, 2, 9}, 
{4, 6, 8, 1, 3, 4, 10, 5, 10, 0, 6, 6, 10, 1, 6, 5, 7, 1},
 {10, 7, 9, 8, 4, 9, 3, 3, 9, 3, 0, 6, 8, 9, 2, 4, 7, 5}, 
 {1, 3, 3, 3, 6, 5, 8, 9, 8, 7, 4, 0, 4, 3, 2, 3, 1, 2}, 
 {8, 1, 9, 8, 3, 10, 3, 8, 1, 10, 4, 1, 0, 6, 5, 4, 4, 5}, 
 {7, 10, 8, 2, 6, 4, 3, 8, 4, 7, 10, 8, 3, 0, 3, 3, 4, 2}, 
 {1, 4, 5, 10, 10, 2, 3, 4, 3, 4, 8, 9, 8, 10, 0, 2, 1, 6},
  {5, 8, 1, 8, 7, 8, 4, 5, 4, 2, 1, 9, 4, 10, 10, 0, 8, 3}, 
  {9, 2, 9, 8, 9, 1, 7, 6, 7, 9, 6, 1, 10, 2, 8, 1, 0, 6},
   {1, 4, 2, 7, 3, 7, 5, 8, 10, 1, 1, 9, 4, 9, 8, 1, 5, 0}};

        
        for (k=0; k<n; k++) {
            for (i=0; i<n; i++) {
                for (j=0; j<n; j++) {
                    if (i!=j && i!=k && j!=k) array[i][j]=min(array[i][k]+array[k][j],array[i][j]);
                }
            }
        }
        
        memset(array2,-1,sizeof(array2));
        array2[1][0]=0;
       
        for (i=1; i<(1<<n); i++) {
            for (j=0; j<n; j++) {
                if (array2[i][j]==-1) continue;
                for (k=1; k<n; k++) {
                    if ((i & (1<<k))!=0) continue;
                    p=(i | (1<<k));
                    if (array2[p][k]==-1) array2[p][k]=array2[i][j]+array[j][k];
                    array2[p][k]=min(array2[p][k],array2[i][j]+array[j][k]);
                    
                }
                 //printf("array2: %d k: %d j : %d \n",array2[i][0],k,j+1);

            }

        }
        answer=INF;
        
        for (i=1; i<n; i++) {
            if (array2[(1<<n)-1][i]>0) answer=min(answer,array2[(1<<n)-1][i]+array[i][0]);
            //printf("%d",answer);
            //printf("%d\n",array[2][i]);
        }
        printf("%d\n",answer);
        end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        cout<< "time: " << elapsed_seconds.count() << "s\n";
    
    return 0;
}