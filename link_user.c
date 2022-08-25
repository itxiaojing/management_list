#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys.h"
                  

//创建空链表
node* create(void)
{
	node* n = (node*)malloc(sizeof(node));
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
struct user* tianjia(void)
{
	struct user* s = (struct user*)malloc(sizeof(struct user));
	printf("请输入普通用户的各项信息：");
	printf("请输入工号：");
	scanf("%d",&s->Job_ID);
	printf("请输入名字：");
	scanf("%s",s->name);
	printf("请输入性别（0->女，1->男）：");
	getchar();
	scanf("%c",&s->sex);
	printf("请输入身份证号码：");
	scanf("%s",s->ID);
	getchar();
	printf("请输入电话：");
	scanf("%s",s->Telephone);
	
	return s;
}
//在链表尾部插入节点
void push_back(node* l, struct user* data)
{
	node* n = (node*)malloc(sizeof(node));
	n->data = data;
	n->next = NULL;

	//找到链表原来节点
	while(l->next != NULL) l = l->next;
	//在尾部插入
	l->next = n;
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
int dle(void)
{
	int ID;
	printf("请输入工号：");
	scanf("%d",&ID);
	return ID;
}

int remove_list(node*l, int ID)
{
	while(l->next != NULL && l->next->data->Job_ID != ID) l = l->next;
	if(l->next == NULL) return 0;
	node* p = NULL;
	l->next = l->next->next;
	free(p);
	return 1;
}

//改变节点数据
//返回0失败，返回1成功
int updata(node* l, int Job_ID)
{
	struct user* s = (struct user*)malloc(sizeof(struct user));
	l = l->next;
	while(l->next !=NULL && l->data->Job_ID != Job_ID) l = l->next;
	if(l == NULL) return 0;
	printf("修改前用户信息：");
	printf("工号：%d\n",l->data->Job_ID);
	printf("名字：%s\n",l->data->name);
	printf("性别：%s\n",l->data->sex == '1' ? "男" : "女");
	printf("身份证号码：%s\n",l->data->ID);
	printf("电话：%s\n",l->data->Telephone);

	printf("请输入用户修改的各项信息：");
	printf("请输入工号：");
	scanf("%d",&s->Job_ID);
	printf("请输入名字：");
	scanf("%s",s->name);
	printf("请输入性别（0->女，1->男）：");
	getchar();
	scanf("%c",&s->sex);
	printf("请输入身份证号码：");
	scanf("%s",s->ID);
	getchar();
	printf("请输入电话：");
	scanf("%s",s->Telephone);
	
	l->data = s;
	return 1;
}
//查找节点数据
//失败返回0，成功返回1
int find(node* l, int Job_ID)
{
	l = l->next;
	while(l != NULL && l->data->Job_ID != Job_ID) l = l->next;
	if(l == NULL) return 0;
	printf("员工相关信息如下：");
	printf("工号：%d\n",l->data->Job_ID);
	printf("名字：%s\n",l->data->name);
	printf("性别：%s\n",l->data->sex == '1' ? "男" : "女");
	printf("身份证号码：%s\n",l->data->ID);
	printf("电话：%s\n",l->data->Telephone);
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

