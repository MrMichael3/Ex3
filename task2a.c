//Michael Küchler, 16-924-318

#include <stdio.h>

void swap(int A[], int i, int j){
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
int partitionHoare(int A[], int low, int high){
	int pivot = A[high];
	int i = high-1;
	for(int j = low;j<high;j++){
		if(A[j]<=pivot){
			i++;
			swap(A,i,j);
		}
	}
	swap(A,i+1,high);
	return (i+1);
}
void quicksort(int A[], int low, int high){
	if(low<high){
		int q = partitionHoare(A, low, high);
		quicksort(A,low,q-1);
		quicksort(A,q+1,high);
	}
}
void printArray(int A[], int size){
	printf("sorted Array: [");
	for(int i = 0;i<size-1;i++){
		printf("A[i], ");
	}
	printf("A[n-1]]");
	
}


int main(){
	int A[]= {4,3,2,5,6,7,8,9,12,1};
	int n = 10;
	quicksort(A,0,n-1);
	printArray(A,n);
	
	return 0;
}
