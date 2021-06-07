/*控制影厅的函数所在*/
#include "all.h"
Screen *Screen_Creathead()
{
	Screen *p =(Screen*)malloc(sizeof(Screen));
	p->next = NULL;
	return p;
}
void Screen_CreatLink(Screen *screen_head)
{
	FILE *screen_fp = fopen("Message/Screen.txt","a+");
	char name[15];
	int seat[100][100];
	while(fscanf(screen_fp,"%s",name)!=EOF)
	{
		Screen *p = (Screen*)malloc(sizeof(Screen));
		strcpy(p->name,name);
		fscanf(screen_fp,"%d%d\n",&(p->line),&(p->row));
		for(int i = 1; i<=p->line; i++)
		{
			for(int j = 1; j<=p->row; j++)
			{
				fscanf(screen_fp,"%d",&((p->seat)[i][j]));
			}
		}
		p->next = screen_head->next;
		screen_head->next = p;
	}
	fclose(screen_fp);
}
int Screen_Add(Screen *screen_head,char *name,int line,int row,int seat[][100])
{
	if(!Screen_Find(screen_head,name))
	{
		Screen *p =(Screen*)malloc(sizeof(Screen));
		strcpy(p->name,name);
		p->line = line;
		p->row = row;
		for(int i = 1; i<=line; i++)
		{
			for(int j = 1; j<=row; j++)
			{
				(p->seat)[i][j] = seat[i][j];
			}
		}
		p->next = screen_head->next;
		screen_head->next = p;
		return 1;
	}
	else
	{
		return 0;
	}
}
Screen* Screen_Find(Screen *screen_head,char *name)
{
	Screen *p = screen_head->next;
	while(p)
	{
		if(strcmp(p->name,name)==0)
		{
			return p;
		}
		p=p->next;
	}
	return NULL;
}
void Screen_Del(Screen *screen_head,char *screen_name)
{
	Screen* q = screen_head;
	Screen *p = q->next;
	while(p)
	{
		if(strcmp(p->name,screen_name)==0)
		{
			Ticket *ticket_head  =Ticket_Creathead();
			Ticket_CreatLink(ticket_head);
			Ticket_DelAll_Screen(ticket_head,screen_name);//删除票
			Ticket_Save(ticket_head);
			Seat *seat_head = (Seat*)malloc(sizeof(Seat));
			seat_head->next = NULL;
			Seat_CreatLink(seat_head);
			Seat_DelAll_Screen(seat_head,screen_name);//删除座位
			Seat_Save(seat_head);
			q->next = p->next;//删除影厅
			free(p);
			return;
		}
		q=p;
		p=p->next;
	}
}
void Screen_Save(Screen *screen_head)
{
	FILE *screen_fp = fopen("Message/screen.txt","w+");
	Screen *p = screen_head->next;
	while(p)
	{
		fprintf(screen_fp,"%s %d %d\n",p->name,p->line,p->row);
		for(int i = 1; i<=p->line; i++)
		{
			for(int j = 1; j<=p->row; j++)
			{
				fprintf(screen_fp,"%d ",(p->seat)[i][j]);
			}
			fputc('\n',screen_fp);
		}
		p=p->next;
	}
	fclose(screen_fp);
}
void Screen_Modify(Screen *p,int line,int row,int num)
{
	(p->seat)[line][row] = num;
}
