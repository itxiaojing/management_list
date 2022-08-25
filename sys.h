#ifndef _SYS_H_
#define _SYS_H_

typedef struct materiais
{
	char mat_ser[30];     //物资编号
	char mat_name[31];   //物资名称
	int mat_sum;   		 //物资总数
	int mat_num;		 //物资剩余
}mat;

struct user
{
	int Job_ID;
	char password[20];
	char name[30];
	char sex;//0表示女，1表示男
	char ID[19];
	char Telephone[15];
};

typedef struct use_information
{
	char mat_ser[30];//物资编号
	int Job_ID;
	int loan_time;
	int return_time;
	int loan_num;
}use;

struct admin
{
	char name[30];
	char pasword[30];
};


typedef struct node
{
    struct user* data;//用户数据域
    struct node* next;//指针域,存放后继节点指针
}node;

typedef struct node_mat
{
    mat* data;//用户数据域
    struct node_mat* next;//指针域,存放后继节点指针
}node_mat;

typedef struct node_use                                                                                                                                        
{
    use* data;//用户数据域
    struct node_use* next;//指针域,存放后继节点指针
}node_use;

node* l;		//普通用户链表指针
node_mat* m;	//物资信息链表指针
node_use* k;	//借还物资信息记录链表指针


//用户信息相关函数
node* create(void);
struct user* tianjia(void);
void push_back(node* l, struct user*data);
int remove_list(node*l, int);
int updata(node* l, int);
int find(node* l, int);
void mam_sys_menu1(void);
int dle(void);
//物资信息相关函数
node_mat* mat_create(void);
mat* mat_tianjia(void);
void mat_push_back(node_mat* m, mat* data);
char* mat_dle(void);
int mat_remove_list(node_mat*m, char* ser);
int mat_updata(node_mat* m, char* ser);
int mat_find(node_mat* m, char* ser);
//界面相关函数
void menu1(void);
void menu2(void);
//密码相关函数
void user_login(void);
void modify_admin_info(void);

#endif
