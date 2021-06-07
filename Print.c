/*���������Print������,���忴ǰ׺*/
#include "all.h"
int Code_Print(Code* code_head)
{
	Code *p = code_head->next;
	if (!p)
	{
		printf("��������\n");
		return 0;
	}
	else
	{
		printf("������             Ȩ��\n");
	}
	while (p)
	{
		printf("%-15d%5d\n", p->code, p->num);
		p = p->next;
	}
	return 1;
}
void Movie_Print(Movie *movie_head)
{
	Movie *p = movie_head->next;
	while(p)
	{
		printf(
		    "��Ӱ��:%-15s\n"
		    "  ����:%-15s     ����:%-15s\n"
		    "  ��ǩ:%-15s     ����:%-15s  ����:%-10s\n"
		    "  ��ӳʱ��:%4d-%2d-%2d      �ۼ�:%.2fԪ\t ʱ��:%2d����\n"
		    "  ���:%-100s\n",p->name,p->dir,p->star,p->label,p->where,p->lang,(p->stime)[0],(p->stime)[1],(p->stime)[2],p->price,p->mins,p->intro);
		p=p->next;
	}
}
int Movie_Creat(Movie* movie_head,int flag)//flag��0�Ͳ������ظ���
{
	char movie_name[15],dir[15],star[15],label[10],where[15],lang[15],intro[250];
	int stime[3];
	int mins;
	float price;
	printf("�������Ӱ��\n");
	In_Name(movie_name,15);
	if(flag&&Movie_Find(movie_head,movie_name))
	{
		return 0;
	}
	printf("�����뵼����\n");
	In_Name(dir,15);
	printf("����������\n");
	In_Name(star,15);
	printf("�������Ӱ��ǩ\n");
	In_Name(label,10);
	printf("�������Ӱ����\n");
	In_Name(where,15);
	printf("�������Ӱ����\n");
	In_Name(lang,15);
	while(1)
	{
		fflush(stdin);
		printf("��������ӳʱ��(��2002-3-26)\n");
		if(scanf("%d-%d-%d",&stime[0],&stime[1],&stime[2])==3 &&Movie_IsTimeLegal(stime[0],stime[1],stime[2]))//���ﻹҪ�ж��º͵�ǰϵͳʱ����Ⱥ�
		{
			break;
		}
		else
		{
			printf("������ӳʱ����������,����������\n");
			printf("       ���������\n");
			getch();
		}
	}
	printf("�������Ӱ���\n");
	In_Name(intro,100);
	while(1)
	{
		fflush(stdin);
		printf("������Ʊ��(Ԫ)\n");
		if(scanf("%f",&price)==1)
		{
			break;
		}
		printf("��������,����������\n");
	}
	while(1)
	{
		fflush(stdin);
		printf("�������Ӱ������\n");
		if(scanf("%d",&mins)==1&&mins>0)
		{
			break;
		}
		printf("��������,����������\n");
	}
	Movie_Add(movie_head,movie_name,dir,star,label,where,lang,stime,intro,price,mins);
	Box *box_head= Box_Creathead();
	Box_CreatLink(box_head);
	Box_Add(box_head,movie_name,price,0);
	Box_Save(box_head);
	return 1;
}
void Movie_PrintOne(Movie *p)//չʾһ��
{
	printf(
	    "��Ӱ��:%-15s\n"
	    "  ����:%-15s     ����:%-15s\n"
	    "  ��ǩ:%-15s     ����:%-15s  ����:%-10s\n"
	    "  ��ӳʱ��:%4d-%2d-%2d      �ۼ�:%.2fԪ\t ʱ��:%2d����\n"
	    "  ���:%-100s\n",p->name,p->dir,p->star,p->label,p->where,p->lang,(p->stime)[0],(p->stime)[1],(p->stime)[2],p->price,p->mins,p->intro);
}
void Person_Print(Person *person_head)
{
	Person *p = person_head->next;
	printf("�û���\t       ����\t\t Ȩ��\n");
	while(p)
	{
		printf("%-15s%-20s%-5d\n",p->name,p->password,p->num);
		p=p->next;
	}
}
int Screen_Creat(Screen *screen_head,int flag)
{
	char name[15];
	int seat[100][100];
	int line,row;
	printf("������Ӱ����\n");
	In_Name(name,15);
	if(flag&&Screen_Find(screen_head,name))//flagΪ1��Ѱ������
	{
		return 0;
	}
	while(1)
	{
		fflush(stdin);
		printf("��������λ����\n");
		if(scanf("%d",&line)==1)
		{
			break;
		}
		printf("��������,����������\n");
	}
	while(1)
	{
		fflush(stdin);
		printf("��������λ����\n");
		if(scanf("%d",&row)==1)
		{
			break;
		}
		printf("��������,����������\n");
	}
	fflush(stdin);
	for(int i = 1; i<=line; i++)
	{
		for(int j = 1; j<=row; j++)
		{
			seat[i][j]=1;
		}
	}
	Screen_Add(screen_head,name,line,row,seat);
	Screen_Save(screen_head);
	return 1;
}
void Screen_Print(Screen* screen_head)//���е�
{
	Screen *p = screen_head->next;
	while(p)
	{
		printf(
		    "Ӱ����:%s\t����:%d ����:%d\n",p->name,p->line,p->row
		);
		for(int i = 1; i<=p->line; i++)
		{
			for(int j = 1; j<=p->row; j++)
			{
				int x = (p->seat)[i][j];
				if(x==1)
				{
					printf("�� ");
				}
				if(x==3)
				{
					printf("�� ");
				}
			}
			putchar('\n');
		}
		p=p->next;
	}
}
void Seat_Print(Seat *p)//����Ա�˲鿴����
{
	printf("%-15s%-15s %4d-%2d-%2d  ",p->movie_name,p->screen_name,(p->time)[0],(p->time)[1],(p->time)[2]);
	printf("%02d:%02d",(p->stime)[0],(p->stime)[1]);
	printf("    ");
	printf("%02d:%02d",(p->etime)[0],(p->etime)[1]);
	printf("   ");
	printf("%d\n",p->id);
}
int Seat_Print_seat(Seat *p)//�˿Ͳ鿴��λ
{
	Seat_Print(p);
	for(int i = 1; i<=p->line; i++)
	{
		for(int j = 1; j<=p->row; j++)
		{
			if((p->seat)[i][j]==1)
			{
				printf("�� ");
			}
			else if((p->seat)[i][j]==2)
			{
				printf("�� ");
			}
			else
			{
				printf("�� ");
			}
		}
		putchar('\n');
	}
	return 0;
}
void Ticket_Print(Ticket *p)
{
	printf("%-15s %-15s %-15s%4d-%2d-%2d ",p->username,p->movie_name,p->screen_name,(p->time)[0],(p->time)[1],(p->time)[2]);
	printf("%02d:%02d",(p->stime)[0],(p->stime)[1]);
	printf("    ");
	printf("%02d:%02d",(p->etime)[0],(p->etime)[1]);
	printf("   ");
	printf("   %-2d %-2d   %.2fԪ  %d\n",p->myline,p->myrow,p->price,p->id);
}
void Box_Print(Box *box_head)
{
	Box *p = box_head->next;
	while(p)
	{
		printf("%-15s  %.1fԪ\n",p->movie_name,p->sum);
		p=p->next;
	}
}
