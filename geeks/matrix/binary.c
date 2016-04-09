#include<stdio.h>
#define M 4
#define N 4
void binary();
void binary()
{
	int i,j;
	int a[M][N];
	int rowFlag = 0;
	int columnFlag = 0;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<N;i++){
		if(a[0][i]==1){
			rowFlag =1;
			break;
		}
	}
	for(i=0;i<M;i++){
		if(a[i][0]==1)
			{columnFlag=1;
				break;
				}
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(a[i][j]==1){
				a[i][0]=1;
				a[0][j]=1;
			}
	}
}
for(i=1;i<M;i++){
		for(j=1;j<N;j++){
			if(a[i][0]||a[0][j]){
				a[i][j]=1;
			}
			else
			a[i][j]=0;	
	}
}
if(rowFlag){
for(i=0;i<N;i++){
	a[0][i]=1;
}
}
if(columnFlag){
for(i=0;i<M;i++){
	a[i][0]=1;
}
}
for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf(" %d ",a[i][j]);
	}
	printf("\n");
}

}

int main(void){
	
	binary();
	return 0;
}