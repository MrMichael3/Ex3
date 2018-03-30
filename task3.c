//Michael Küchler, 16-924-318

#include <stdio.h>
#include <time.h>

void readFile(char filename[], int output[], int *n){
	FILE *f;
	int i;
	f= fopen(filename,"r");
	i = 0;
	while(fscanf(f,"%d", &output[i])==1){
		i++;
	}
	*n= i-1;
	fclose(f);
}

int main(){
	clock_t start;
	clock_t end;
	float seconds;
	start = clock();
	//sorting function
	end = clock();
	seconds = (float)(end - start)/CLOCKS_PER_SEC;
	printf("secs: %f\n", seconds);
	return 0;
}
