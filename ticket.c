/*控制电影票的函数*/
#include "all.h"
Ticket* Ticket_Creathead()
{
	Ticket *p = (Ticket*)malloc(sizeof(Ticket));
	p->next = NULL;
	return p;
}
void Ticket_CreatLink(Ticket *ticket_head)
{
	FILE *ticket_fp = fopen("Message/ticket.txt","a+");
	while(!feof(ticket_fp))
	{
		Ticket *p = (Ticket*)malloc(sizeof(Ticket));
		p->next = NULL;
		if(fscanf(ticket_fp,"%s %s %s %d %d %d %d %d %d %d %d %d %f %d\n",p->username,p->movie_name,p->screen_name,&(p->time)[0],&(p->time)[1],&(p->time)[2],&(p->stime)[0],&(p->stime)[1],&(p->etime)[0],&(p->etime)[1],&(p->myline),&(p->myrow),&(p->price),&(p->id))!=14)
		{
			free(p);
			break;
		}
		p->next = ticket_head->next;
		ticket_head->next = p;
	}
	fclose(ticket_fp);
}
void Ticket_Add(Ticket *ticket_head,char *username,char *movie_name,char *screen_name,int *_time,int *stime,int *etime,int myline,int myrow,float price,int seat_id)
{
	Ticket *p = (Ticket*)malloc(sizeof(Ticket));
	strcpy(p->username,username);
	strcpy(p->movie_name,movie_name);
	strcpy(p->screen_name,screen_name);
	(p->time)[0] = _time[0];
	(p->time)[1] = _time[1];
	(p->time)[2] = _time[2];
	(p->stime)[0] = stime[0];
	(p->stime)[1] = stime[1];
	(p->etime)[0] = etime[0];
	(p->etime)[1] = etime[1];
	p->myline = myline;
	p->myrow = myrow;
	p->price = price;
	p->id = time(NULL);
	p->next = ticket_head->next;
	ticket_head->next = p;
	Ticket_Save(ticket_head);
	Box *box_head = Box_Creathead();//增加票房
	Box_CreatLink(box_head);
	Box *q = Box_Find(box_head,movie_name);
	q->sum += q->price;
	Box_Save(box_head);
	Seat *seat_head = (Seat*)malloc(sizeof(Seat));//选座位
	seat_head->next = NULL;
	Seat_CreatLink(seat_head);
	Seat_Modify(seat_head,p->movie_name,p->screen_name,p->time,p->stime,myline,myrow,2);//锁定座位
	Seat_Save(seat_head);
}
void Ticket_Del(Ticket *ticket_head,int id)//顾客退票
{
	Ticket *m = ticket_head;
	Ticket *p = m->next;
	while(p)
	{
		if(p->id == id)
		{
			Seat *seat_head = (Seat*)malloc(sizeof(Seat));
			seat_head->next = NULL;
			Seat_CreatLink(seat_head);
			Seat_Modify(seat_head,p->movie_name,p->screen_name,p->time,p->stime,p->myline,p->myrow,1);//恢复座位
			Seat_Save(seat_head);
			Box *box_head = Box_Creathead();//减少票房
			Box_CreatLink(box_head);
			Box *q = Box_Find(box_head,p->movie_name);
			q->sum -= q->price;
			Box_Save(box_head);
			m->next = p->next;
			free(p);
			Ticket_Save(ticket_head);
			return;
		}
		m = p;
		p=p->next;
	}
}
void Ticket_Save(Ticket* ticket_head)
{
	FILE *ticket_fp = fopen("Message/ticket.txt","w+");
	Ticket *p = ticket_head->next;
	while(p)
	{
		fprintf(ticket_fp,"%s %s %s %d %d %d %d %d %d %d %d %d %f %d\n",p->username,p->movie_name,p->screen_name,(p->time)[0],(p->time)[1],(p->time)[2],(p->stime)[0],(p->stime)[1],(p->etime)[0],(p->etime)[1],(p->myline),(p->myrow),(p->price),(p->id));
		p=p->next;
	}
	fclose(ticket_fp);
}
void Ticket_Find(Ticket *ticket_head,char *username)
{
	Ticket *p = ticket_head->next;
	while(p)
	{
		if(strcmp(p->username,username)==0)
		{
			Ticket_Print(p);
		}
		p=p->next;
	}
}
int Ticket_FindId(Ticket *ticket_head,int id)
{
	Ticket *p = ticket_head->next;
	while(p)
	{
		if(p->id==id)
		{
			return 1;
		}
		p=p->next;
	}
	return 0;
}
void Ticket_DelAll_Movie(Ticket *ticket_head,char *movie_name)//删除所有有关电影票信息
{
	while(1)
	{
		Ticket *q = ticket_head;
		Ticket *p = q->next;
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
void Ticket_DelAll_Screen(Ticket *ticket_head,char *screen_name)
{
	while(1)
	{
		Ticket *q = ticket_head;
		Ticket *p = q->next;
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
void Ticket_Modify(Ticket *ticket_head,char *name,char *newname)//用于用户修改信息后票的转移
{
	Ticket *p = ticket_head->next;
	while(p)
	{
		if(strcmp(p->username,name)==0)
		{
			strcpy(p->username,newname);
		}
		p=p->next;
	}
}
void Ticket_Del_Seat(Ticket *ticket_head,char* movie_name,char* screen_name,int *_time,int *stime,int *etime)//减少排片后删除相关电影票
{
	while(1)
	{
		Ticket *q = ticket_head;
		Ticket *p = q->next;
		while(p)
		{
			if(strcmp(p->movie_name,movie_name)==0&&strcmp(p->screen_name,screen_name)==0&&(p->time)[0] == _time[0]&&(p->time)[1] == _time[1]&&(p->time)[2] == _time[2]&&(p->stime)[0] == stime[0]&&(p->stime)[1] == stime[1]&&(p->etime)[0] == etime[0]&&(p->etime)[1] == etime[1])
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
