/*控制登录注册的页面*/
#include "all.h"
void Login() //登录
{
	system("cls");
	fflush(stdin);
	char name[15], passward[20];
	printf("请输入姓名:");
	In_Name(name,15);
	printf("请输入密码:");
	In_Passward(passward,15);
	putchar('\n');
	Person* person_head = Person_Creathead();
	Person_CreatLink(person_head);
	Person *p = Person_Find(person_head,name);
	if(!p)
	{
		printf("    用户名不存在\n");
		printf("输入1重新输入,0返回菜单\n");
		int n;
		scanf("%d",&n);
		if(n)
		{
			Login();
		}
	}
	else
	{
		if(strcmp(passward,p->password)==0)
		{
			Automatic_Del_Seat();
			InLogin(p->name);
			Port(p->num,name);
			OutLogin(p->name);
		}
		else
		{
			printf("密码或用户名不正确,请重新输入\n");
			printf("       任意键以继续\n");
			getch();
			Login();
		}
	}
}
void Register() //注册
{
	system("cls");
	fflush(stdin);
	int code,num,n;
	while(1)
	{
		printf("1.有邀请码 2.无邀请码\n");
		if(scanf("%d",&n)==1)
		{
			if(n == 1)
			{
				goto t1;
			}
			else if(n == 2)
			{
				num = 2;
				goto t2;
			}
		}
	}
t1:
	;
	system("cls");
	fflush(stdin);
	printf("请输入邀请码:");
	Code *code_head = Code_Creathead();
	Code_CreatLink(code_head);
	if(scanf("%d", &code)==1)
	{
		num = Code_Find(code_head,code);
		if(num == 0)
		{
			goto next;
		}
		else
		{
		t2:
			;
			system("cls");
			fflush(stdin);
			char name[15];
			while(1)
			{
				system("cls");
				printf("请输入姓名:");
				In_Name(name,15);
				Person *person_head = Person_Creathead();
				Person_CreatLink(person_head);
				if(!Person_Find(person_head,name))
				{
					char passward1[20],passward2[20];
					while(1)
					{
						printf("请输入密码:");
						In_Passward(passward1,20);
						putchar('\n');
						printf("请再次输入密码:");
						In_Passward(passward2,20);
						putchar('\n');
						if(strcmp(passward1,passward2)==0)
						{
							break;
						}
						else
						{
							system("cls");
							printf("两次输入不一致,请重新输入\n");
							printf("     任意键以继续\n");
							getch();
						}
					}
					Person_Add(person_head,name,passward1,num);
					Person_Save(person_head);
					printf("恭喜您注册成功,快去登录吧!\n");
					printf("     任意键以继续\n");
					getch();
					break;
				}
				else
				{
					system("cls");
					printf("该姓名已经被注册,请重新输入\n");
					printf("       任意键以继续\n");
					getch();
				}
			}
		}
	}
	else
	{
	next:
		;
		system("cls");
		fflush(stdin);
		printf("激活码输入有误\n重新输入请输入1,退出请输入0\n");
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			Register();
		}
	}
}
