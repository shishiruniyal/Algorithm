#include "avl.h"
#include <stdlib.h>
#include <stdio.h>


int
main (void)
{

  node *root = NULL;
  long int status, data, check,testcase;
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
	  status = insert (&root, data);
	  if (status == 0)
	    printf ("Inserted\n");
	  break;

	case 2:
	  status = delete (&root, data);
	  if (status != 0)
	    printf ("element not exists\n");
	  break;

	// case 9:
	//   Inorder (root);
	//   printf ("\n");
	//   break;


	default:
	  break;
	}
	testcase --;
    }
}
