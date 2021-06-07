/*头文件以及大多数函数声明的所在*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#ifndef _struct_
#define _struct_
typedef struct _Ticket      /*电影票信息*/
{
	char username[15]; 		/*用户名*/
	char movie_name[15];    /*电影名*/
	char screen_name[15];	/*影厅名*/
	int time[3];	 	    /*电影放映日期 -> int*/
	int stime[2];		    /*开始时间(几点)*/
	int etime[2];		    /*结束时间(几点)*/
	int myline,myrow;       /*我的座位行和列*/
	float price;            /*价格*/
	int id;
	struct _Ticket *next;
} Ticket;
typedef struct _Movies   /*电影信息*/
{
	char name[15];	     /*电影名*/
	char dir[15];		 /*导演*/
	char star[15];		 /*主演*/
	char label[10];		 /*标签*/
	char where[15];		 /*地区*/
	char lang[15];		 /*语言*/
	int stime[3];      	 /*放映时间 年-月-日*/
	char intro[100];	 /*简介*/
	float price;	 	 /*价格*/
	int mins;			 /*时长*/
	double ALL;
	struct _Movies *next;
} Movie;
typedef struct _Box 	    /*票房*/
{
	struct _Box *prev;
	char movie_name[15]; 	/*电影名*/
	float price;		    /*价格*/
	double sum;			    /*票房*/
	struct _Box *next;
} Box;
typedef struct _Screen     /*影厅*/
{
	char name[15];		   /*影厅名*/
	int line,row;          /*行 和 列*/
	int seat[100][100];    /*影厅座位*/
	struct _Screen *next;
} Screen;
typedef struct _Seat       /*座位信息*/
{
	char movie_name[15];   /*电影名*/
	char screen_name[15];  /*影厅名*/
	int line,row;          /*行和列*/
	int time[3];           /*播出日期 -> int*/
	int stime[2];          /*开始时间*/
	int etime[2];          /*结束时间*/
	int seat[100][100];    /*座位*/
	int id;
	struct _Seat *next;
} Seat;
typedef struct _Code       /*邀请码*/
{
	int code;              /*邀请码*/
	int num;               /*权限*/
	struct _Code *next;
} Code;
typedef struct _Person     /*使用者*/
{
	char name[15];	       /*姓名*/
	char password[20];     /*密码*/
	int num;		       /*权限*/
	struct _Person *next;
} Person;
#endif
#ifndef _in_								  /*输入信息*/
#define _in_
void In_Name(char *name,int Max);             /*用于输入姓名*/
void In_Passward(char *passward,int Max);     /*用于输入密码*/
#endif
#ifndef _time_legal_														   /*判断时间合法性*/
#define _time_legal_
int IsTimeLegal(int year,int month,int day,int nowyear,int nowmon,int nowday); /*判断年月日是否合法*/
#endif
#ifndef _face_
#define _face_
void Login(); 		/*登录*/
void Register();	/*注册*/
#endif
#ifndef _time_login_
#define _time_login_
void InLogin(char *name);		/*进入记录*/
void OutLogin(char *name);		/*离开记录*/
void CheckLogin();				/*检查登录数据*/
void CleanLogin();				/*清除登录数据*/
#endif
#ifndef _port_
#define _port_
void Port(int num,char* name);		/*端口函数*/
void Manager(char *name);			/*经理端口*/
void Admin(char* name);				/*管理员端口*/
void Customer(char* name);			/*顾客端口*/
#endif
#ifndef _code_							/*邀请码函数*/
#define _code_
Code *Code_Creathead();					/*创建头*/
void Code_CreatLink(Code* code_head);	/*读取文件内容*/
int Code_Find(Code* code_head,int code);/*寻找是否存在该邀请码,如果存在返回其权限值,不存在返回0*/
int Code_Add(Code* code_head,int num);	/*增加相应权限的邀请码*/
int Code_Print(Code *code_head);		/*展示所有邀请码*/
void Code_Save(Code* code_head);		/*保存所有邀请码到文件中*/
#endif
#ifndef _person_														/*使用者的信息*/
#define _person_
Person* Person_Creathead();												/*创建头*/
void Person_CreatLink(Person *person_head);								/*读取文件内容*/
int Person_Add(Person *person_head,char *name,char *passward,int num);	/*创造新的用户,如果有重名就返回0,无重名就返回1*/
void Person_Del(Person *person_head,char *name);						/*删除用户*/
void Person_Modify(Person *p,char *newname,char *newpassward);			/*修改用户信息*/
Person* Person_Find(Person *person_head,char *name);					/*通过姓名查找用户,如果找到就返回指向该用户节点的指针,否则返回NULL*/
void Person_Print(Person *person_head);									/*展示所有的用户信息*/
void Person_Save(Person *person_head);									/*保存用户信息到文件*/
#endif
#ifndef _movie_                                                        	/*电影信息*/
#define _movie_
int Movie_IsTimeLegal(int year,int month,int day);
Movie* Movie_Creathead();												/*创建头*/
void Movie_CreatLink(Movie *movie_head);								/*从文件中读取内容*/
int Movie_Add(Movie *movie_head,char *name,char* dir,char *star,char *label,char *where,char *lang,int *stime,char *intro,float price,int mins); /*电影信息的添加,如果没有重名就返回1,否则返回0*/
Movie* Movie_Find(Movie *movie_head,char *name);						/*通过电影名查找电影,如果存在就返回结点指针,否则返回NULL*/
void Movie_Print(Movie *movie_head);									/*展示所有电影信息*/
void Movie_Save(Movie *movie_head);										/*保存信息到文件*/
int Movie_Creat(Movie* movie_head,int flag);							/*创建新的电影信息,flag是0就不查找重名,最后调用Movie_Add()函数*/
void Movie_PrintOne(Movie *p);											/*只展示一个电影的信息*/
int Movie_FindMo(Movie *movie_head,char *movie_name);					/*模糊查找,如果查找到相关电影信息后返回1,否则返回0*/
void Movie_Del(Movie *movie_head,char *name);							/*删除电影*/
void Movie_Modify(Movie *movie_head,Movie *p,float price,char *intro);	/*修改电影信息*/
#endif
#ifndef _screen_																	/*影厅信息*/
#define _screen_
Screen *Screen_Creathead();															/*创建头*/
void Screen_CreatLink(Screen *screen_head);											/*从文件读取信息*/
int Screen_Add(Screen *screen_head,char *name,int line,int row,int seat[100][100]);	/*增加剧院信息,如果重名返回0,否则返回1*/
Screen* Screen_Find(Screen *screen_head,char *name);								/*通过影厅名查找影厅,如果找到返回节点指针,否贼返回NULL*/
void Screen_Del(Screen *screen_head,char *name);									/*删除影厅信息*/
int Screen_Creat(Screen *screen_head,int flag);										/*创建新的影厅信息,flag为1查找重名*/
void Screen_Save(Screen *screen_head);												/*保存信息到文件*/
void Screen_Print(Screen* screen_head);												/*展示所有影厅信息*/
void Screen_Modify(Screen *p,int line,int row,int num);								/*修改影厅座位信息*/
#endif
#ifndef _seat_  												        /*座位信息*/
#define _seat_
Seat* Seat_Creathead();													/*创建头*/
void Seat_CreatLink(Seat *seat_head);									/*从文件中读取信息*/
void Seat_Add(Seat *seat_head,char *movie_name,char *screen_name,Screen *screen,Movie *movie_p,int *_time,int *stime,int *etime);	/*增加座位,在增加某个电影排片时使用*/
void Seat_Print(Seat *p);												/*展示一个座位信息,顾客查看时使用*/
int Seat_FindMovie(Seat *seat_head,char *movie_name);					/*查看某个电影的场次时使用(找到并显示),找到至少一个返回1,否则返回0*/
int Seat_Del(Seat *seat_head,int id);									/*通过座位id删除座位找到返回1,没找到返回0,减少排片时使用,以及下架电影或者影厅时使用*/
void Seat_Save(Seat *seat_head);										/*保存信息到文件*/
void Seat_PrintAll(Seat *seat_head);									/*展示所有排片*/
void Seat_Modify(Seat* seat_head,char *movie_name,char *screen_name,int *time,int *stime,int myline,int myrow,int num);/*修改座位状态,用于顾客买票时使用*/
int Seat_Print_seat(Seat *p);											/*顾客查看座位*/
Seat *Seat_Findid(Seat *seat_head,int id);								/*通过座位id找到座位返回节点指针,否则返回NULL*/
void Seat_DelAll_Movie(Seat* seat_head,char *movie_name);				/*删除所有相关座位信息*/
void Seat_DelAll_Screen(Seat* seat_head,char *screen_name);				/*和上面差不多,本来是放一起的...*/
int Seat_IsTimeOk(Seat *seat_head,char *screen_name,int *_time,int *stime,int *etime);	/*判断排片时间是否冲突*/
void Ticket_Del_Seat(Ticket *ticket_head,char* movie_name,char* screen_name,int *_time,int *stime,int *etime);	/*减少排片时删除相关电影票*/
void Seat_FindOverTime(Seat *seat_head,int nowyear,int nowmonth,int nowday,int nowhour,int nowmin);	/*寻找超时的场次并删除*/
#endif
#ifndef _box_											/*票房信息*/
#define _box_
Box *Box_Creathead();									/*创建头*/
void Box_CreatLink(Box *box_head);						/*读取信息*/
void Box_Add(Box *box_head,char *movie_name,float price, double sum);	/*增加一个票房名,经理增加一个电影后使用*/
void Box_Del(Box *Box_head,char *movie_name);			/*删除一个票房名,经理下架电影时使用*/
Box* Box_Find(Box *box_head,char *movie_name);			/*通过电影名查找票房,返回节点指针,否则返回NULL*/
void Box_Replace(Box *p,Box *m);						/*交换节点信息*/
void Box_Sort(Box *low,int flag);						/*票房排序*/
void Box_Print(Box *box_head);							/*展示所有票房*/
void Box_Save(Box *box_head);							/*保存到文件*/
#endif
#ifndef _strcmp_me_				/*字符串模糊比较*/
#define _strcmp_me_
int _strcmp(char *s1,char *s2);	/*模糊比较函数*/
#endif
#ifndef _ticket_												/*电影票*/
#define _ticket_
Ticket* Ticket_Creathead();										/*创建头*/
void Ticket_CreatLink(Ticket *ticket_head);						/*读取信息*/
void Ticket_Add(Ticket *ticket_head,char *username,char *movie_name,char *screen_name,int *time,int *stime,int *etime,int myline,int myrow,float price,int seat_id);/*增加电影票,在顾客购买电影票时使用*/
void Ticket_Del(Ticket*ticket_head,int id);						/*通过id删除电影票,退票时使用*/
void Ticket_Save(Ticket* ticket_head);							/*保存电影票信息*/
void Ticket_Print(Ticket *p);									/*展示一张电影票信息*/
void Ticket_Find(Ticket *ticket_head,char *username);			/*通过用户名查找电影票信息并展示*/
int Ticket_FindId(Ticket *ticket_head,int id);					/*返回id的电影票节点指针,否则返回NULL*/
void Ticket_DelAll_Movie(Ticket *ticket_head,char *movie_name);	/*删除一切相关信息*/
void Ticket_DelAll_Screen(Ticket *ticket_head,char *Screen_name);
void Ticket_Modify(Ticket *ticket_head,char *name,char *newname);	/*电影票名的更改,用于用户更改姓名后电影票信息的更新*/
#endif
#ifndef _automatic_del_
#define _automatic_del_
void Automatic_Del_Seat();										/*自动化减少场次*/
#endif
