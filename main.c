/*********************************************
@File name : TTMS.dev 
@Author : Raja
@Version : 1.0
@Date : 2021-3-20
@Description : ��c����ʵ��ӰԺ����ϵͳ 
********************************************/
/*���Ƴ����ʼ�Ľ���*/
#include "all.h"
int main()
{
	while (1)
	{
		system("cls");
		int n = 0;
		printf("           ��ӭ������ӰԺ\n");
		printf("------------------------------------\n"
		       "------------------------------------\n"
		       "||            1.��¼              ||\n"
		       "||            2.ע��              ||\n"
		       "||            3.�뿪              ||\n"
		       "------------------------------------\n"
		       "------------------------------------\n");
		printf("            ������ѡ��:");
		scanf("%d", &n);
		if (n == 3)//�˳�
		{
			system("cls");
			fflush(stdin);
			printf("��Ԫ˳:����˧!\n");
			getch();
			break;
		}
		else if (n == 1)//��¼
			Login();
		else if (n == 2)//ע��
			Register();
		else
		{
			system("cls");
			fflush(stdin);
			printf("������Ч,����������\n");
			printf(" ������Լ���\n");
			getch();
		}
	}
	return 0;
}
