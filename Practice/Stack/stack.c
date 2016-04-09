#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

NODE* top = NULL;

 int push(void * data){
 	if(top == NULL){
 		top = (NODE*)malloc(sizeof(NODE)*1);
 		top->next = NULL;
 	}
	NODE* nod = (NODE*)malloc(sizeof(NODE)*1);
	if(nod==NULL){
		return -1;
	}
	nod->next = top->next;
	nod->data = data;
	top->next = nod;

	return 0;
}

void* peek(){
	if(top->next==NULL){
		return NULL;
	}
	void* temp = (top->next)->data;
	return temp;
}

void* pop(){
	if(top->next==NULL){
		return NULL;
	}
	NODE* temp = top->next;
	void* value = (top->next)->data;
	top->next = (top->next)->next;
	free(temp);
	temp=NULL;
	return value;
}