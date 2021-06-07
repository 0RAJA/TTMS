/*控制座位的函数所在*/
#include "all.h"
Seat* Seat_Creathead()
{
	Seat *p = (Seat*)malloc(sizeof(Seat));
	p->next = NULL;
	return p;
}
void Seat_CreatLink(Seat *seat_head)
{
	FILE *seat_fp = fopen("Message/seat.txt","a+");
	char movie_name[15],screen_name[15];
	while(fscanf(seat_fp,"%s%s",movie_name,screen_name)==2)
	{
		Seat *p = (Seat*)malloc(sizeof(Seat));
		strcpy(p->movie_name,movie_name);
		strcpy(p->screen_name,screen_name);
		fscanf(seat_fp,"%d %d %d %d %d %d %d %d %d %d\n",&(p->line),&(p->row),&(p->time)[0],&(p->time)[1],&(p->time)[2],&(p->stime)[0],&(p->stime)[1],&(p->etime)[0],&(p->etime)[1],&(p->id));
		for(int i = 1; i<=p->line; i++)
		{
			for(int j = 1; j<=p->row; j++)
			{
				fscanf(seat_fp,"%d",&(p->seat)[i][j]);
			}
		}
		p->next = seat_head->next;
		seat_head->next = p;
	}
	fclose(seat_fp);
}
void Seat_Add(Seat *seat_head,char *movie_name,char *screen_name,Screen *screen,Movie *movie_p,int *_time,int *stime,int *etime)/*排片*/
{
	Seat* p =(Seat*)malloc(sizeof(Seat));
	strcpy(p->movie_name,movie_name);
	strcpy(p->screen_name,screen_name);
	(p->time)[0] = _time[0];
	(p->time)[1] = _time[1];
	(p->time)[2] = _time[2];
	(p->stime)[0] = stime[0];
	(p->stime)[1] = stime[1];
	(p->etime)[0] = etime[0];
	(p->etime)[1] = etime[1];
	p->line = screen->line;
	p->row = screen->row;
	p->id = time(NULL);
	for(int i = 1; i<=p->line; i++)
	{
		for(int j = 1; j<=p->row; j++)
		{
			(p->seat)[i][j] = (screen->seat)[i][j];//从影厅资料中读取数据
		}
	}
	p->next = seat_head->next;
	seat_head->next = p;
}
int Seat_FindMovie(Seat *seat_head,char *movie_name)//通过电影找场次
{
	int flag = 0;
	Seat *p = seat_head->next;
	while(p)
	{
		if(strcmp(p->movie_name,movie_name) == 0)
		{
			flag =1;
			Seat_Print(p);
		}
		p=p->next;
	}
	return flag;
}
void Seat_PrintAll(Seat *seat_head)
{
	Seat *p = seat_head->next;
	while(p)
	{
		Seat_Print(p);
		p=p->next;
	}
}
int Seat_Del(Seat *seat_head,int id)//减少场次
{
	Seat *q = seat_head;
	Seat *p = q->next;
	while(p)
	{
		if(p->id == id)
		{
			Ticket *ticket_head = Ticket_Creathead();
			Ticket_CreatLink(ticket_head);
			Ticket_Del_Seat(ticket_head,p->movie_name,p->screen_name,p->time,p->stime,p->etime);
			Ticket_Save(ticket_head);
			q->next = p->next;
			free(p);
			return 1;
		}
		q = p;
		p = p->next;
	}
	return 0;
}
void Seat_Save(Seat *seat_head)
{
	FILE *seat_fp = fopen("Message/seat.txt","w+");
	Seat *p = seat_head->next;
	while(p)
	{
		fprintf(seat_fp,"%s %s %d %d %d %d %d %d %d %d %d %d\n",p->movie_name,p->screen_name,p->line,p->row,(p->time)[0],(p->time)[1],(p->time)[2],(p->stime)[0],(p->stime)[1],(p->etime)[0],(p->etime)[1],p->id);
		for(int i = 1; i<=p->line; i++)
		{
			for(int j = 1; j<=p->row; j++)
			{
				fprintf(seat_fp,"%d ",(p->seat)[i][j]);
			}
			fputc('\n',seat_fp);
		}
		p=p->next;
	}
	fclose(seat_fp);
}
void Seat_Modify(Seat* seat_head,char *movie_name,char *screen_name,int *time,int *stime,int myline,int myrow,int num)
{
	Seat *p = seat_head->next;
	while(p)
	{
		if(strcmp(p->movie_name,movie_name)==0&&strcmp(p->screen_name,screen_name)==0&&(p->time)[0] == time[0]&&(p->time)[1] == time[1]&&(p->time)[2] == time[2]&&stime[0]==(p->stime)[0])
		{
			(p->seat)[myline][myrow] = num;
			return;
		}
		p=p->next;
	}
}
Seat *Seat_Findid(Seat *seat_head,int id)//通过id返回seat
{
	Seat *p = seat_head->next;
	while(p)
	{
		if(p->id==id)
		{
			return p;
		}
		p=p->next;
	}
	return NULL;
}
void Seat_DelAll_Movie(Seat* seat_head,char *movie_name)
{
	while(1)
	{
		Seat *q = seat_head;
		Seat *p = q->next;
		while(p)
		{
			if(strcmp(p->movie_name,movie_name)==0)
			{
				q->next = p->next;
				free(p);
				break;
			}
			q = p;
			p=p->next;
		}
		if(!p)
		{
			return;
		}
	}
}
void Seat_DelAll_Screen(Seat* seat_head,char *screen_name)
{
	while(1)
	{
		Seat *q = seat_head;
		Seat *p = q->next;
		while(p)
		{
			if(strcmp(p->screen_name,screen_name)==0)
			{
				q->next = p->next;
				free(p);
				break;
			}
			q = p;
			p=p->next;
		}
		if(!p)
		{
			return;
		}
	}
}
int Seat_IsTimeOk(Seat *seat_head,char *screen_name,int *_time,int *stime,int *etime)
{
	Seat *p = seat_head->next;
	while(p)
	{
		if(strcmp(screen_name,p->screen_name) == 0 && (p->time)[0] == _time[0]&&(p->time)[1] == _time[1] && (p->time)[2] == _time[2])//同影厅,同年月日 比较 时间
		{
			if(etime[0]<(p->stime)[0]||etime[0] ==(p->stime)[0]&&(p->stime)[1]-etime[1]>=20)
			{
				p=p->next;
				continue;
			}
			else if((p->etime)[0]<stime[0]||(p->etime)[0] == stime[0]&&stime[1]-(p->etime)[1]>=20)
			{
				p=p->next;
				continue;
			}
			return 0;
		}
		p=p->next;
	}
	return 1;
}
void Seat_FindOverTime(Seat *seat_head,int nowyear,int nowmonth,int nowday,int nowhour,int nowmin)
{
	while(1)
	{
		int flag = 0;
		Seat *q = seat_head;
		Seat *p = q->next;
		while(p)
		{
			if((p->time)[0]<nowyear)//年
			{
				flag = 1;
				break;
			}
			else if((p->time)[0] == nowyear)
			{
				if((p->time)[1]<nowmonth)//月
				{
					flag = 1;
					break;
				}
				else if((p->time)[1] == nowmonth)
				{
					if((p->time)[2]<nowday)//日
					{
						flag = 1;
						break;
					}
					else if((p->time)[2] == nowday)
					{
						if((p->etime)[0]<nowhour)//小时
						{
							flag = 1;
							break;
						}
						else if((p->etime)[0] == nowhour)
						{
							if((p->etime)[1]<=nowmin)//分钟
							{
								flag = 1;
								break;
							}
						}
					}
				}
			}
			q = p;
			p=p->next;
		}
		if(flag)
		{
			Seat_Del(seat_head,p->id);
		}
		if(!p)
		{
			return;
		}
	}
}
