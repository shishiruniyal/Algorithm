#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 100

int main(){
	double start,end,executionTime;
	int a[MAX],key,j,n,i,r,temp;

	srand((unsigned int)time(NULL)); // setting the seed

//Taking input size
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

//shuffle the input with knuth shuffle
/*	start = (double)clock();
	for(i=1;i<n;i++){
		r = rand()%i;
		temp = a[i];
		a[i] = a[r];
		a[r] = temp;
	}
	end = (double)clock();
	executionTime = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Time taken to shuffle array of size %d is %f\n",n,executionTime);
	printf("Shuffled array is \n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
printf("\n");
*/
//Insertion sort on shuffled array
start = (double)clock();
for(j=1;j<n;j++){
key = a[j];
i = j-1;
while(i>=0 && a[i]>key){
a[i+1]=a[i];
i--;
}
a[i+1]=key;
}
end = (double)clock();
executionTime = ((double)(end-start))/CLOCKS_PER_SEC;
printf("Time taken to sort array of size %d is %f\n",n,executionTime);
printf("Sorted array is \n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");

}