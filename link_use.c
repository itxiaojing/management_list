#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sys.h"
const char* weekday[] = {"日", "一", "二", "三", "四", "五", "六"};
                
void buffer(void)
{
	while(getchar() != '\n');
}

//创建空链表
node_use* use_create(void)
{
	node_use* n = (node_use*)malloc(sizeof(node_use));
	n->next = NULL;

	return n;
}

use* use_tianjia(void)
{
	use* s = (use*)malloc(sizeof(use));
	printf("请录入物资借还信息：\n");
	printf("请输入物资编号：");
	scanf("%30s",s->mat_ser);
	buffer();
	printf("请输入操作用户编号：");
	scanf("%d",&s->Job_ID);
	buffer();
	s->loan_time = time(NULL);
	s->return_time = 0;
	printf("请输入借出数量：");
	scanf("%d",&s->loan_num);
	buffer();
	return s;
}
//在链表尾部插入节点
void use_push_back(node_use* k, node_mat* m, node* l, use* data)
{
	while(l->next != NULL && l->next->data->Job_ID != data->Job_ID) l = l->next;
   if(l->next == NULL) 
   {
   		printf("您无此权限，请升级为普通用户\n");
		return;
   }
	while(m->next != NULL && m->next->data->mat_ser != data->mat_ser) m = m->next;
   if(m->next == NULL) 
   {
   		printf("很抱歉没有此件物资\n");
		return;
   }   
	if(data->loan_num > m->next->data->mat_num)
	{
		printf("很抱歉，此物资数量不足！！！\n");
		return;
	}
	node_use* n = (node_use*)malloc(sizeof(node_use));
	n->data = data;
	n->next = NULL;
	m->next->data->mat_num -= data->loan_num;

	//找到链表原来节点
	while(k->next != NULL) k = k->next;
	//在尾部插入
	k->next = n;
}

//删除某个节点
//返回0失败，返回1成功
char* use_dle(void)
{
	char* use = (char*)malloc(30);
	printf("请输入物资编号：");
	scanf("%30s",use);
	 buffer();
	return use;
}


//物资归还
//返回0失败，返回1成功
int use_updata(node_mat* m, node_use* k,char* use)
{
	k = k->next;
	while(k != NULL && strcmp(k->data->mat_ser, use)) k = k->next;
	if(k == NULL) return 0;

	printf("物资归还记录信息如下：");
	printf("物资编号：%s\n",k->data->mat_ser);
	printf("操作用户：%d\n",k->data->Job_ID);
	printf("借出数量：%d\n",k->data->loan_num);
	k->data->return_time = time(NULL);
	while(m->next != NULL && strcmp(m->next->data->mat_ser, use)) m = m->next;
	m->next->data->mat_num += k->data->loan_num;

	return 1;
}
//查找节点数据
//失败返回0，成功返回1
int use_find(node_use* k, int Job_ID)
{
	k = k->next;
	while(k != NULL && k->data->Job_ID != Job_ID) k = k->next;
	if(k == NULL) return 0;
	printf("物资借录信息如下：");
	printf("物资编号：%s\n",k->data->mat_ser);
	printf("操作用户：%d\n",k->data->Job_ID);
	printf("借出数量：%d\n",k->data->loan_num);

	struct tm* loan_time = localtime(&k->data->loan_time);
	printf("借出时间：%d年%d月%d日 %d:%02d:%02d 星期%s\n", loan_time->tm_year + 1900, loan_time->tm_mon + 1, loan_time->tm_mday, loan_time->tm_hour, loan_time->tm_min, loan_time->tm_sec, weekday[loan_time->tm_wday]);
	
	struct tm* now_time = localtime(&k->data->return_time);
	printf("归还时间：%d年%d月%d日 %d:%02d:%02d 星期%s\n", now_time->tm_year + 1900, now_time->tm_mon + 1, now_time->tm_mday, now_time->tm_hour, now_time->tm_min, now_time->tm_sec, weekday[now_time->tm_wday]);


	return 1;
}

