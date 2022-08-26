
#include <stdio.h>
#include <stdlib.h>
#include "sys.h"


void write_infor(node* s1, node_mat* s2, node_use* s3)
{
	s1 = s1->next;
	s2 = s2->next;
	s3 = s3->next;

	FILE* fp1 = fopen("node_infor", "wb");
	FILE* fp2 = fopen("mat_infor", "wb");
	FILE* fp3 = fopen("use_infor", "wb");

	if((fp1 == NULL) || (fp2 == NULL) || (fp3 == NULL))
	{
		perror("fopen error!");
		return;
	}

	while(s1 != NULL)
	{
		fwrite(s1->data, sizeof(struct user), 1, fp1);
		s1 = s1->next;
	}



	while(s2 != NULL)
	{
		fwrite(s2->data, sizeof(mat), 1, fp2);
		s2 = s2->next;
	}


	
	while(s3 != NULL)
	{
		fwrite(s3->data, sizeof(use), 1, fp3);
		s3 = s3->next;
	}

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}




















