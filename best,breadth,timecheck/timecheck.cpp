#include "bestsearch.cpp"
#include "breadthsearch.cpp"
#include <ctime>

int main(){
    clock_t bestt;
    clock_t breadtht;
    breadtht = clock();
    int answer2=0;
    knapsack2(N,W,answer2);
    printf("\n");
    breadtht = clock()-breadtht;
    bestt = clock();
    int answer3=0;
    knapsack3(N,W,answer3);
    printf("\n");
    bestt = clock()-bestt;
    printf("breadth first search -> max profit : %d\n",answer2);
    printf("breadth first search -> node count : %d\n",breadth_count+1);
    printf("breadth first search -> time : %f seconds\n",((float)breadtht)/(CLOCKS_PER_SEC));
    printf("\n");
    printf("best first search -> max profit : %d\n",answer3);
    printf("best first search -> node count : %d\n",best_count+1);
    printf("best first search -> time : %f seconds\n",((float)bestt)/(CLOCKS_PER_SEC));
    printf("\n");
    return 0;
}
