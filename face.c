/*���Ƶ�¼ע���ҳ��*/
#include "all.h"
void Login() //��¼
{
	system("cls");
	fflush(stdin);
	char name[15], passward[20];
	printf("����������:");
	In_Name(name,15);
	printf("����������:");
	In_Passward(passward,15);
	putchar('\n');
	Person* person_head = Person_Creathead();
	Person_CreatLink(person_head);
	Person *p = Person_Find(person_head,name);
	if(!p)
	{
		printf("    �û���������\n");
		printf("����1��������,0���ز˵�\n");
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
			printf("������û�������ȷ,����������\n");
			printf("       ������Լ���\n");
			getch();
			Login();
		}
	}
}
void Register() //ע��
{
	system("cls");
	fflush(stdin);
	int code,num,n;
	while(1)
	{
		printf("1.�������� 2.��������\n");
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
	printf("������������:");
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
				printf("����������:");
				In_Name(name,15);
				Person *person_head = Person_Creathead();
				Person_CreatLink(person_head);
				if(!Person_Find(person_head,name))
				{
					char passward1[20],passward2[20];
					while(1)
					{
						printf("����������:");
						In_Passward(passward1,20);
						putchar('\n');
						printf("���ٴ���������:");
						In_Passward(passward2,20);
						putchar('\n');
						if(strcmp(passward1,passward2)==0)
						{
							break;
						}
						else
						{
							system("cls");
							printf("�������벻һ��,����������\n");
							printf("     ������Լ���\n");
							getch();
						}
					}
					Person_Add(person_head,name,passward1,num);
					Person_Save(person_head);
					printf("��ϲ��ע��ɹ�,��ȥ��¼��!\n");
					printf("     ������Լ���\n");
					getch();
					break;
				}
				else
				{
					system("cls");
					printf("�������Ѿ���ע��,����������\n");
					printf("       ������Լ���\n");
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
		printf("��������������\n��������������1,�˳�������0\n");
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			Register();
		}
	}
}
