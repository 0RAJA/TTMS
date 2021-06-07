/*控制不同用户的功能模块*/
#include"all.h"
int Account(char *name)//我的账户
{
	printf("输入1修改信息\n");
	int n;
	if(scanf("%d",&n)!=1||n!=1)
	{
		return 0;
	}
	system("cls");
	fflush(stdin);
	Person* person_head = Person_Creathead();
	Person_CreatLink(person_head);
	Person*p = Person_Find(person_head,name);
	while(1)
	{
		system("cls");
		fflush(stdin);
		printf("修改信息中...\n");
		char newname[15];
		printf("请输入新的姓名:");
		In_Name(newname,15);
		putchar('\n');
		if(!Person_Find(person_head,newname))//看有没有重名的 
		{
			char passward1[20],passward2[20];
			while(1)
			{
				system("cls");
				fflush(stdin);
				printf("修改信息中...\n");
				printf("请输入修改后的密码:");
				In_Passward(passward1,20);
				putchar('\n');
				printf("请再次输入修改过后的密码:");
				In_Passward(passward2,20);
				putchar('\n');
				if(strcmp(passward1,passward2)==0)
				{
					break;
				}
				else
				{
					printf("两次输入不一致,请重新输入\n");
					printf("任意键以继续\n");
					getch();
				}
			}
			Person_Modify(p,newname,passward1);
			Person_Save(person_head);
			Ticket *ticket_head = Ticket_Creathead();
			Ticket_CreatLink(ticket_head);
			Ticket_Modify(ticket_head,name,newname);
			Ticket_Save(ticket_head);
			printf("修改成功,请重新登录\n");
			printf("任意键以继续\n");
			getch();
			break;
		}
		else
		{
			printf("该姓名已存在,请重新输入\n");
			printf("任意键以继续\n");
			getch();
		}
	}
	return 1;
}
void Port(int num,char* name)//端口
{
	if(num==1)
	{
		Manager(name);
	}
	else if(num == 2)
	{
		Customer(name);
	}
	else if(num == 3)
	{
		Admin(name);
	}
}
void Manager(char* name)//经理
{
	while(1)
	{
		system("cls");
		fflush(stdin);
		printf(
		    "1.电影信息查询及管理\n"
		    "2.影厅信息查询及管理\n"
		    "3.指定电影播出计划查询及管理\n"
		    "4.浏览所有电影排片\n"
		    "5.我的账户\n"
		    "6.退出登录\n"
		);
		int n = 0;
		scanf("%d",&n);
		if(n == 6)
		{
			break;
		}
		else if(n == 1)
		{
			while(1)
			{
				system("cls");
				fflush(stdin);
				printf(
				    "1.指定电影信息操作\n"
				    "2.浏览所有电影信息\n"
				    "3.新增电影信息\n"
				    "4.返回\n"
				);
				int num = 0;
				scanf("%d",&num);
				if(num == 4)
				{
					break;
				}
				if(num == 1)
				{
					while(1)
					{
						system("cls");
						fflush(stdin);
						char movie_name[15];
						printf("请输入需要操作的电影名:");
						In_Name(movie_name,15);
						Movie * movie_head = Movie_Creathead();
						Movie_CreatLink(movie_head);
						system("cls");
						Movie *p = Movie_Find(movie_head,movie_name);
						fflush(stdin);
						if(p)
						{
							printf(
							    "电影名:%-15s\n"
							    "  导演:%-15s     主演:%-15s\n"
							    "  标签:%-15s     地区:%-15s  语言:%-10s\n"
							    "  上映时间:%4d-%2d-%2d      售价:%.2f元\t 时间:%2d分钟\n"
							    "   简介:%-100s\n",p->name,p->dir,p->star,p->label,p->where,p->lang,(p->stime)[0],(p->stime)[1],(p->stime)[2],p->price,p->mins,p->intro);
							printf("1.修改电影信息\n2.下架电影信息\n3.返回\n");
							int n;
							if(scanf("%d",&n)==1&&n==1||n==2||n==3)
							{
								if(n==3)
								{
									break;
								}
								if(n==1)
								{
									while(1)
									{
										system("cls");
										fflush(stdin);
										printf(
										    "电影名:%-15s\n"
										    "  导演:%-15s     主演:%-15s\n"
										    "  标签:%-15s     地区:%-15s  语言:%-10s\n"
										    "  上映时间:%4d-%2d-%2d      售价:%.2f元\t 时间:%2d分钟\n"
										    "   简介:%-100s\n",p->name,p->dir,p->star,p->label,p->where,p->lang,(p->stime)[0],(p->stime)[1],(p->stime)[2],p->price,p->mins,p->intro);
										printf("1.修改价格\n2.修改简介\n其他输入返回\n");
										int num;
										if(scanf("%d",&num)==1&&num==1||num==2)
										{
											float price;
											char intro[100];
											price = -1;
											if(num==1)
											{
												while(1)
												{
													fflush(stdin);
													printf("请输入修改后的价格\n");
													if(scanf("%f",&price)==1)
													{
														Movie_Modify(movie_head,p,price,NULL);
														printf(
														    "价格修改成功\n"
														    " 任意键继续\n"
														);
														getch();
														break;
													}
													else
													{
														printf(
														    "价格输入有误,请重新输入\n"
														    "       任意键继续\n"
														);
														getch();
													}
												}
											}
											else
											{
												fflush(stdin);
												printf("请输入简介\n");
												In_Name(intro,100);
												Movie_Modify(movie_head,p,-1,intro);
												printf(
												    "简介修改成功\n"
												    " 任意键继续\n"
												);
												getch();
											}
										}
										else
										{
											break;
										}
									}
								}
								else
								{
									Movie_Del(movie_head,movie_name);
									Movie_Save(movie_head);
									printf("下架成功\n");
									printf("任意键继续\n");
									getch();
								}
							}
							break;
						}
						else
						{
							printf("未找到该电影信息\n");
							int n;
							printf("输入1重新输入电影名\n");
							if(scanf("%d",&n)!=1||n!=1)
							{
								break;
							}
						}
					}
				}
				else if(num == 2)
				{
					system("cls");
					fflush(stdin);
					Movie *movie_head = Movie_Creathead();
					Movie_CreatLink(movie_head);
					Movie_Print(movie_head);
					printf("任意键以继续\n");
					getch();
				}
				else if(num == 3)
				{
					system("cls");
					fflush(stdin);
					Movie *movie_head = Movie_Creathead();
					Movie_CreatLink(movie_head);
					printf("确定新增电影信息请输入1\n");
					int o;
					if(scanf("%d",&o)==1&&o==1)
					{
						while(1)
						{
							system("cls");
							fflush(stdin);
							if(Movie_Creat(movie_head,1))
							{
								Movie_Save(movie_head);
								printf("录入电影信息完成\n");
								printf("输入1继续录入\n");
							}
							else
							{
								printf("电影名重复\n输入1重新录入\n");
							}
							int n;
							if(scanf("%d",&n)!=1||n!=1)
							{
								break;
							}
						}
					}
				}
				else
				{
					system("cls");
					fflush(stdin);
					printf("输入有误,请重新输入\n");
					printf("任意键以继续\n");
					getch();
				}
			}
		}
		else if(n == 2)
		{
			while(1)
			{
				system("cls");
				fflush(stdin);
				printf(
				    "1.指定影厅信息操作\n"
				    "2.浏览所有影厅信息\n"
				    "3.新增影厅信息\n"
				    "4.返回\n"
				);
				int num = 0;
				scanf("%d",&num);
				if(num==4)
				{
					break;
				}
				if(num == 1)
				{
					while(1)
					{
						system("cls");
						fflush(stdin);
						char screen_name[15];
						printf("请输入需要操作的影厅名:");
						In_Name(screen_name,15);
						Screen *screen_head = Screen_Creathead();
						Screen_CreatLink(screen_head);
						Screen *p = Screen_Find(screen_head,screen_name);
						if(p)
						{
							printf("影厅名\t    行数 列数\n");
							printf(
							    "%-15s%-2d  %-2d\n",p->name,p->line,p->row
							);
							for(int i = 1; i<=p->line; i++)
							{
								for(int j = 1; j<=p->row; j++)
								{
									int x = (p->seat)[i][j];
									if(x==1)
									{
										printf("○ ");
									}
									if(x==3)
									{
										printf("◎ ");
									}
								}
								putchar('\n');
							}
							printf("1.修改影厅座位信息\n2.删除影厅\n3.返回菜单\n");
							int n;
							if(scanf("%d",&n)==1&&n==1||n==2||n==3)
							{
								if(n==3)
								{
									break;
								}
								if(n==1)
								{
									while(1)
									{
										system("cls");
										fflush(stdin);
										printf("影厅名\t    行数 列数\n");
										printf(
										    "%-15s%-2d  %-2d\n",p->name,p->line,p->row
										);
										for(int i = 1; i<=p->line; i++)
										{
											for(int j = 1; j<=p->row; j++)
											{
												int x = (p->seat)[i][j];
												if(x==1)
												{
													printf("○ ");
												}
												if(x==3)
												{
													printf("◎ ");
												}
											}
											putchar('\n');
										}
										int line,row;
										printf("请输入需要变更的座位行列来转换座位状态(○表示正常,◎表示损坏)\n");
										if(scanf("%d%d",&line,&row)==2&&line>=1&&row>=1&&line<=p->line&&row<=p->row)
										{
											if((p->seat)[line][row]==1)
											{
												Screen_Modify(p,line,row,3);
											}
											else
											{
												Screen_Modify(p,line,row,1);
											}
											Screen_Save(screen_head);
											printf("修改成功\n");
										}
										else
										{
											printf("无法更改该座位\n");
										}
										printf("继续修改请输入1\n");
										int n;
										if(scanf("%d",&n)!=1||n!=1)
										{
											break;
										}
									}
								}
								else
								{
									Screen_Del(screen_head,screen_name);
									Screen_Save(screen_head);
									printf(" 删除成功\n");
									printf("任意键继续\n");
									getch();
								}
							}
							break;
						}
						else
						{
							system("cls");
							fflush(stdin);
							printf("未找到该影厅的信息\n");
							int n;
							printf("输入1重新输入影厅名\n");
							if(scanf("%d",&n)!=1||n!=1)
							{
								break;
							}
						}
					}
				}
				else if(num==2)
				{
					system("cls");
					fflush(stdin);
					Screen* screen_head = Screen_Creathead();
					Screen_CreatLink(screen_head);
					Screen_Print(screen_head);
					printf("任意键以继续\n");
					getch();
				}
				else if(num==3)
				{
					while(1)
					{
						system("cls");
						fflush(stdin);
						Screen *screen_head = Screen_Creathead();
						Screen_CreatLink(screen_head);
						if(Screen_Creat(screen_head,1))
						{
							printf("录入影厅信息完成\n");
							printf("输入1继续录入\n");
						}
						else
						{
							printf("影厅名已存在\n输入1重新录入\n");
						}
						int n;
						if(scanf("%d",&n)!=1||n!=1)
						{
							break;
						}
					}
				}
				else
				{
					system("cls");
					fflush(stdin);
					printf("输入有误,请重新输入\n");
					printf("任意键以继续\n");
					getch();
				}
			}
		}
		else if(n == 3)
		{
			while(1)
			{
				system("cls");
				fflush(stdin);
				Screen *screen_head = Screen_Creathead();//影厅信息准备就绪
				Screen_CreatLink(screen_head);
				Seat *seat_head = Seat_Creathead();//场次信息准备就绪
				Seat_CreatLink(seat_head);
				Movie *movie_head = Movie_Creathead();//电影信息准备就绪
				Movie_CreatLink(movie_head);
				printf("请输入需要操作的电影名\n");
				char movie_name[15];
				In_Name(movie_name,15);
				Movie *movie_p = Movie_Find(movie_head,movie_name);//需要操作的电影指针在这里!!
				if(movie_p)//如果有这个电影信息
				{
					while(1)
					{
						system("cls");
						printf("电影名\t     影厅名\t        播出日期   开始时间 结束时间 id\n");
						Seat_FindMovie(seat_head,movie_name);//展示一下
						putchar('\n');
						printf("1.增加排片\n2,减少排片\n3.返回\n");
						int n;
						if(scanf("%d",&n)==1&&n==1||n==2)
						{
							if(n==1)//++
							{
								printf("请输入需要排片的影厅名:");//之后可以增加排片的年月日
								char screen_name[15];
								In_Name(screen_name,15);
								Screen *screen_p = Screen_Find(screen_head,screen_name);//需要排片的影厅指针在这里!!!
								if(screen_p)//如果有这个影厅
								{
									int stime[2],etime[2],_time[3];
									while(1)
									{
										fflush(stdin);
										printf("请输入电影的播出日期(2002-3-26):");
										if(scanf("%d-%d-%d",&(_time[0]),&(_time[1]),&(_time[2]))!=3||!IsTimeLegal(_time[0],_time[1],_time[2],(movie_p->stime)[0],(movie_p->stime)[1],(movie_p->stime)[2]))//检查_time是否 >= 上映日期
										{
											printf(
											    "播出时间输入有误或存在时间冲突,请核对后重新输入\n"
											    "                 任意键继续\n"
											);
											getch();
											continue;
										}
										printf("请输入该影片的播放时间(7:10):");
										if(scanf("%d:%d",&(stime[0]),&(stime[1]))!=2)//检查stime与同影厅seat的etime是否冲突
										{
											printf("时间输入有误请重新输入\n");
											printf("     任意键继续\n");
											getch();
											continue;
										}
										etime[0] = (stime[0]+(stime[1]+movie_p->mins)/60)%24;//可能会跨日期 记得把日期要判断下
										etime[1] = (stime[1]+movie_p->mins)%60;
										if(!(Seat_IsTimeOk(seat_head,screen_name,_time,stime,etime)))
										{
											printf(
											    "播出时间存在冲突,请核对后重新输入\n"
											    "            任意键继续\n"
											);
											getch();
											continue;
										}
										break;
									}
									Seat_Add(seat_head,movie_name,screen_name,screen_p,movie_p,_time,stime,etime);
									Seat_Save(seat_head);
									printf(" 排片成功\n");
									printf("任意键继续\n");
									getch();
								}
								else
								{
									printf("没有该影厅信息\n");
									printf(" 任意键继续\n");
									getch();
								}
							}
							else //--
							{
								printf("请输入需要撤场的电影id名:");
								int id;
								if(scanf("%d",&id)==1&&Seat_Del(seat_head,id))
								{
									Seat_Save(seat_head);
									system("cls");
									fflush(stdin);
									printf(" 删除成功");
									printf("任意键继续\n");
									getch();
								}
								else
								{
									system("cls");
									fflush(stdin);
									printf("id有误或不存在\n");
									printf(" 任意键继续\n");
									getch();
								}
							}
						}
						else
						{
							break;
						}
					}
				}
				else
				{
					printf("没有查询到该电影信息\n");
					printf("   输入1重新查询\n");
					int n;
					if(scanf("%d",&n)!=1||n!=1)
					{
						break;
					}
					goto next;
				}
				break;
			next:
				;
			}
		}
		else if(n==4) //浏览所有电影排片
		{
			system("cls");
			fflush(stdin);
			Seat* seat_head = Seat_Creathead();
			Seat_CreatLink(seat_head);
			printf("电影名\t     影厅名\t        播出日期   开始时间 结束时间 id\n");
			Seat_PrintAll(seat_head);
			printf("任意键继续\n");
			getch();
		}
		else if(n==5)
		{
			if(Account(name))
			{
				break;
			}
		}
		else
		{
			system("cls");
			fflush(stdin);
			printf("输入有误,请重新输入\n");
			printf(" 任意键以继续\n");
			getch();
		}
	}
}
void Admin(char* name)//管理员
{
	while(1)
	{
		system("cls");
		fflush(stdin);
		printf(
		    "1.系统用户管理\n"
		    "2.登录记录查询\n"
		    "3.增加新邀请码\n"
		    "4.显示所有邀请码\n"
		    "5.修改我的信息\n"
		    "6.退出登录\n"
		);
		int n = 0;
		scanf("%d",&n);
		if(n == 6)
		{
			break;
		}
		if(n == 1)
		{
			while(1)
			{
				system("cls");
				fflush(stdin);
				printf(
				    "1.指定用户信息操作\n"
				    "2.显示所有用户\n"
				    "3.返回上一级\n"
				);
				int num;
				if(scanf("%d",&num)==1&&num==1||num==2||num==3)
				{
					if(num==1)
					{
						while(1)
						{
							system("cls");
							fflush(stdin);
							Person *person_head = Person_Creathead();
							Person_CreatLink(person_head);
							char fname[15];
							printf("请输入需要进行操作的账号名:");
							In_Name(fname,15);
							Person *p = Person_Find(person_head,fname);
							if(strcmp(fname,name)==0)
							{
								printf("不允许在此处修改自己信息\n");
								printf("任意键以继续\n");
								getch();
							}
							else if(p)
							{
							re:
								;
								system("cls");
								fflush(stdin);
								printf("用户名\t    密码\t\t  权限\n");
								printf("%-15s%-20s%-5d\n",p->name,p->password,p->num);
								printf(
								    "1.修改用户信息\n"
								    "2.删除用户信息\n"
								    "3.返回\n"
								);
								int n;
								scanf("%d",&n);
								if(n == 1)
								{
									while(1)
									{
										system("cls");
										fflush(stdin);
										printf("修改信息中\n");
										char newname[15];
										printf("请输入新的姓名:");
										In_Name(newname,15);
										if(!Person_Find(person_head,newname))
										{
											char passward1[20],passward2[20];
											while(1)
											{
												system("cls");
												fflush(stdin);
												printf("修改信息中...\n");
												printf("请输入修改后的密码:");
												In_Passward(passward1,20);
												putchar('\n');
												printf("请再次输入修改过后的密码:");
												In_Passward(passward2,20);
												putchar('\n');
												if(strcmp(passward1,passward2)==0)
												{
													break;
												}
												else
												{
													printf("两次输入不一致,请重新输入\n");
													printf("任意键以继续\n");
													getch();
												}
											}
											Person_Modify(p,newname,passward1);
											Person_Save(person_head);
											printf("修改成功\n");
											printf("任意键以继续\n");
											getch();
											break;
										}
										else
										{
											printf("该姓名已存在,请重新输入\n");
											printf("任意键以继续\n");
											getch();
										}
									}
								}
								else if(n == 2)
								{
									int num;
									printf("确认删除请输入1\n");
									if(scanf("%d",&num)==1&&num==1)
									{
										system("cls");
										fflush(stdin);
										Person_Del(person_head,fname);
										Person_Save(person_head);
										printf("删除成功\n");
										printf("任意键以继续\n");
										getch();
									}
								}
								else if(n == 3)
								{
									break;
								}
								else
								{
									printf("输入有误,请重新输入\n");
									printf("任意键以继续\n");
									getch();
									goto re;
								}
							}
							else
							{
								system("cls");
								fflush(stdin);
								printf("不存在此用户\n");
								printf("任意键以继续\n");
								getch();
							}
							break;
						over:
							;
						}
					}
					else if(num==2)
					{
						system("cls");
						fflush(stdin);
						Person *person_head = Person_Creathead();
						Person_CreatLink(person_head);
						Person_Print(person_head);
						putchar('\n');
						printf("任意键以继续\n");
						getch();
					}
					else
					{
						break;
					}
				}
				else
				{
					printf("输入有误,请重新输入\n");
					printf("任意键以继续\n");
					getch();
				}
			}

		}
		else if(n == 2)
		{
			system("cls");
			fflush(stdin);
			printf("用户名\t        登录日期    时间    访问操作\n");
			CheckLogin();
			putchar('\n');
			int m;
			printf("是否清除数据?\n清除请输入1,取消请输入0:\n");
			if(scanf("%d",&m)==1 && m == 1)
			{
				CleanLogin();
				printf("清除成功!\n");
			}
			printf("任意键以继续\n");
			getch();
		}
		else if(n == 3)
		{
			while(1)
			{
				system("cls");
				fflush(stdin);
				int num;
				printf(
				    "1.经理邀请码\n"
				    "2.管理员邀请码\n"
				);
				if(scanf("%d",&num)==1&&num==1||num==2)
				{
					if(num == 2)
					{
						num = 3;
					}
					Code *code_head = Code_Creathead();
					Code_CreatLink(code_head);
					printf("%d\n",Code_Add(code_head,num));
					Code_Save(code_head);
					printf("任意键以继续\n");
					getch();
					break;
				}
			}
		}
		else if(n == 4)
		{
			system("cls");
			fflush(stdin);
			Code *code_head = Code_Creathead();
			Code_CreatLink(code_head);
			if(Code_Print(code_head))
			{
				printf("删除所有邀请码请输入1\n");
				int num;
				if(scanf("%d",&num)==1&&num==1)
				{
					FILE *code_fp = fopen("Message/code.txt","w+");
					fclose(code_fp);
					printf("删除成功\n");
				}
			}
			printf("任意键以继续\n");
			getch();
		}
		else if(n == 5)
		{
			if(Account(name))
			{
				break;
			}
		}
		else
		{
			system("cls");
			fflush(stdin);
			printf("输入有误,请重新输入\n");
			printf("任意键以继续\n");
			getch();
		}
	}
}
void Customer(char* name)//顾客
{
	while(1)
	{
		system("cls");
		fflush(stdin);
		printf(
		    "1.搜索电影\n"
		    "2.我的电影票\n"
		    "3.票房统计\n"
		    "4.我的账户\n"
		    "5.退出登录\n"
		);
		int n;
		if(scanf("%d",&n)==1&&n>=1&&n<=5)
		{
			if(n==5)
			{
				break;
			}
			if(n==1)
			{
				while(1)
				{
					system("cls");
					fflush(stdin);
					Movie *movie_head = Movie_Creathead();
					Movie_CreatLink(movie_head);
					Movie_Print(movie_head);
					putchar('\n');
					printf("1.精准选择\n2.模糊查询\n3.返回\n");
					int num;
					if(scanf("%d",&num)==1&&n==1||n==2||n==3)
					{
						if(num==3)
						{
							break;
						}
						if(num==1)
						{
						OK:
							;
							fflush(stdin);
							printf("请输入电影名:");
							char movie_name[15];
							In_Name(movie_name,15);
							Movie *movie_head = Movie_Creathead();
							Movie_CreatLink(movie_head);
							Movie *movie_p = Movie_Find(movie_head,movie_name);
							if(movie_p)
							{
								while(1)
								{
									system("cls");
									fflush(stdin);
									printf("电影信息如下\n");
									printf(
									    "电影名:%-15s\n"
									    "  导演:%-15s     主演:%-15s\n"
									    "  标签:%-15s     地区:%-15s  语言:%-10s\n"
									    "  上映时间:%4d-%2d-%2d      售价:%.2f元\t 时间:%2d分钟\n"
									    "  简介:%-100s\n",movie_p->name,movie_p->dir,movie_p->star,movie_p->label,movie_p->where,movie_p->lang,(movie_p->stime)[0],(movie_p->stime)[1],(movie_p->stime)[2],movie_p->price,movie_p->mins,movie_p->intro);
									printf("放映计划如下\n");
									Seat *seat_head  =(Seat*)malloc(sizeof(Seat));
									seat_head->next = NULL;
									Seat_CreatLink(seat_head);
									system("cls");
									printf("电影名\t      影厅名\t       播出日期   开始时间 结束时间   id\n");
									if(Seat_FindMovie(seat_head,movie_name))//查找并展出
									{
										putchar('\n');
										fflush(stdin);
										printf("请输入id来购买电影票\n或者输入q退出\n");
										int id;
										if(scanf("%d",&id)!=1)
										{
											break;
										}
										Seat *seat_p = Seat_Findid(seat_head,id);
										if(seat_p)
										{
											Seat_Print_seat(seat_p);
											while(1)
											{
												printf("请输入座位行列\n");
												int myline,myrow;
												if(scanf("%d%d",&myline,&myrow)!=2)
												{
													printf("您的输入有误,请重新输入\n");
													printf("任意键继续\n");
													getch();
													continue;
												}
												if(myline>=1&&myrow>=1&&myline<=seat_p->line&&myrow<=seat_p->row&&(seat_p->seat)[myline][myrow]==1)
												{
													Ticket *ticket_head = Ticket_Creathead();
													Ticket_CreatLink(ticket_head);
													Ticket_Add(ticket_head,name,movie_name,seat_p->screen_name,seat_p->time,seat_p->stime,seat_p->etime,myline,myrow,movie_p->price,id);
													printf("购买成功\n");
													printf("任意键继续\n");
													getch();
													goto over;
													break;
												}
												else
												{
													printf("您所选择的座位无法被预定,请重新选择\n");
												}
											}
										}
										else
										{
											system("cls");
											fflush(stdin);
											printf("id不存在或有误,请重新输入\n");
											printf("任意键继续\n");
											getch();
										}
									}
									else
									{
										printf("无相关放映计划\n");
										printf("任意键继续\n");
										getch();
										break;
									}
								}
							}
							else
							{
								system("cls");
								fflush(stdin);
								printf("您所输入的电影不存在\n");
								printf("任意键继续\n");
								getch();
							}
						}
						else
						{
							printf("请输入电影的关键字:");
							char movie_name[15];
							In_Name(movie_name,15);
							putchar('\n');
							Movie *movie_head = Movie_Creathead();
							Movie_CreatLink(movie_head);
							system("cls");
							if(Movie_FindMo(movie_head,movie_name))
							{
								goto OK;
							}
							else
							{
								printf("没有相关的电影,请重新查找或切换查找方式\n");
								printf("任意键继续\n");
								getch();
							}

						}
					}
					else
					{
						system("cls");
						fflush(stdin);
						printf("您的输入有误,请重新输入\n");
						printf("任意键继续\n");
						getch();
					}
				}
			over:
				;
			}
			else if(n==2)
			{
				while(1)
				{
					system("cls");
					fflush(stdin);
					printf("您的电影票如下\n");
					Ticket *ticket_head = Ticket_Creathead();
					Ticket_CreatLink(ticket_head);
					printf("用户名\t        电影名\t       影厅名\t     电影放映日期 开始时间 结束时间  座位行列  价格    id\n");
					Ticket_Find(ticket_head,name);
					printf("输入1选择影片退票,其他输入返回\n");
					int num;
					if(scanf("%d",&num)!=1||num!=1)
					{
						break;
					}
					else
					{
						printf("请输入影票id来退票:");
						int id;
						if(scanf("%d",&id)==1)
						{
							if(Ticket_FindId(ticket_head,id))
							{
								system("cls");
								Ticket_Del(ticket_head,id);
								printf("退票成功\n");
								printf("任意键退出\n");
								getch();
								break;
							}
							else
							{
								printf("无此id影票\n");
								printf("任意键继续\n");
								getch();
							}
						}
						else
						{
							system("cls");
							printf("id输入有误,请重新输入\n");
							printf("任意键以继续\n");
							getch();
						}
					}
				}
			}
			else if(n==3)
			{
				while(1)
				{
					system("cls");
					printf("1.升序查看当前票房\n2.降序查看当前票房\n3.返回\n");
					int num;
					if(scanf("%d",&num)==1&&num==1||num==2||n==3)
					{
						fflush(stdin);
						if(num==3)
						{
							break;
						}
						else
						{
							system("cls");
							printf("票房数据如下\n");
							printf("电影名\t        票房\n");
							Box *box_head = Box_Creathead();
							Box_CreatLink(box_head);
							Box_Sort(box_head->next,num-1);
							Box_Print(box_head);
							printf("任意键继续\n");
							getch();
						}
					}
					else
					{
						printf("您的输入有误,请重新输入\n");
						printf(" 任意键继续\n");
						getch();
					}
				}
			}
			else if(n==4)
			{
				if(Account(name))
				{
					break;
				}
			}
		}
		else
		{
			system("cls");
			printf("您的输入有误,请重新输入\n");
			printf("任意键继续\n");
			getch();
		}
	}
}
