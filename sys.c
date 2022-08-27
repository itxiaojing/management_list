#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys.h"
void mam_sys_menu2(void);
static void mam_sys_menu3(void);
void menu_con_find(void);


void mam_sys_menu1(void)
{
	printf("\n\t\t\t\t\t***********欢迎使用本系统***************\n");
	printf("\t\t\t\t\t\t管理员登录请输入：1\n");
	printf("\t\t\t\t\t\t其它用户登录请输入：2\n");
	printf("\t\t\t\t\t\t退出本系统请输入：0\n");
	printf("\t\t\t\t\t*****************************************\n");
}


void mam_sys_menu2(void)
{
//	system("clear");
	printf("\n\t\t\t\t\t**********您以进入管理员界面**************\n");
	printf("\n\t\t\t\t\t\t修改自己用户和密码请输入：1\n");
	printf("\n\t\t\t\t\t\t添加普通用户的信息请输入：2\n");
	printf("\n\t\t\t\t\t\t查找普通用户关信息请输入：3\n");
	printf("\n\t\t\t\t\t\t删除普通用户相关信息请输入：4\n");
	printf("\n\t\t\t\t\t\t修改普通用户相关信息请输入：5\n");
	printf("\n\t\t\t\t\t\t添加物资的信息请输入：6\n");
	printf("\n\t\t\t\t\t\t查找物资的信息请输入：7\n");
	printf("\n\t\t\t\t\t\t删除物资的信息请输入：8\n");
	printf("\n\t\t\t\t\t\t修改物资的信息请输入：9\n");
	printf("\n\t\t\t\t\t\t退出本系统请输入：0\n");
	printf("\t\t\t\t\t*****************************************\n");
}


//管理员登录界面
void menu1(void)
{
	system("clear");
	mam_sys_menu2();

	while(1)
	{
		int menu1;
		do                          
        {
            printf(">");
            scanf("%d",&menu1);
            while(getchar() != '\n');
            if(menu1 > 9 || menu1 < 0) printf("Input error\n");
        }while(menu1 > 9 || menu1 < 0);
		switch(menu1)
		{
	case 0:
			system("clear");
			printf("感谢您的使用，下次再见！\n");
			write_infor(l,m,k);
			exit(0);
			break;
		
	case 1:
			system("clear");
			modify_admin_info();
			mam_sys_menu2();
			break;
			
	case 2:
			system("clear");
			push_back(l, tianjia());
			mam_sys_menu2();
			break;	
	case 3:
			system("clear");
			if(!find(l, dle()))  printf("无此人\n");
			mam_sys_menu2();
			break;
	
	case 4:
			system("clear");
			if(!remove_list(l, dle())) printf("无此人\n");
			else printf("删除成功\n");
			mam_sys_menu2();
			break;

	case 5:
			system("clear");
//			adm_sta_modify();
			if(!updata(l, dle())) printf("无此人\n");
			else printf("修改成功\n");
			mam_sys_menu2();
			break;

	case 6:
			system("clear");
//			adm_con_add();
			mat_push_back(m, mat_tianjia());
			printf("添加成功\n");
			mam_sys_menu2();
			break;
			
	case 7:
			system("clear");
			if(!mat_find(m, mat_dle()))  printf("没有该物资\n");
			mam_sys_menu2();
			break;
		
	case 8:
			system("clear");
			if(!mat_remove_list(m, mat_dle())) printf("无此人\n");
			else printf("删除成功\n");

			mam_sys_menu2();
			break;

	case 9:
			system("clear");
			if(!mat_updata(m, mat_dle())) printf("无此人\n");
			else printf("修改成功\n");
//			use_push_back(k,m, use_tianjia());
			mam_sys_menu2();
			break;
		}
		
	}
}

static void mam_sys_menu3(void)
{
	printf("\n\t\t\t\t\t*********您以进入普通用户界面**************\n");
	printf("\t\t\t\t\t\t修改自己用户密码请输入：1\n");
	printf("\t\t\t\t\t\t借出物资请输入：2\n");
	printf("\t\t\t\t\t\t归还物资请输入：3\n");
	printf("\t\t\t\t\t\t查看物资借还记录请输入：4\n");
	printf("\t\t\t\t\t\t查看本人相关信息请输入：5\n");
	printf("\t\t\t\t\t\t退出本系统请输入0\n");
}

//普通用户登录界面
void menu2(void)
{
	mam_sys_menu3();

	while(1)
	{
		int menu2;
		do
        {
            printf(">");
            scanf("%d",&menu2);
            while(getchar() != '\n');
            if(menu2 > 5 || menu2 < 0)  printf("Input error\n");
        }while(menu2 > 5 || menu2 < 0);
		switch(menu2)
		{
	case 0:
			printf("感谢您的使用，下次再见！\n");
			write_infor(l,m,k);
			exit(0);
			break;
		
	case 1:
			system("clear");
			sta_mod_password(l);
			mam_sys_menu3();
			break;
			
	case 2:
			system("clear");
			use_push_back(k,m,l, use_tianjia());
			mam_sys_menu3();
			break;	
	case 3:
			system("clear");
			if(!use_updata(m, k, use_dle())) printf("物资不存在或输入有误！！！\n");
			mam_sys_menu3();
			break;
	case 4:
			system("clear");
			if(!use_find(k, dle())) printf("输入错误或没有借出此物资\n");
			mam_sys_menu3();
			break;
	case 5:
			system("clear");
			sta_fiad(l);
			mam_sys_menu3();
			break;
		}
	}
}	
