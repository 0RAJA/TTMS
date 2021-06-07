/*********************************************
@File name : TTMS.dev 
@Author : Raja
@Version : 1.0
@Date : 2021-3-20
@Description : 用c语言实现影院管理系统 
********************************************/
/*控制程序最开始的界面*/
#include "all.h"
int main()
{
	while (1)
	{
		system("cls");
		int n = 0;
		printf("           欢迎来到电影院\n");
		printf("------------------------------------\n"
		       "------------------------------------\n"
		       "||            1.登录              ||\n"
		       "||            2.注册              ||\n"
		       "||            3.离开              ||\n"
		       "------------------------------------\n"
		       "------------------------------------\n");
		printf("            请输入选项:");
		scanf("%d", &n);
		if (n == 3)//退出
		{
			system("cls");
			fflush(stdin);
			printf("顾元顺:我最帅!\n");
			getch();
			break;
		}
		else if (n == 1)//登录
			Login();
		else if (n == 2)//注册
			Register();
		else
		{
			system("cls");
			fflush(stdin);
			printf("输入无效,请重新输入\n");
			printf(" 任意键以继续\n");
			getch();
		}
	}
	return 0;
}
