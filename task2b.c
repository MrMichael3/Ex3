//Michael Küchler, 16-924-318

#include <stdio.h>

void swap(int A[], int i, int j){
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
int partitionHoare(int A[], int low, int high, int choice){
	int pivot;
	if(choice == 0){
		pivot = A[high];
	}
	else{
		//find pivot
		int middle = (high + low)/2;
		if(A[low]<=A[high]){
			if(A[low]>= A[middle]){
				pivot = low;
			}
			else{
				if(A[high]<=A[middle]){
					pivot = high;
				}
				else{
					pivot = middle;
				}
			}
		}
		else{
			if(A[high]>= A[middle]){
				pivot = high;
			}
			else{
				if(A[low]<=A[middle]){
					pivot = low;
				}
				else{
					pivot = middle;
				}
			}
		}
	}
	//swap pivot with last element
	if(pivot != high){
		swap(A,pivot,high);
	}
	pivot = A[high];
	int i = low-1;
	for(int j = low;j<high;j++){
		if(A[j]<=pivot){
			i++;
			swap(A,i,j);
		}
	}
	swap(A,i+1,high);
	return (i+1);
}
void quicksort(int A[], int low, int high, int choice){
	
	if(low<high){
		int q = partitionHoare(A, low, high,choice);
		quicksort(A,low,q-1,choice);
		quicksort(A,q+1,high,choice);
	}
}
void printArray(int A[], int size){
	printf("sorted Array: [");
	for(int i = 0;i<size-1;i++){
		printf("%d,",A[i]);
	}
	printf("%d]",A[size-1]);
	
}


int main(){
	int A[]= {4,3,2,5,6,7,8,9,12,1};
	int n = 10;
	quicksort(A,0,n-1,1);
	printArray(A,n);
	
	return 0;
}
