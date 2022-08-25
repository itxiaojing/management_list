#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys.h"
void mam_sys_menu2(void);
void mam_sys_menu3(void);
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
			if(!mat_find(m, mat_dle()))  printf("无此人\n");
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
			mam_sys_menu2();
			break;
		}
		
	}
}

void menu_con_find(void)
{
	printf("\n**********您以查找联系人界面**************\n");
	printf("按姓名查找请输入：1\n");
	printf("按电话查找请输入：2\n");
	printf("按邮箱查找请输入：3\n");
	printf("按备注查找请输入：4\n");
	printf("按分组查找请输入：5\n");
	printf("退出本系统请输入：0\n");
}

void menu_con_find1(void)
{
	while(1)
	{
		int menu;
		menu_con_find();
		 do
        {
            printf(">");
            scanf("%d",&menu);
            while(getchar() != '\n');
            if(menu > 5 || menu < 0) printf("Input error\n");
        }while(menu > 5 || menu < 0);
		switch(menu)
		{
	case 0:
			printf("感谢您的使用，下次再见！\n");
			exit(0);
			break;
		
	case 1:
//			adm_con_find();
		//	menu_con_find();
			break;
			
	case 2:
//			adm_con_find1();
		//	menu_con_find();		
			break;	
	case 3:
//			adm_con_find2();
		//	menu_con_find();
			break;
	
	case 4:
//			adm_con_find3();
		//	menu_con_find();
			break;
	case 5:
//			adm_con_find4();
		//	menu_con_find();
			break;		
		}
	}
}

void menu_sta_find(void)
{
	printf("\n**********您以查找员工界面**************\n");
	printf("按工号查找请输入：1\n");
	printf("按名字查找请输入：2\n");
	printf("身份证号查找输入：3\n");
	printf("按电话查找请输入：4\n");
	printf("退出本系统请输入：0\n");
}
void menu_sta_finds(void)
{
	while(1)
	{
		int menu;
		menu_sta_find();
		 do
        {
            printf(">");
            scanf("%d",&menu);
            while(getchar() != '\n');
            if(menu > 4 || menu < 0) printf("Input error\n");
        }while(menu > 4 || menu < 0);
		switch(menu)
		{
	case 0:
			printf("感谢您的使用，下次再见！\n");
			exit(0);
			break;
		
	case 1:
//			adm_sta_find();
		//	menu_con_find();
			break;
			
	case 2:
//			adm_sta_find1();
		//	menu_con_find();		
			break;	
	case 3:
//			adm_sta_find2();
		//	menu_con_find();
			break;
	
	case 4:
//			adm_sta_find3();
		//	menu_con_find();
			break;
		}
	}
}

void mam_sys_menu3(void)
{
	printf("\n\t\t\t\t\t*********您以进入普通用户界面**************\n");
	printf("\t\t\t\t\t\t修改自己用户密码请输入：1\n");
	printf("\t\t\t\t\t\t查找自己相关信息请输入：2\n");
	printf("\t\t\t\t\t\t查找联系人的信息请输入：3\n");
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
            if(menu2 > 3 || menu2 < 0)  printf("Input error\n");
        }while(menu2 > 3 || menu2 < 0);
		switch(menu2)
		{
	case 0:
			printf("感谢您的使用，下次再见！\n");
			exit(0);
			break;
		
	case 1:
			system("clear");
//			sta_mod_password();
			mam_sys_menu3();
			break;
			
	case 2:
			system("clear");
//			sta_fiad();
			mam_sys_menu3();
			break;	
	case 3:
			system("clear");
//			menu_con_find1();		
			mam_sys_menu3();
			break;
		}
	}
}
