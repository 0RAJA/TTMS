/*���Ƶ�¼��¼�ĺ���*/
#include "all.h"
void InLogin(char *name)//��¼��¼����
{
	FILE *time_fp = fopen("Message/login-record.txt","a+");
	struct tm *p;
	time_t timep = time(NULL)+8*60*60;//����ʱ��
	p = gmtime(&timep);
	fprintf(time_fp,"%-15s %-4d.%-2d.%-2d  %-2d:%-2d:%-2d  %-5s\n",name,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec,"IN");
	fclose(time_fp);
}
void OutLogin(char *name)//��¼�뿪����
{
	FILE *time_fp = fopen("Message/login-record.txt","a+");
	struct tm *p;
	time_t timep = time(NULL)+8*60*60;//����ʱ��
	p = gmtime(&timep);
	fprintf(time_fp,"%-15s %-4d.%-2d.%-2d  %-2d:%-2d:%-2d  %-5s\n",name,1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec,"OUT");
	fclose(time_fp);
}
void CheckLogin()//�������
{
	FILE *check_fp = fopen("Message/login-record.txt","a+");
	while(!feof(check_fp))
	{
		char c = fgetc(check_fp);
		putchar(c);
	}
	fclose(check_fp);
}
void CleanLogin()//�������
{
	FILE *clean_fp = fopen("Message/login-record.txt","w");
	fclose(clean_fp);
}
