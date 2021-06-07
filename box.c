/*控制票房的函数所在*/
#include "all.h"
Box *Box_Creathead()
{
	Box *p =(Box*)malloc(sizeof(Box));
	p->next = NULL;
	p->prev =NULL;
	return p;
}
void Box_CreatLink(Box *box_head)
{
	FILE *box_fp = fopen("Message/box.txt","a+");
	while(!feof(box_fp))
	{
		Box *p = (Box*)malloc(sizeof(Box));
		p->next = NULL;
		p->prev = NULL;
		if(fscanf(box_fp,"%s %f %lf\n",p->movie_name,&(p->price),&(p->sum))!=3)
		{
			free(p);
			break;
		}
		if(box_head->next)
		{
			box_head->next->prev = p;
		}
		p->next = box_head->next;
		box_head->next = p;
		p->prev = box_head;
	}
	fclose(box_fp);
}
void Box_Add(Box *box_head,char *movie_name,float price, double sum)
{
	Box *p = (Box*)malloc(sizeof(Box));
	p->next = p->prev = NULL;
	if(box_head->next)
	{
		box_head->next->prev = p;
	}
	p->next = box_head->next;
	box_head->next = p;
	p->prev = box_head;
	strcpy(p->movie_name,movie_name);
	p->price = price;
	p->sum = 0;
}
void Box_Del(Box *box_head,char *movie_name)
{
	Box *p = Box_Find(box_head,movie_name);
	if(p)
	{
		p->prev->next = p->next;
		if(p->next)
		{
			p->next->prev = p->prev;
		}
		free(p);
	}
}
Box* Box_Find(Box *box_head,char *movie_name)
{
	Box *p = box_head->next;
	while(p)
	{
		if(strcmp(p->movie_name,movie_name)==0)
		{
			return p;
		}
		p=p->next;
	}
	return NULL;
}
void Box_Replace(Box *p,Box *m)//交换
{
	char movie_name[15];
	float price;
	double sum;
	strcpy(movie_name,m->movie_name);
	price = m->price;
	sum = m->sum;
	strcpy(m->movie_name,p->movie_name);
	m->price = p->price;
	m->sum = p->sum;
	strcpy(p->movie_name,movie_name);
	p->price = price;
	p->sum = sum;
}
void Box_Sort(Box *low,int flag)//1是降序,0是升序
{
	Box *i,*j;
	for(i=low; i; i=i->next)
	{
		for(j=i->next; j; j=j->next)
		{
			if(flag)
			{
				if(i->sum<j->sum)
				{
					Box_Replace(i,j);
				}
			}
			else
			{
				if(i->sum>j->sum)
				{
					Box_Replace(i,j);
				}
			}

		}
	}
}
void Box_Save(Box *box_head)
{
	FILE *box_fp = fopen("Message/box.txt","w+");
	Box *p = box_head->next;
	while(p)
	{
		fprintf(box_fp,"%s %f %lf\n",p->movie_name,p->price,p->sum);
		p=p->next;
	}
	fclose(box_fp);
}
