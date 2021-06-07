/*控制人员信息的函数所在*/
#include "all.h"
Person* Person_Creathead()
{
	Person *p = (Person*)malloc(sizeof(Person));
	p->next = NULL;
	return p;
}
void Person_CreatLink(Person *person_head)
{
	FILE *person_fp = fopen("Message/person.txt", "a+");
	char name[15],passward[20];
	int num;
	while(fscanf(person_fp,"%s%s%d\n",name,passward,&num)!=EOF)
	{
		Person *p = (Person*)malloc(sizeof(Person));
		strcpy(p->name,name);
		strcpy(p->password,passward);
		p->num = num;
		p->next = person_head->next;
		person_head->next = p;
	}
	fclose(person_fp);
}
int Person_Add(Person *person_head,char *name,char *passward,int num)
{
	if(!Person_Find(person_head,name))
	{
		Person *p = (Person*)malloc(sizeof(Person));
		strcpy(p->name,name);
		strcpy(p->password,passward);
		p->num = num;
		p->next = person_head->next;
		person_head->next = p;
		return 1;
	}
	else
	{
		return 0;
	}
}
void Person_Del(Person *person_head,char *name)//删除用户信息
{
	Person *p,*q;
	q = person_head;
	p = q->next;
	while(p)
	{
		if(strcmp(p->name,name)==0)
		{
			q->next = p->next;
			free(p);
		}
		q = p;
		p=p->next;
	}
}
void Person_Modify(Person *p,char *newname,char *newpassward)//修改用户信息
{
	strcpy(p->name,newname);
	strcpy(p->password,newpassward);
}
Person* Person_Find(Person *person_head,char *name)
{
	Person *p = person_head->next;
	while(p)
	{
		if(strcmp(name,p->name) == 0)
		{
			return p;
		}
		p=p->next;
	}
	return NULL;
}
void Person_Save(Person *person_head)
{
	FILE *person_fp = fopen("Message/person.txt","w+");
	Person *p = person_head->next;
	while(p)
	{
		fprintf(person_fp,"%s %s %d\n",p->name,p->password,p->num);
		p=p->next;
	}
	fclose(person_fp);
}
