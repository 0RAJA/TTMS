/*ͷ�ļ��Լ��������������������*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#ifndef _struct_
#define _struct_
typedef struct _Ticket      /*��ӰƱ��Ϣ*/
{
	char username[15]; 		/*�û���*/
	char movie_name[15];    /*��Ӱ��*/
	char screen_name[15];	/*Ӱ����*/
	int time[3];	 	    /*��Ӱ��ӳ���� -> int*/
	int stime[2];		    /*��ʼʱ��(����)*/
	int etime[2];		    /*����ʱ��(����)*/
	int myline,myrow;       /*�ҵ���λ�к���*/
	float price;            /*�۸�*/
	int id;
	struct _Ticket *next;
} Ticket;
typedef struct _Movies   /*��Ӱ��Ϣ*/
{
	char name[15];	     /*��Ӱ��*/
	char dir[15];		 /*����*/
	char star[15];		 /*����*/
	char label[10];		 /*��ǩ*/
	char where[15];		 /*����*/
	char lang[15];		 /*����*/
	int stime[3];      	 /*��ӳʱ�� ��-��-��*/
	char intro[100];	 /*���*/
	float price;	 	 /*�۸�*/
	int mins;			 /*ʱ��*/
	double ALL;
	struct _Movies *next;
} Movie;
typedef struct _Box 	    /*Ʊ��*/
{
	struct _Box *prev;
	char movie_name[15]; 	/*��Ӱ��*/
	float price;		    /*�۸�*/
	double sum;			    /*Ʊ��*/
	struct _Box *next;
} Box;
typedef struct _Screen     /*Ӱ��*/
{
	char name[15];		   /*Ӱ����*/
	int line,row;          /*�� �� ��*/
	int seat[100][100];    /*Ӱ����λ*/
	struct _Screen *next;
} Screen;
typedef struct _Seat       /*��λ��Ϣ*/
{
	char movie_name[15];   /*��Ӱ��*/
	char screen_name[15];  /*Ӱ����*/
	int line,row;          /*�к���*/
	int time[3];           /*�������� -> int*/
	int stime[2];          /*��ʼʱ��*/
	int etime[2];          /*����ʱ��*/
	int seat[100][100];    /*��λ*/
	int id;
	struct _Seat *next;
} Seat;
typedef struct _Code       /*������*/
{
	int code;              /*������*/
	int num;               /*Ȩ��*/
	struct _Code *next;
} Code;
typedef struct _Person     /*ʹ����*/
{
	char name[15];	       /*����*/
	char password[20];     /*����*/
	int num;		       /*Ȩ��*/
	struct _Person *next;
} Person;
#endif
#ifndef _in_								  /*������Ϣ*/
#define _in_
void In_Name(char *name,int Max);             /*������������*/
void In_Passward(char *passward,int Max);     /*������������*/
#endif
#ifndef _time_legal_														   /*�ж�ʱ��Ϸ���*/
#define _time_legal_
int IsTimeLegal(int year,int month,int day,int nowyear,int nowmon,int nowday); /*�ж��������Ƿ�Ϸ�*/
#endif
#ifndef _face_
#define _face_
void Login(); 		/*��¼*/
void Register();	/*ע��*/
#endif
#ifndef _time_login_
#define _time_login_
void InLogin(char *name);		/*�����¼*/
void OutLogin(char *name);		/*�뿪��¼*/
void CheckLogin();				/*����¼����*/
void CleanLogin();				/*�����¼����*/
#endif
#ifndef _port_
#define _port_
void Port(int num,char* name);		/*�˿ں���*/
void Manager(char *name);			/*����˿�*/
void Admin(char* name);				/*����Ա�˿�*/
void Customer(char* name);			/*�˿Ͷ˿�*/
#endif
#ifndef _code_							/*�����뺯��*/
#define _code_
Code *Code_Creathead();					/*����ͷ*/
void Code_CreatLink(Code* code_head);	/*��ȡ�ļ�����*/
int Code_Find(Code* code_head,int code);/*Ѱ���Ƿ���ڸ�������,������ڷ�����Ȩ��ֵ,�����ڷ���0*/
int Code_Add(Code* code_head,int num);	/*������ӦȨ�޵�������*/
int Code_Print(Code *code_head);		/*չʾ����������*/
void Code_Save(Code* code_head);		/*�������������뵽�ļ���*/
#endif
#ifndef _person_														/*ʹ���ߵ���Ϣ*/
#define _person_
Person* Person_Creathead();												/*����ͷ*/
void Person_CreatLink(Person *person_head);								/*��ȡ�ļ�����*/
int Person_Add(Person *person_head,char *name,char *passward,int num);	/*�����µ��û�,����������ͷ���0,�������ͷ���1*/
void Person_Del(Person *person_head,char *name);						/*ɾ���û�*/
void Person_Modify(Person *p,char *newname,char *newpassward);			/*�޸��û���Ϣ*/
Person* Person_Find(Person *person_head,char *name);					/*ͨ�����������û�,����ҵ��ͷ���ָ����û��ڵ��ָ��,���򷵻�NULL*/
void Person_Print(Person *person_head);									/*չʾ���е��û���Ϣ*/
void Person_Save(Person *person_head);									/*�����û���Ϣ���ļ�*/
#endif
#ifndef _movie_                                                        	/*��Ӱ��Ϣ*/
#define _movie_
int Movie_IsTimeLegal(int year,int month,int day);
Movie* Movie_Creathead();												/*����ͷ*/
void Movie_CreatLink(Movie *movie_head);								/*���ļ��ж�ȡ����*/
int Movie_Add(Movie *movie_head,char *name,char* dir,char *star,char *label,char *where,char *lang,int *stime,char *intro,float price,int mins); /*��Ӱ��Ϣ�����,���û�������ͷ���1,���򷵻�0*/
Movie* Movie_Find(Movie *movie_head,char *name);						/*ͨ����Ӱ�����ҵ�Ӱ,������ھͷ��ؽ��ָ��,���򷵻�NULL*/
void Movie_Print(Movie *movie_head);									/*չʾ���е�Ӱ��Ϣ*/
void Movie_Save(Movie *movie_head);										/*������Ϣ���ļ�*/
int Movie_Creat(Movie* movie_head,int flag);							/*�����µĵ�Ӱ��Ϣ,flag��0�Ͳ���������,������Movie_Add()����*/
void Movie_PrintOne(Movie *p);											/*ֻչʾһ����Ӱ����Ϣ*/
int Movie_FindMo(Movie *movie_head,char *movie_name);					/*ģ������,������ҵ���ص�Ӱ��Ϣ�󷵻�1,���򷵻�0*/
void Movie_Del(Movie *movie_head,char *name);							/*ɾ����Ӱ*/
void Movie_Modify(Movie *movie_head,Movie *p,float price,char *intro);	/*�޸ĵ�Ӱ��Ϣ*/
#endif
#ifndef _screen_																	/*Ӱ����Ϣ*/
#define _screen_
Screen *Screen_Creathead();															/*����ͷ*/
void Screen_CreatLink(Screen *screen_head);											/*���ļ���ȡ��Ϣ*/
int Screen_Add(Screen *screen_head,char *name,int line,int row,int seat[100][100]);	/*���Ӿ�Ժ��Ϣ,�����������0,���򷵻�1*/
Screen* Screen_Find(Screen *screen_head,char *name);								/*ͨ��Ӱ��������Ӱ��,����ҵ����ؽڵ�ָ��,��������NULL*/
void Screen_Del(Screen *screen_head,char *name);									/*ɾ��Ӱ����Ϣ*/
int Screen_Creat(Screen *screen_head,int flag);										/*�����µ�Ӱ����Ϣ,flagΪ1��������*/
void Screen_Save(Screen *screen_head);												/*������Ϣ���ļ�*/
void Screen_Print(Screen* screen_head);												/*չʾ����Ӱ����Ϣ*/
void Screen_Modify(Screen *p,int line,int row,int num);								/*�޸�Ӱ����λ��Ϣ*/
#endif
#ifndef _seat_  												        /*��λ��Ϣ*/
#define _seat_
Seat* Seat_Creathead();													/*����ͷ*/
void Seat_CreatLink(Seat *seat_head);									/*���ļ��ж�ȡ��Ϣ*/
void Seat_Add(Seat *seat_head,char *movie_name,char *screen_name,Screen *screen,Movie *movie_p,int *_time,int *stime,int *etime);	/*������λ,������ĳ����Ӱ��Ƭʱʹ��*/
void Seat_Print(Seat *p);												/*չʾһ����λ��Ϣ,�˿Ͳ鿴ʱʹ��*/
int Seat_FindMovie(Seat *seat_head,char *movie_name);					/*�鿴ĳ����Ӱ�ĳ���ʱʹ��(�ҵ�����ʾ),�ҵ�����һ������1,���򷵻�0*/
int Seat_Del(Seat *seat_head,int id);									/*ͨ����λidɾ����λ�ҵ�����1,û�ҵ�����0,������Ƭʱʹ��,�Լ��¼ܵ�Ӱ����Ӱ��ʱʹ��*/
void Seat_Save(Seat *seat_head);										/*������Ϣ���ļ�*/
void Seat_PrintAll(Seat *seat_head);									/*չʾ������Ƭ*/
void Seat_Modify(Seat* seat_head,char *movie_name,char *screen_name,int *time,int *stime,int myline,int myrow,int num);/*�޸���λ״̬,���ڹ˿���Ʊʱʹ��*/
int Seat_Print_seat(Seat *p);											/*�˿Ͳ鿴��λ*/
Seat *Seat_Findid(Seat *seat_head,int id);								/*ͨ����λid�ҵ���λ���ؽڵ�ָ��,���򷵻�NULL*/
void Seat_DelAll_Movie(Seat* seat_head,char *movie_name);				/*ɾ�����������λ��Ϣ*/
void Seat_DelAll_Screen(Seat* seat_head,char *screen_name);				/*��������,�����Ƿ�һ���...*/
int Seat_IsTimeOk(Seat *seat_head,char *screen_name,int *_time,int *stime,int *etime);	/*�ж���Ƭʱ���Ƿ��ͻ*/
void Ticket_Del_Seat(Ticket *ticket_head,char* movie_name,char* screen_name,int *_time,int *stime,int *etime);	/*������Ƭʱɾ����ص�ӰƱ*/
void Seat_FindOverTime(Seat *seat_head,int nowyear,int nowmonth,int nowday,int nowhour,int nowmin);	/*Ѱ�ҳ�ʱ�ĳ��β�ɾ��*/
#endif
#ifndef _box_											/*Ʊ����Ϣ*/
#define _box_
Box *Box_Creathead();									/*����ͷ*/
void Box_CreatLink(Box *box_head);						/*��ȡ��Ϣ*/
void Box_Add(Box *box_head,char *movie_name,float price, double sum);	/*����һ��Ʊ����,��������һ����Ӱ��ʹ��*/
void Box_Del(Box *Box_head,char *movie_name);			/*ɾ��һ��Ʊ����,�����¼ܵ�Ӱʱʹ��*/
Box* Box_Find(Box *box_head,char *movie_name);			/*ͨ����Ӱ������Ʊ��,���ؽڵ�ָ��,���򷵻�NULL*/
void Box_Replace(Box *p,Box *m);						/*�����ڵ���Ϣ*/
void Box_Sort(Box *low,int flag);						/*Ʊ������*/
void Box_Print(Box *box_head);							/*չʾ����Ʊ��*/
void Box_Save(Box *box_head);							/*���浽�ļ�*/
#endif
#ifndef _strcmp_me_				/*�ַ���ģ���Ƚ�*/
#define _strcmp_me_
int _strcmp(char *s1,char *s2);	/*ģ���ȽϺ���*/
#endif
#ifndef _ticket_												/*��ӰƱ*/
#define _ticket_
Ticket* Ticket_Creathead();										/*����ͷ*/
void Ticket_CreatLink(Ticket *ticket_head);						/*��ȡ��Ϣ*/
void Ticket_Add(Ticket *ticket_head,char *username,char *movie_name,char *screen_name,int *time,int *stime,int *etime,int myline,int myrow,float price,int seat_id);/*���ӵ�ӰƱ,�ڹ˿͹����ӰƱʱʹ��*/
void Ticket_Del(Ticket*ticket_head,int id);						/*ͨ��idɾ����ӰƱ,��Ʊʱʹ��*/
void Ticket_Save(Ticket* ticket_head);							/*�����ӰƱ��Ϣ*/
void Ticket_Print(Ticket *p);									/*չʾһ�ŵ�ӰƱ��Ϣ*/
void Ticket_Find(Ticket *ticket_head,char *username);			/*ͨ���û������ҵ�ӰƱ��Ϣ��չʾ*/
int Ticket_FindId(Ticket *ticket_head,int id);					/*����id�ĵ�ӰƱ�ڵ�ָ��,���򷵻�NULL*/
void Ticket_DelAll_Movie(Ticket *ticket_head,char *movie_name);	/*ɾ��һ�������Ϣ*/
void Ticket_DelAll_Screen(Ticket *ticket_head,char *Screen_name);
void Ticket_Modify(Ticket *ticket_head,char *name,char *newname);	/*��ӰƱ���ĸ���,�����û������������ӰƱ��Ϣ�ĸ���*/
#endif
#ifndef _automatic_del_
#define _automatic_del_
void Automatic_Del_Seat();										/*�Զ������ٳ���*/
#endif
