#include <stdio.h>
#include <stdlib.h>
#include "sys.h"


void read_infor(node* s1, node_mat* s2, node_use* s3)
{

	struct user* demo1 = NULL;
	mat* demo2 = NULL;
	use* demo3 = NULL;

	FILE* fp1 = fopen("node_infor", "w+b");
	FILE* fp2 = fopen("mat_infor", "w+b");
	FILE* fp3 = fopen("use_infor", "w+b");

	if((fp1 == NULL) || (fp2 == NULL) || (fp3 == NULL))
	{
		perror("fopen error!");
		return;
	}

	while(fread(demo1, sizeof(struct user), 1, fp1))
	{
		node* n = (node*) malloc (sizeof(node));

		if(NULL == n)
		{
			perror("malloc error!");
			return;
		}

		n->data = demo1;
		n->next = s1->next;
		s1->next = n;
	}

	while(fread(demo2, sizeof(mat), 1, fp2))
	{
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

	while(fread(demo3, sizeof(use), 1, fp3))
	{
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




















