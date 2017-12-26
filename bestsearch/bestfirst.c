#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum dir {
	left = 1,
	right = 2
};

int maxProfit = 0;
int w;
int n;

typedef struct ITEM {
	int profit;
	int weight;
	int pw;
	int bound;
}item;

int log_two(int n) { return (int)(log(n) / log(2)); }

int Get(item** it, int weight, int i) {
	i++;
	for(; i < n-1; i++) {
		weight += it[i]->weight;
		if(weight > w)
			break;
	}
	if(i == n)
		return 0;
	return i;
}

int Bound(item** it, int profit, int weight, int i) {
	int k = Get(it, weight, i);
	int totalWeight = TotalWeight(it, weight, i);
	i++;
	if(i >= n)
		return 0;
	for(; i < k; i++)
		profit += it[i]->profit;
	profit = profit + ((w - totalWeight) * it[k]->pw);
	return profit;
}

void Set(item* it, int profit, int weight) {
	it->profit = profit;
	it->weight = weight;
	it->bound = 0;
	if(profit == 0)
		it->pw = 0;
	else
		it->pw = profit / weight;
}

void Sett(item * arr, int profit, int weight, int i, item ** it) {
	arr->profit = profit;
	arr->weight = weight;
	arr->bound = Bound(it, profit, weight, i);
	if(arr->weight > w) {
		arr->profit = 0;
	}
	else if (arr->profit > maxProfit)
		maxProfit = arr->profit;
}

int TotalWeight(item** it, int weight, int i) {
	int k = Get(it, weight, i);
	i++;
	if(i >= n)
		return 0;
	for(; i < k; i++)
		weight += it[i]->weight;
	return weight;
}

void search(item** arr, item** it, int index, int depth) {
	int i;
	int max;
	if(index >= n-1 || depth >= (int)pow(2, n))
		return;

	if(arr[depth]->weight > w) arr[depth]->profit = 0;
	else if(arr[depth]->profit > maxProfit)
		maxProfit = arr[depth]->profit;

	arr[depth * 2 + (int)left] = (item*)malloc(sizeof(item));
	arr[depth * 2 + (int)right] = (item*)malloc(sizeof(item));

	Sett(arr[depth * 2 + (int)left], arr[depth]->profit + it[index+1]->profit,
		arr[depth]->weight + it[index+1]->weight,
		 index+1, it);
	Sett(arr[depth * 2 + (int)right], arr[depth]->profit,
		arr[depth]->weight,
		 index+1, it);

	arr[depth]->bound = 0;
	max = depth;
	for(i=1; i<=depth * 2 + right; i++) {
		if(arr[i] != NULL)
			if(arr[max]->bound < arr[i]->bound)
				max = i;
	}

	if(arr[max]->bound > maxProfit && max != depth)
		search(arr, it, log_two(max+2), max);
}

int main(void)
{
	int i;
	w = 13;
	n = 6;
	item** it = (item**)malloc(sizeof(item*) * n);
	item** arr = (item**)malloc(sizeof(item*) * ((int)pow(2,n)));
	for(i=0; i<(int)pow(2,n); i++)
		arr[i] = NULL;

	for(i=0; i<n; i++)
		it[i] = (item*)malloc(sizeof(item));
	Set(it[0], 0, 0);
	Set(it[1], 20, 2);
	Set(it[2], 30, 5);
	Set(it[3], 35, 7);
	Set(it[4], 12, 3);
	Set(it[5], 3, 1);

	arr[0] = (item*)malloc(sizeof(item));
	Set(arr[0], 0, 0);
	
	search(arr, it, 0, 0);

	printf("max : %d \n", maxProfit);

	return 0;
}