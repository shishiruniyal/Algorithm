#include "bst.h"

void testInser(Node **root,int key, char *data){
	int status = insert(root,key,data);
	if(status!=0){
		printf("Insertion failed\n");
	}
}

void testDelete(Node **root,int key){
	int status = delete(root,key);
	if(status !=0){
		printf("Not found\n");
	}
	else{
		printf("Sucessfully deleted \n");
	}
}
void testSearch(){
	strcpy(data,search(root,key));
	printf("%s\n",data);
}
void testInorder();