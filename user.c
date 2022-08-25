#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "sys.h"
#include "md5.h"

char uname[51];
char upass[31];
int gh, lj = 0;


int check_admin(const char* user_name, const char* user_pass);


void user_login(void)
{
	char user_name[51], *user_pass;

	printf("\n欢迎登录！\n");
	printf("用户名：");
	scanf("%s", user_name);
	user_pass = getpass("密  码：");
	
	
	if(check_admin(user_name, user_pass))
	{
		printf("用户名或密码错误！\n");
		exit(0);
	}

	strcpy(uname, user_name);
	strcpy(upass, user_pass);
}


int check_admin(const char* user_name, const char* user_pass)
{
	FILE* fp = NULL;
	char name[51], pwd[33];
	int retval = 0;

	fp = fopen("admin_info", "r");

	if(NULL == fp) return 1;

	retval = fscanf(fp, "%s%s", name, pwd);
	
	fclose(fp);

	if(2 != retval) return 2;

	if(strcmp(user_name, name) != 0)
		return 3;

	if(strcmp(pwd, md5_encode(user_pass, strlen(user_pass))) != 0)
		return 4;

	return 0;
}



void modify_admin_info(void)
{
	int op;

	printf("\n********** 修改管理员账号信息 ************\n\n");
	printf("操作提示：\n");
	printf("修改用户名请输入 1\n");
	printf("修改密码请输入 2\n");
	printf("返回上一级界面请输入 0\n");

	while(1)
	{
		printf("\n>: ");
		if(1 != scanf("%d", &op))
		{
			op = -1;
			while(getchar() != '\n');
		}

		if(op == 0) break;

		switch(op)
		{
			case 1:
			{
				// 修改用户名
				char* pwd;
				char user_name[51];
				
				pwd = getpass("\n请输入管理员密码：");

				if(strcmp(pwd, upass))
				{
					printf("\n密码错误，修改失败！\n");
					break;
				}

				printf("\n请输入新用户名：");
				scanf("%s", user_name);

				FILE* fp = fopen("admin_info", "w");
				
				if(NULL == fp)
				{
					printf("写 admin_info 文件失败！\n");
					break;
				}

				fprintf(fp, "%s %s", user_name, md5_encode(upass, strlen(upass)));

				fclose(fp);

				strcpy(uname, user_name);

				printf("\n修改用户名成功！\n");

				break;
			}

			case 2:
			{
				// 修改密码
				char pwd1[31], pwd2[31];
				
				strcpy(pwd1, getpass("\n请输入管理员密码："));

				if(strcmp(pwd1, upass))
				{
					printf("\n密码错误，修改失败！\n");
					break;
				}

				while(1)
				{
					strcpy(pwd1, getpass("\n请输入新密码："));
					strcpy(pwd2, getpass("\n请确认新密码："));

					if(strcmp(pwd1, pwd2))
					{
						printf("\n两次输入的密码不一样，请重新输入！\n");
					}
					else break;
				}
				

				FILE* fp = fopen("admin_info", "w");
				
				if(NULL == fp)
				{
					printf("写 admin_info 文件失败！\n");
					break;
				}

				strcpy(upass, pwd1);

				fprintf(fp, "%s %s", uname, md5_encode(upass, strlen(upass)));

				fclose(fp);

				printf("\n修改密码成功！\n");

				break;
			}

			default:
				printf("\n输入错误，请重新输入！\n");

		}
	}
}

/*
void ordinary_login(void)
{
	int i = 0, j = 0, k = 0;
	char* passwd;
	struct staff s;
	printf("欢迎登录\n");
	while(1)
	{
		if(k != 0)	system("clear");
		if(k != 0) printf("账号或密码错误,请重新输入！\n");
		k++;
			printf("请输入您的工号：");
			scanf("%d",&gh);
		//	printf("请输入密码：");
		//	scanf("%s",passwd);
			passwd = getpass("请输入您的密码：");
			
			FILE* fp = fopen("sta_data","rb");
			
			if(NULL == fp) return ;
			j++;
			while(1)
			{
				fread(&s, sizeof(s), 1 , fp);
			    if(feof(fp)) 
				{
					printf("账号或密码错误！\n");
					break ;	
				}
				if(s.Job_ID == gh)
				{
					if(strcmp(s.password, passwd) == 0) 
					{	
						i++;
						break;
					}
					else
					{
						printf("账号或密码错误！\n");
						break;
					}
				}

			}
		if(j>=3) 
		{
			system("clear");
			printf("账号或密码错误！\n");
			printf("您已经输入三次，强制退出本系统！\n");
			exit(0);
		}
		 fclose(fp);
		if(i != 0)	break;
	}
}


void sta_fiad(void)
{
	int i;
	struct staff s;
	FILE* fp = fopen("sta_data", "rb");
	if(NULL == fp) return ;
	
	while(1)
	{
		fread(&s, sizeof(s), 1, fp);
		if(s.Job_ID == gh)
		{
			printf("您的基本信息如下：\n");
			printf("工号：%d\n",s.Job_ID);
			printf("姓名：%s\n",s.name);
			printf("性别：%s\n",s.sex ==0 ? "男" : "女");
			printf("身份证号码：%s\n",s.ID);
			printf("电话：%s\n",s.Telephone);
			break;
		}	
	}	
	printf("\n");
	printf("\n返回上一级请按：0\n");
	scanf("%d",&i);
	system("clear");
}

void sta_mod_password(void)
{
	int i = 0, j = 0;char* sta_passwd;	
	char sta_passwd1[30], sta_passwd2[30];
	struct staff s;FILE* fp = fopen("sta_data","r+b");if(NULL == fp) return ;
	while(1)
	{
		sta_passwd = getpass("请输入您密码：");
		if(NULL == fp) return ;
		while(1)
		{
			fread(&s, sizeof(s), 1, fp);
			if(s.Job_ID == gh)
			{
				if(strcmp(s.password, sta_passwd) == 0)
				{
					strcpy(sta_passwd1, getpass("\n请输入新密码："));
					printf("%s\n",sta_passwd1);
					system("clear");
					strcpy(sta_passwd2, getpass("\n请确认新密码："));
					if(strcmp(sta_passwd1, sta_passwd2) == 0)
					{
						 printf("%s\n",sta_passwd1);
						 printf("%s\n",sta_passwd2);
						 strcpy(s.password, sta_passwd2);
						
						//	printf("%s",s.password);
							fseek(fp, -sizeof(s), SEEK_CUR);
							fwrite(&s, sizeof(s), 1, fp);
							printf("修改成功！");
							j++;
							break;
						
					}
					else
					{
						printf("两次密码不相同，请重新输入！\n");
						continue;
					}
					
				}
			
				else
				{
					printf("密码输入错误，");
					i++;
					break;
				}
			}	
		
			if(i >= 3) 
			{	
				system("clear");
				printf("您已经三次输入错误，本系统强行退出！\n");
				exit(0);
			}
		}	
		fclose(fp);
		if(j == 1) break;
	}
}*/	
