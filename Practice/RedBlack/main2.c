#include "redBlack2.h"
#include <stdlib.h>
#include <stdio.h>


int main (void)
{
// node *nil;
// nil = (node *)malloc(sizeof(node));
// nil->data = -1;
// nil->left = NULL;
// nil->right = NULL;
// nil->black =1;
// nil->parent = NULL;
  node *root = NULL;
  //(root)->parent = NULL;
  long int data, check,testcase;
  int status;
  node *temp;
  printf ("Enter 0 to search and 1 for insert and 2 for delete\n");
  scanf("%ld",&testcase);
  while (testcase >0)
    {
      scanf ("%ld %ld", &check, &data);
      switch (check)
	{
	case 0:
	  search (&root, data);
	  break;

	case 1:
	  status = insert (&root,data);
	  if (status == 0)
	    printf ("Inserted\n");
	  break;
	

	case 2:
	  status = delete (&root, data);
	  if (status != 0)
	    printf ("element not exists\n");
	else{
		printf("Deleted\n");
	}
	  break;

	// case 9:
	//   Inorder (root);
	//   printf ("\n");
	//   break;

Inorder (root);
	default:
	  break;
	}
	testcase --;
    }
//Inorder (root);

// printf("count = %ld\n",doubleRed(root));



}

// long int doubleRed(node *root){
// 	long int count = 0;
// if(root->left!=NULL){
// 		if(root->black==0 && root->left->black==0){
// 			printf("Double red detected\n");
// 			count ++;
// 		}
// 	return	count+doubleRed(root->left);
// }
// else if(root->right!=NULL){
// 	if(root->black==0 && root->right->black==0){
// 		printf("Double red detected\n");
// 		count ++;
// 	}
// 	return count+doubleRed(root->right);
// }
// }