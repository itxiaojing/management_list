#include <stdio.h>
#include <stdlib.h>
#include "sys.h"


void read_infor(node* s1, node_mat* s2, node_use* s3)
{

	FILE* fp1 = fopen("node_infor", "rb");
	FILE* fp2 = fopen("mat_infor", "rb");
	FILE* fp3 = fopen("use_infor", "rb");

	if((fp1 == NULL) || (fp2 == NULL) || (fp3 == NULL))
	{
		perror("fopen error!");
		return;
	}
//		node* n = (node*) malloc (sizeof(node));
	while(1)
	{
	
	struct user* demo1 = (struct user*)malloc(sizeof(struct user));
	if(!fread(demo1, sizeof(struct user), 1, fp1)) break;
	
		node* n = (node*) malloc (sizeof(node));

		if(NULL == n)
		{
			perror("malloc error!");
			return;
		}


		n->data = demo1;
		n->next = NULL;
		while(s1->next != NULL) s1 = s1->next;
		s1->next = n;
	
	}

	while(1)
	{
	if(fread(demo2, sizeof(mat), 1, fp2)) break;
	
		node_mat* n = (node_mat*) malloc (sizeof(node_mat));

		if(NULL == n)
		{
			perror("malloc error!");
			return;
		}

		n->data = demo2;
		n->next = s2->next;
		s2->next = n;
	}
	

	while(1)
	{
		if(fread(demo3, sizeof(use), 1, fp3)) break;
	use* demo3 = (use*)malloc(sizeof(use));
		node_use* n = (node_use*) malloc (sizeof(node_use));

		if(NULL == n)
		{
			perror("malloc error!");
			return;
		}

		n->data = demo3;
		n->next = s3->next;
		s3->next = n;
	}

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}


