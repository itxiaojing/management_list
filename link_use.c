#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys.h"
                  

//创建空链表
node_use* use_create(void)
{
	node_use* n = (node_use*)malloc(sizeof(node_use));
	n->next = NULL;

	return n;
}
/*
//链表的销毁
void destroy(node* l)
{
	node* p = NULL;
	while(l != NULL)
	{
		p = l->next;
		free(p);
		l = l->next;
	}
}*/
use* use_tianjia(void)
{
	use* s = (use*)malloc(sizeof(use));
	printf("请录入借出物资信息：\n");
	printf("请输入物资编号：");
	scanf("%s",s->mat_ser);
	getchar();
	printf("请输入操作人工号：");
	scanf("%d",s->Job_ID);
	printf("请输入物资总：");
	scanf("%d",&s->mat_sum);
	printf("请输入物资余数 ：");
	scanf("%d",&s->mat_num);
	
	return s;
}
//在链表尾部插入节点
void mat_push_back(node_mat* m, mat* data)
{
	node_mat* n = (node_mat*)malloc(sizeof(node_mat));
	n->data = data;
	n->next = NULL;

	//找到链表原来节点
	while(m->next != NULL) m = m->next;
	//在尾部插入
	m->next = n;
}
/*
//在链表头部插入节点
void push_fornt(node* l, elem_type data)
{
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = l->next;

	l->next = n;
}

//任意位置位置插入
void insert(node* l,unsigned int pos, elem_type data)
{
	node* n =(node*)malloc(sizeof(node));
	n->data = data;
	
	while(pos-- && l->next != NULL) l = l->next;

	n->next = l->next;
	l->next = n;

}*/
//删除某个节点
//返回0失败，返回1成功
char* mat_dle(void)
{
	char* ser = (char*)malloc(30);
	printf("请输入物资编号：");
	scanf("%s",ser);
	return ser;
}

int mat_remove_list(node_mat*m, char* ser)
{
	while(m->next != NULL && strcmp(m->next->data->mat_ser, ser)) m = m->next;
	if(m->next == NULL) return 0;
	node_mat* p = NULL;
	m->next = m->next->next;
	free(p);
	return 1;
}

//改变节点数据
//返回0失败，返回1成功
int mat_updata(node_mat* m, char* ser)
{
	mat* s = (mat*)malloc(sizeof(mat));
	m = m->next;
	while(m->next != NULL && strcmp(m->next->data->mat_ser, ser)) m = m->next;
	if(m == NULL) return 0;
	printf("修改前物资信息：");
	printf("物资编号：%s\n",m->data->mat_ser);
	printf("物资名称：%s\n",m->data->mat_name);
	printf("物资总数：%d\n",m->data->mat_sum);
	printf("物资剩余：%d\n",m->data->mat_num);

	printf("请输入修改物资各项信息：");
	printf("请输入物资编号：");
	scanf("%s",s->mat_ser);
	printf("请输入物资名称：");
	scanf("%s",s->mat_name);
	printf("请输入物资总数：");
	getchar();
	scanf("%d",&s->mat_sum);
	printf("请输入物资剩余：");
	scanf("%d",&s->mat_num);
	
	m->data = s;
	return 1;
}
//查找节点数据
//失败返回0，成功返回1
int mat_find(node_mat* m, char* ser)
{
	m = m->next;
	while(m != NULL && strcmp(m->data->mat_ser, ser)) m = m->next;
	if(m == NULL) return 0;
	printf("物资相关信息如下：");
	printf("物资编号：%s\n",m->data->mat_ser);
	printf("物资名称：%s\n",m->data->mat_name);
	printf("物资总数：%d\n",m->data->mat_sum);
	printf("物资剩余：%d\n",m->data->mat_num);
	return 1;
}
/*
//清空，删除所有存放有数据元素的节点，即删除所有元素
void clear(node* l)
{
	node *p =l->next, *q =NULL;
	while(p != NULL)
	{
		q = p->next;
		free(p);
		q = p;
	}
	l->next = NULL;
}
*/
/*
//打印链表所有的节点  
void show(node* l)
{
	l = l->next;
	while(l != NULL) printf("%d ", l->data), l = l->next;
}
*/

