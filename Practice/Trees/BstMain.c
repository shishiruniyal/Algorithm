#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <string.h>

int main(void){
int status,check,key;
char data[50];
Node *root = NULL;

printf("press 1 for insert, 2 for search, 3 for delete, 4 for traversal inorder\n");
do{

if(!scanf("%d",&check))
	exit(0) ;

switch(check){
	case 1:
	//printf("Enter key Separated by data\n");
	scanf("%d",&key);
	scanf("%s",data);
	status = insert(&root,key,data);
	if(status!=0){
		printf("Insertion failed\n");
	}
	//printf("\n");
	break;

	case 2:
	printf("Enter key to search\n");
	scanf("%d",&key);
	strcpy(data,search(root,key));
	printf("%s",data);
	printf("\n");
	break;

	case 3:

	printf("Enter key to be deleted\n");
	scanf("%d",&key);
	status = delete(&root,key);
	if(status !=0){
		printf(" Not found\n");
	}
	else{
		printf("Sucessfully deleted \n");
	}
	break;

	case 4:
	InOrder(root);
	printf("\n");
	break;

	default :
	break;

}
}
while(1);

return 0;

}