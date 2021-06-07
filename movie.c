/*控制电影的函数所在*/
#include "all.h"
int Movie_IsTimeLegal(int year,int month,int day)
{
	struct tm *p;
	time_t timep = time(NULL)+8*60*60;//北京时间
	p = gmtime(&timep);
	int nowyear,nowmon,nowday;
	nowyear = p->tm_year+1900;
	nowmon = p->tm_mon+1;
	nowday = p->tm_mday;
	return IsTimeLegal(year,month,day,nowyear,nowmon,nowday);
}
Movie* Movie_Creathead()/*创建空头*/
{
	Movie *p = (Movie*)malloc(sizeof(Movie));
	p->next = NULL;
	return p;
}
void Movie_CreatLink(Movie *movie_head)/*读文件*/
{
	FILE *movie_fp = fopen("Message/movie.txt","a+");
	char name[15],dir[15],star[15],label[10],where[15],lang[15],intro[250];
	int stime[3];
	float price;
	int mins;
	while(fscanf(movie_fp,"%s %s %s %s %s %s %d %d %d %s %f %d\n",name,dir,star,label,where,lang,&stime[0],&stime[1],&stime[2],intro,&price,&mins)!=EOF)/*读取年月日*/
	{
		Movie *p = (Movie*)malloc(sizeof(Movie));
		strcpy(p->name,name);
		strcpy(p->dir,dir);
		strcpy(p->star,star);
		strcpy(p->label,label);
		strcpy(p->where,where);
		strcpy(p->lang,lang);
		(p->stime)[0] = stime[0];
		(p->stime)[1] = stime[1];
		(p->stime)[2] = stime[2];
		strcpy(p->intro,intro);
		p->price = price;
		p->mins = mins;
		p->next = movie_head->next;
		movie_head->next = p;
	}
	fclose(movie_fp);
}
int Movie_Add(Movie *movie_head,char *name,char* dir,char *star,char *label,char *where,char *lang,int *stime,char *intro,float price,int mins)
{
	if(!Movie_Find(movie_head,name))
	{
		Movie *p = (Movie*)malloc(sizeof(Movie));
		strcpy(p->name,name);
		strcpy(p->dir,dir);
		strcpy(p->star,star);
		strcpy(p->label,label);
		strcpy(p->where,where);
		strcpy(p->lang,lang);
		(p->stime)[0] = stime[0];
		(p->stime)[1] = stime[1];
		(p->stime)[2] = stime[2];
		strcpy(p->intro,intro);
		p->price = price;
		p->mins = mins;
		p->next = movie_head->next;
		movie_head->next = p;
		return 1;
	}
	else
	{
		return 0;
	}
}
Movie* Movie_Find(Movie *movie_head,char *name)
{
	Movie *p = movie_head->next;
	while(p)
	{
		if(strcmp(name,p->name)==0)
		{
			return p;
		}
		p=p->next;
	}
	return NULL;
}
void Movie_Save(Movie *movie_head)
{
	FILE *movie_fp = fopen("Message/movie.txt","w+");
	Movie *p = movie_head->next;
	while(p)
	{
		fprintf(movie_fp,"%s %s %s %s %s %s %d %d %d %s %.2f %d\n",p->name,p->dir,p->star,p->label,p->where,p->lang,(p->stime)[0],(p->stime)[1],(p->stime)[2],p->intro,p->price,p->mins);
		p = p->next;
	}
	fclose(movie_fp);
}
void Movie_Del(Movie *movie_head,char *name)
{
	Movie *q = movie_head;
	Movie *p = q->next;
	while(p)
	{
		if(strcmp(p->name,name) == 0)
		{
			Box *box_head = Box_Creathead();
			Box_CreatLink(box_head);
			Box_Del(box_head,p->name);//删除票房
			Box_Save(box_head);
			Ticket *ticket_head  =Ticket_Creathead();
			Ticket_CreatLink(ticket_head);
			Ticket_DelAll_Movie(ticket_head,name);//删除票
			Ticket_Save(ticket_head);
			Seat *seat_head = (Seat*)malloc(sizeof(Seat));
			seat_head->next = NULL;
			Seat_CreatLink(seat_head);
			Seat_DelAll_Movie(seat_head,name);
			Seat_Save(seat_head);//删除座位
			q->next = p->next;//删除电影
			free(p);
			return;
		}
		q = p;
		p=p->next;
	}
}
int Movie_FindMo(Movie *movie_head,char *movie_name)//模糊查询
{
	int flag = 0;
	Movie *p = movie_head->next;
	while(p)
	{
		if(_strcmp(p->name,movie_name)>=1)
		{
			flag = 1;
			Movie_PrintOne(p);
		}
		p=p->next;
	}
	return flag;
}
void Movie_Modify(Movie *movie_head,Movie *p,float price,char *intro)//修改电影信息
{
	if(price!=-1)
	{
		p->price = price;
		Box *box_head = Box_Creathead();
		Box_CreatLink(box_head);
		Box *box_p = Box_Find(box_head,(p->name));
		box_p->price = price;
		Box_Save(box_head);
	}
	if(intro)
	{
		strcpy(p->intro,intro);
	}
	Movie_Save(movie_head);
}
