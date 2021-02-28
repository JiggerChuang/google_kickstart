#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j){
	int temp = *i;
	*i = *j;
	*j = temp;
}

void quick_sort(int a[], int left, int right){
	int pk=0, i=0, j=0;
	pk = left;
	i = left;
	j = right + 1;

	if (left < right){
		do {
			do{
				i++;
			} while ((a[i] < a[pk]) && (i <= right));
			do {
				j--;
			} while ((a[j] > a[pk]) && (j >= left));
			if (i < j)	swap(&a[i], &a[j]);
		}	while(i < j);
		swap(&a[pk], &a[j]);
		quick_sort(a, left, j-1);
		quick_sort(a, j+1, right);
	}
}

int main(){
	int test_case=0, house_num=0, budget=0, buy_num=0;
	int left=0, right=0;
	int *house;

	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++){
		scanf("%d %d", &house_num, &budget);
		house = calloc(house_num, sizeof(int));
		for (int j = 0; j < house_num; j++){
			scanf("%d", &house[j]);
		}

		// sort house price
		left = 0;
		right = house_num - 1;
		quick_sort(house, left, right);

		for (int j = 0; j < house_num; j++){
			if ((budget - house[j]) >= 0){
				buy_num++;
				budget -= house[j];
			} else {
				break;
			}
		}
		printf("Case #%d: %d\n", (i+1), buy_num);	
		
		// reinitial
		left=0;
		right=0;
		buy_num = 0;
		free(house);
	}
	
	return 0;
}
