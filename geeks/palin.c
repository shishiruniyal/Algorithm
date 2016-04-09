#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int i,int j,char *,int);
int lcs(char *,char *,int ,int);

int len1,len2;
int **table;
int count=0;
char *aa,*bb;
char *s1,*s2,*s3,*s4;
int main(void){
  int i,j;
  int a,b;
  int test;
  scanf("%d",&test);
  while(test>0){
    int flag=0;
    s1 = (char *)malloc(sizeof(char)*1000);
    s2 = (char *)malloc(sizeof(char)*1000);
    s3 = (char *)malloc(sizeof(char)*1000);
    s4 = (char *)malloc(sizeof(char)*1000);
scanf("%s",s1);
scanf("%s",s3);

for(i=0;i<strlen(s1);i++){
        for(j=0;j<strlen(s3);j++){
          if(s1[i]==s3[j])
          { flag = 1;
            break; }
        }
        if(flag)
          break;
      }
len1 = strlen(s1);
for(i=len1-1;i>=0;i--){
  s2[i] = s1[len1-1-i];
}
len2 = len1;
a = lcs(s1,s2,len1,len2);
aa = (char *)malloc(sizeof(char)*a);
count =0;
print(len1,len2,s1,1);
for(i=0;i<a;i++){
  printf("%c",aa[i]);
}
printf(" \n a = %d\n",a);

// for(i=0;i<len1+1;i++){
//   for(j=0;j<len1+1;j++){
//     printf(" %d ",table[i][j]);
//   }
//   printf("\n");
// }

len1 = strlen(s3);
for(i=len1-1;i>=0;i--){
  s4[i] = s3[len1-1-i];
}

len2 = len1;
b = lcs(s3,s4,len1,len2);
bb = (char *)malloc(sizeof(char)*b);
count =0;
print(len1,len2,s3,0);

for(i=0;i<b;i++){
  printf("%c",bb[i]);
}
printf("\n");
printf(" \nb = %d\n",b);
printf("flag = %d\n",flag);

if(a%2==0 || b%2==0){
  printf("first :%d\n",a+b);
}
else {
  if(aa[(a/2)]==bb[(b/2)]){
    printf("Second :%d\n",a+b);
  }
  else{
    if(a==1 && b==1 && flag==1){
     printf("Third :%d\n",a+b);
    }
    else
    printf("Fourth :%d\n",a+b-1);
  }
}
free(aa);
free(bb);
free(s1);
free(s2);
free(s3);
free(s4);
free(table);
test--;
}
return 0;
}

int lcs(char *s1,char *s2,int len1,int len2){
  int i,j;
table = (int **)malloc(sizeof(int *)*(len1+1) );
for(i=0;i<len1+1;i++){
  table[i] = (int *)malloc(sizeof(int)*(len2+1));
}
i=0;
for(j=0;j<len2+1;j++){
  table[i][j] = 0;
}
j=0;
for(i=0;i<len1+1;i++){
  table[i][j] = 0;
}
for(i=1;i<len1+1;i++){
  for(j=1;j<len2+1;j++){
    int max;
    if(s1[i-1]==s2[j-1]){
      table[i][j] = 1+table[i-1][j-1];
    }
    else{
      max = table[i-1][j];
      if(max < table[i][j-1]){
        max = table[i][j-1];
      }
        table[i][j] = max;
    }
  }
}

return(table[len1][len2]);

}

void print(int i,int j,char *s1,int flag){
  if(i==0 || j==0){
    return;
  }
if(s1[i-1]==s1[strlen(s1)-j])
{
  print(i-1,j-1,s1,flag);
  if(flag){
  aa[count] = s1[i-1];
 // printf("i=%d %c ",i,s1[i-1]);
  }
  else
     bb[count] = s1[i-1];
  count ++;
}
else {
  if(table[i][j-1]>table[i-1][j]){
    print(i,j-1,s1,flag);
  }
  else{
    print(i-1,j,s1,flag);
  }
}

}