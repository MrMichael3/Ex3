//Michael Küchler, 16-924-318

#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include "bubblesort.c"
#include "quicksort.c"
#include "quicksortM.c"
#include "heapsort.c"


void readFile(char filename[], int output[]){
	FILE *f;
	int i;
	f= fopen(filename,"r");
	i = 0;
	while(fscanf(f,"%d", &output[i])==1){
		i++;
	}
	//*n = i-1;
	fclose(f);
}


int main(){
	int A[30000];
	int length = 30000;
	char f[] = "inverse.txt";
	int *n;
	readFile(f,A);
	clock_t start;
	clock_t end;
	float seconds;
	start = clock();
	//sorting function
	quicksort(A,0,29999);
	end = clock();
	printArray(A,10);
	seconds = (float)(end - start)/CLOCKS_PER_SEC;
	printf("secs: %f\n", seconds);
	return 0;
}
