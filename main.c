#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys.h"


int main()
{
	system("clear");
	int op; 
	l = create();
	m = mat_create();
	k =	use_create();
	read_infor(l, m, k);

	mam_sys_menu1();
	while(1)
	{
		do
		{
			printf(">");
			scanf("%d",&op);
			while(getchar() != '\n');
			if(op > 2 || op < 0) printf("Input error\n");
		}while(op > 2 || op < 0);
		switch(op)
		{
			case 0:
			printf("感谢您的使用，下次再见！\n");
			exit(0);
			break;
			
			case 1:
			system("clear");
			user_login();
//			adm_password();
			menu1();//管理员登录界面函数
			break;
			
			case 2:
			system("clear");
			ordinary_login(l);
			system("clear");
			menu2();//普通用户登录界面函数
			break ;
			
		}

	}
	return 0;
}
