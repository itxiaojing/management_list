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
	int Job_ID;		 //操作工人编号
	time_t loan_time;	 //借书时间
	time_t return_time; //归还时间
	int loan_num;    //借出数量
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

void buffer(void);

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
void ordinary_login(node* l);

//物资借还相关函数
node_use* use_create(void);
use* use_tianjia(void);
void use_push_back(node_use* k, node_mat* m, node* l, use* data);
char* use_dle(void);
int use_updata(node_mat* m, node_use* k ,char* use);
int use_find(node_use* k, int Job_ID);
int use_dle1();

void write_infor(node* s1, node_mat* s2, node_use* s3);
void read_infor(node* s1, node_mat* s2, node_use* s3);

void sta_fiad(node* l);
void sta_mod_password(node* l);
#endif
