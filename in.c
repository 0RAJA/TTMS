/*控制输入的信息,输入姓名及密码的函数*/
#include<stdio.h>
#include<string.h>
#include<conio.h>
void In_Name(char *name,int Max)//输入姓名
{
	fflush(stdin);
	memset(name,'\0',sizeof(name));
	int i = 0;
	char c;
	while (c = getchar())
	{
		if (c == 8) //删除(修改之后这里似乎并无卵用)
		{
			if (i == 0)
			{
				continue;
			}
			printf("\b");
			printf(" ");
			printf("\b");
			i--;
		}
		else if (c == '\n') //回车
		{
			break;
		}
		else //普通输入
		{
			if (i == Max-1)
			{
				continue;
			}
			name[i++] = c;
		}
	}
	name[i] = '\0';
}
void In_Passward(char *passward,int Max)//输入密码
{
	fflush(stdin);
	memset(passward,'\0',sizeof(passward));
	int i = 0;
	while (1)
	{
		char c = getch();
		if (c == 8) //删除
		{
			if (i == 0)
			{
				continue;
			}
			printf("\b");
			printf(" ");
			printf("\b");
			i--;
		}
		else if (c == '\r') //回车
		{
			break;
		}
		else //普通输入
		{
			if (i == Max-1)
			{
				continue;
			}
			printf("*");//回显
			passward[i++] = c;
		}
	}
	passward[i] = '\0';
}
