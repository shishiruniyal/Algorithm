#include "redBlack.h"
#include <stdlib.h>
#include <stdio.h>


int main (void)
{

node *nil;
nil = (node *)malloc(sizeof(node));
nil->data = -1;
nil->left = NULL;
nil->right = NULL;
nil->black =1;
nil->parent = NULL;
nil->count = 0;

  node *root = nil;
  (root)->parent = nil;
  long int data, check,testcase,rank,element;
  int status;
  node *temp;
  printf ("Enter 0 to search and 1 for insert and 2 for delete 3 for rank\n");
  scanf("%ld",&testcase);
  while (testcase >0)
    {
      scanf ("%ld %ld", &check, &data);
      switch (check)
	{
	case 0:
	  search (&root, data,nil);
	  break;

	case 1:
		temp = newNode(data,nil);
	  status = insert (&root,temp,nil);
	  if (status == 0)
	    printf ("Inserted\n");
	  break;
	

	case 2:
	  status = delete (&root, data,nil);
	  if (status != 0)
	    printf ("element not exists\n");
	else{
		printf("Deleted\n");
	}
	  break;

	  case 3:
	  	rank = Rank(data,root,nil);
	  	printf("Rank is = %ld\n",rank);
	  	break;

	  case 4:
	  element = FindRank(data, root, nil);
	  if(element == 0)
	  {
	  	printf("Element with rank %ld not exists\n",data);
	  }
	  else
	  {
	  printf("Element with rank %ld is = %ld\n",data,element);
	}
	  break;
	// case 9:
	//   Inorder (root,root,nil);
	//   printf ("\n");
	//   break;

	default:
	  break;
	}
	testcase --;
    }

//Inorder (root,root,nil);
// printf("count = %ld\n",doubleRed(root));

printf("total count = %ld\n",root->count);

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