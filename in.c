/*�����������Ϣ,��������������ĺ���*/
#include<stdio.h>
#include<string.h>
#include<conio.h>
void In_Name(char *name,int Max)//��������
{
	fflush(stdin);
	memset(name,'\0',sizeof(name));
	int i = 0;
	char c;
	while (c = getchar())
	{
		if (c == 8) //ɾ��(�޸�֮�������ƺ���������)
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
		else if (c == '\n') //�س�
		{
			break;
		}
		else //��ͨ����
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
void In_Passward(char *passward,int Max)//��������
{
	fflush(stdin);
	memset(passward,'\0',sizeof(passward));
	int i = 0;
	while (1)
	{
		char c = getch();
		if (c == 8) //ɾ��
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
		else if (c == '\r') //�س�
		{
			break;
		}
		else //��ͨ����
		{
			if (i == Max-1)
			{
				continue;
			}
			printf("*");//����
			passward[i++] = c;
		}
	}
	passward[i] = '\0';
}
