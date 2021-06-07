/*控制邀请码的函数*/
#include "all.h"
Code *Code_Creathead()
{
	Code *p = (Code*)malloc(sizeof(Code));
	p->next = NULL;
	return p;
}
void Code_CreatLink(Code* code_head) //从文件中读之前的邀请码
{
	FILE *code_fp = fopen("Message/code.txt", "a+");
	int code, num;
	while (fscanf(code_fp,"%d %d\n",&code, &num) != EOF)
	{
		Code *p = (Code*)malloc(sizeof(Code));
		p->code = code;
		p->num = num;
		p->next = code_head->next;
		code_head->next = p;
	}
	fclose(code_fp);
}
int Code_Find(Code* code_head,int code)//寻找
{
	Code *p = code_head->next;
	while (p)
	{
		if (p->code == code)
		{
			return p->num; //返回该邀请码对应的权限
		}
		p = p->next;
	} //如果没有这个邀请码,返回权限为0
	return 0;
}
int Code_Add(Code* code_head,int num)
{
	Code *p = (Code*)malloc(sizeof(Code));
	p->code = time(NULL);
	p->num = num;
	p->next = code_head->next;
	code_head->next = p;
	return p->code;
}
void Code_Save(Code* code_head)
{
	FILE *code_fp = fopen("Message/code.txt", "w+");
	Code *p = code_head->next;
	while (p)
	{
		fprintf(code_fp, "%d %d\n", p->code, p->num);
		p=p->next;
	}
	fclose(code_fp);
}
