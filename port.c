/*���Ʋ�ͬ�û��Ĺ���ģ��*/
#include"all.h"
int Account(char *name)//�ҵ��˻�
{
	printf("����1�޸���Ϣ\n");
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
		printf("�޸���Ϣ��...\n");
		char newname[15];
		printf("�������µ�����:");
		In_Name(newname,15);
		putchar('\n');
		if(!Person_Find(person_head,newname))//����û�������� 
		{
			char passward1[20],passward2[20];
			while(1)
			{
				system("cls");
				fflush(stdin);
				printf("�޸���Ϣ��...\n");
				printf("�������޸ĺ������:");
				In_Passward(passward1,20);
				putchar('\n');
				printf("���ٴ������޸Ĺ��������:");
				In_Passward(passward2,20);
				putchar('\n');
				if(strcmp(passward1,passward2)==0)
				{
					break;
				}
				else
				{
					printf("�������벻һ��,����������\n");
					printf("������Լ���\n");
					getch();
				}
			}
			Person_Modify(p,newname,passward1);
			Person_Save(person_head);
			Ticket *ticket_head = Ticket_Creathead();
			Ticket_CreatLink(ticket_head);
			Ticket_Modify(ticket_head,name,newname);
			Ticket_Save(ticket_head);
			printf("�޸ĳɹ�,�����µ�¼\n");
			printf("������Լ���\n");
			getch();
			break;
		}
		else
		{
			printf("�������Ѵ���,����������\n");
			printf("������Լ���\n");
			getch();
		}
	}
	return 1;
}
void Port(int num,char* name)//�˿�
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
void Manager(char* name)//����
{
	while(1)
	{
		system("cls");
		fflush(stdin);
		printf(
		    "1.��Ӱ��Ϣ��ѯ������\n"
		    "2.Ӱ����Ϣ��ѯ������\n"
		    "3.ָ����Ӱ�����ƻ���ѯ������\n"
		    "4.������е�Ӱ��Ƭ\n"
		    "5.�ҵ��˻�\n"
		    "6.�˳���¼\n"
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
				    "1.ָ����Ӱ��Ϣ����\n"
				    "2.������е�Ӱ��Ϣ\n"
				    "3.������Ӱ��Ϣ\n"
				    "4.����\n"
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
						printf("��������Ҫ�����ĵ�Ӱ��:");
						In_Name(movie_name,15);
						Movie * movie_head = Movie_Creathead();
						Movie_CreatLink(movie_head);
						system("cls");
						Movie *p = Movie_Find(movie_head,movie_name);
						fflush(stdin);
						if(p)
						{
							printf(
							    "��Ӱ��:%-15s\n"
							    "  ����:%-15s     ����:%-15s\n"
							    "  ��ǩ:%-15s     ����:%-15s  ����:%-10s\n"
							    "  ��ӳʱ��:%4d-%2d-%2d      �ۼ�:%.2fԪ\t ʱ��:%2d����\n"
							    "   ���:%-100s\n",p->name,p->dir,p->star,p->label,p->where,p->lang,(p->stime)[0],(p->stime)[1],(p->stime)[2],p->price,p->mins,p->intro);
							printf("1.�޸ĵ�Ӱ��Ϣ\n2.�¼ܵ�Ӱ��Ϣ\n3.����\n");
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
										    "��Ӱ��:%-15s\n"
										    "  ����:%-15s     ����:%-15s\n"
										    "  ��ǩ:%-15s     ����:%-15s  ����:%-10s\n"
										    "  ��ӳʱ��:%4d-%2d-%2d      �ۼ�:%.2fԪ\t ʱ��:%2d����\n"
										    "   ���:%-100s\n",p->name,p->dir,p->star,p->label,p->where,p->lang,(p->stime)[0],(p->stime)[1],(p->stime)[2],p->price,p->mins,p->intro);
										printf("1.�޸ļ۸�\n2.�޸ļ��\n�������뷵��\n");
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
													printf("�������޸ĺ�ļ۸�\n");
													if(scanf("%f",&price)==1)
													{
														Movie_Modify(movie_head,p,price,NULL);
														printf(
														    "�۸��޸ĳɹ�\n"
														    " ���������\n"
														);
														getch();
														break;
													}
													else
													{
														printf(
														    "�۸���������,����������\n"
														    "       ���������\n"
														);
														getch();
													}
												}
											}
											else
											{
												fflush(stdin);
												printf("��������\n");
												In_Name(intro,100);
												Movie_Modify(movie_head,p,-1,intro);
												printf(
												    "����޸ĳɹ�\n"
												    " ���������\n"
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
									printf("�¼ܳɹ�\n");
									printf("���������\n");
									getch();
								}
							}
							break;
						}
						else
						{
							printf("δ�ҵ��õ�Ӱ��Ϣ\n");
							int n;
							printf("����1���������Ӱ��\n");
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
					printf("������Լ���\n");
					getch();
				}
				else if(num == 3)
				{
					system("cls");
					fflush(stdin);
					Movie *movie_head = Movie_Creathead();
					Movie_CreatLink(movie_head);
					printf("ȷ��������Ӱ��Ϣ������1\n");
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
								printf("¼���Ӱ��Ϣ���\n");
								printf("����1����¼��\n");
							}
							else
							{
								printf("��Ӱ���ظ�\n����1����¼��\n");
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
					printf("��������,����������\n");
					printf("������Լ���\n");
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
				    "1.ָ��Ӱ����Ϣ����\n"
				    "2.�������Ӱ����Ϣ\n"
				    "3.����Ӱ����Ϣ\n"
				    "4.����\n"
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
						printf("��������Ҫ������Ӱ����:");
						In_Name(screen_name,15);
						Screen *screen_head = Screen_Creathead();
						Screen_CreatLink(screen_head);
						Screen *p = Screen_Find(screen_head,screen_name);
						if(p)
						{
							printf("Ӱ����\t    ���� ����\n");
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
										printf("�� ");
									}
									if(x==3)
									{
										printf("�� ");
									}
								}
								putchar('\n');
							}
							printf("1.�޸�Ӱ����λ��Ϣ\n2.ɾ��Ӱ��\n3.���ز˵�\n");
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
										printf("Ӱ����\t    ���� ����\n");
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
													printf("�� ");
												}
												if(x==3)
												{
													printf("�� ");
												}
											}
											putchar('\n');
										}
										int line,row;
										printf("��������Ҫ�������λ������ת����λ״̬(���ʾ����,���ʾ��)\n");
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
											printf("�޸ĳɹ�\n");
										}
										else
										{
											printf("�޷����ĸ���λ\n");
										}
										printf("�����޸�������1\n");
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
									printf(" ɾ���ɹ�\n");
									printf("���������\n");
									getch();
								}
							}
							break;
						}
						else
						{
							system("cls");
							fflush(stdin);
							printf("δ�ҵ���Ӱ������Ϣ\n");
							int n;
							printf("����1��������Ӱ����\n");
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
					printf("������Լ���\n");
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
							printf("¼��Ӱ����Ϣ���\n");
							printf("����1����¼��\n");
						}
						else
						{
							printf("Ӱ�����Ѵ���\n����1����¼��\n");
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
					printf("��������,����������\n");
					printf("������Լ���\n");
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
				Screen *screen_head = Screen_Creathead();//Ӱ����Ϣ׼������
				Screen_CreatLink(screen_head);
				Seat *seat_head = Seat_Creathead();//������Ϣ׼������
				Seat_CreatLink(seat_head);
				Movie *movie_head = Movie_Creathead();//��Ӱ��Ϣ׼������
				Movie_CreatLink(movie_head);
				printf("��������Ҫ�����ĵ�Ӱ��\n");
				char movie_name[15];
				In_Name(movie_name,15);
				Movie *movie_p = Movie_Find(movie_head,movie_name);//��Ҫ�����ĵ�Ӱָ��������!!
				if(movie_p)//����������Ӱ��Ϣ
				{
					while(1)
					{
						system("cls");
						printf("��Ӱ��\t     Ӱ����\t        ��������   ��ʼʱ�� ����ʱ�� id\n");
						Seat_FindMovie(seat_head,movie_name);//չʾһ��
						putchar('\n');
						printf("1.������Ƭ\n2,������Ƭ\n3.����\n");
						int n;
						if(scanf("%d",&n)==1&&n==1||n==2)
						{
							if(n==1)//++
							{
								printf("��������Ҫ��Ƭ��Ӱ����:");//֮�����������Ƭ��������
								char screen_name[15];
								In_Name(screen_name,15);
								Screen *screen_p = Screen_Find(screen_head,screen_name);//��Ҫ��Ƭ��Ӱ��ָ��������!!!
								if(screen_p)//��������Ӱ��
								{
									int stime[2],etime[2],_time[3];
									while(1)
									{
										fflush(stdin);
										printf("�������Ӱ�Ĳ�������(2002-3-26):");
										if(scanf("%d-%d-%d",&(_time[0]),&(_time[1]),&(_time[2]))!=3||!IsTimeLegal(_time[0],_time[1],_time[2],(movie_p->stime)[0],(movie_p->stime)[1],(movie_p->stime)[2]))//���_time�Ƿ� >= ��ӳ����
										{
											printf(
											    "����ʱ��������������ʱ���ͻ,��˶Ժ���������\n"
											    "                 ���������\n"
											);
											getch();
											continue;
										}
										printf("�������ӰƬ�Ĳ���ʱ��(7:10):");
										if(scanf("%d:%d",&(stime[0]),&(stime[1]))!=2)//���stime��ͬӰ��seat��etime�Ƿ��ͻ
										{
											printf("ʱ��������������������\n");
											printf("     ���������\n");
											getch();
											continue;
										}
										etime[0] = (stime[0]+(stime[1]+movie_p->mins)/60)%24;//���ܻ������ �ǵð�����Ҫ�ж���
										etime[1] = (stime[1]+movie_p->mins)%60;
										if(!(Seat_IsTimeOk(seat_head,screen_name,_time,stime,etime)))
										{
											printf(
											    "����ʱ����ڳ�ͻ,��˶Ժ���������\n"
											    "            ���������\n"
											);
											getch();
											continue;
										}
										break;
									}
									Seat_Add(seat_head,movie_name,screen_name,screen_p,movie_p,_time,stime,etime);
									Seat_Save(seat_head);
									printf(" ��Ƭ�ɹ�\n");
									printf("���������\n");
									getch();
								}
								else
								{
									printf("û�и�Ӱ����Ϣ\n");
									printf(" ���������\n");
									getch();
								}
							}
							else //--
							{
								printf("��������Ҫ�����ĵ�Ӱid��:");
								int id;
								if(scanf("%d",&id)==1&&Seat_Del(seat_head,id))
								{
									Seat_Save(seat_head);
									system("cls");
									fflush(stdin);
									printf(" ɾ���ɹ�");
									printf("���������\n");
									getch();
								}
								else
								{
									system("cls");
									fflush(stdin);
									printf("id����򲻴���\n");
									printf(" ���������\n");
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
					printf("û�в�ѯ���õ�Ӱ��Ϣ\n");
					printf("   ����1���²�ѯ\n");
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
		else if(n==4) //������е�Ӱ��Ƭ
		{
			system("cls");
			fflush(stdin);
			Seat* seat_head = Seat_Creathead();
			Seat_CreatLink(seat_head);
			printf("��Ӱ��\t     Ӱ����\t        ��������   ��ʼʱ�� ����ʱ�� id\n");
			Seat_PrintAll(seat_head);
			printf("���������\n");
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
			printf("��������,����������\n");
			printf(" ������Լ���\n");
			getch();
		}
	}
}
void Admin(char* name)//����Ա
{
	while(1)
	{
		system("cls");
		fflush(stdin);
		printf(
		    "1.ϵͳ�û�����\n"
		    "2.��¼��¼��ѯ\n"
		    "3.������������\n"
		    "4.��ʾ����������\n"
		    "5.�޸��ҵ���Ϣ\n"
		    "6.�˳���¼\n"
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
				    "1.ָ���û���Ϣ����\n"
				    "2.��ʾ�����û�\n"
				    "3.������һ��\n"
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
							printf("��������Ҫ���в������˺���:");
							In_Name(fname,15);
							Person *p = Person_Find(person_head,fname);
							if(strcmp(fname,name)==0)
							{
								printf("�������ڴ˴��޸��Լ���Ϣ\n");
								printf("������Լ���\n");
								getch();
							}
							else if(p)
							{
							re:
								;
								system("cls");
								fflush(stdin);
								printf("�û���\t    ����\t\t  Ȩ��\n");
								printf("%-15s%-20s%-5d\n",p->name,p->password,p->num);
								printf(
								    "1.�޸��û���Ϣ\n"
								    "2.ɾ���û���Ϣ\n"
								    "3.����\n"
								);
								int n;
								scanf("%d",&n);
								if(n == 1)
								{
									while(1)
									{
										system("cls");
										fflush(stdin);
										printf("�޸���Ϣ��\n");
										char newname[15];
										printf("�������µ�����:");
										In_Name(newname,15);
										if(!Person_Find(person_head,newname))
										{
											char passward1[20],passward2[20];
											while(1)
											{
												system("cls");
												fflush(stdin);
												printf("�޸���Ϣ��...\n");
												printf("�������޸ĺ������:");
												In_Passward(passward1,20);
												putchar('\n');
												printf("���ٴ������޸Ĺ��������:");
												In_Passward(passward2,20);
												putchar('\n');
												if(strcmp(passward1,passward2)==0)
												{
													break;
												}
												else
												{
													printf("�������벻һ��,����������\n");
													printf("������Լ���\n");
													getch();
												}
											}
											Person_Modify(p,newname,passward1);
											Person_Save(person_head);
											printf("�޸ĳɹ�\n");
											printf("������Լ���\n");
											getch();
											break;
										}
										else
										{
											printf("�������Ѵ���,����������\n");
											printf("������Լ���\n");
											getch();
										}
									}
								}
								else if(n == 2)
								{
									int num;
									printf("ȷ��ɾ��������1\n");
									if(scanf("%d",&num)==1&&num==1)
									{
										system("cls");
										fflush(stdin);
										Person_Del(person_head,fname);
										Person_Save(person_head);
										printf("ɾ���ɹ�\n");
										printf("������Լ���\n");
										getch();
									}
								}
								else if(n == 3)
								{
									break;
								}
								else
								{
									printf("��������,����������\n");
									printf("������Լ���\n");
									getch();
									goto re;
								}
							}
							else
							{
								system("cls");
								fflush(stdin);
								printf("�����ڴ��û�\n");
								printf("������Լ���\n");
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
						printf("������Լ���\n");
						getch();
					}
					else
					{
						break;
					}
				}
				else
				{
					printf("��������,����������\n");
					printf("������Լ���\n");
					getch();
				}
			}

		}
		else if(n == 2)
		{
			system("cls");
			fflush(stdin);
			printf("�û���\t        ��¼����    ʱ��    ���ʲ���\n");
			CheckLogin();
			putchar('\n');
			int m;
			printf("�Ƿ��������?\n���������1,ȡ��������0:\n");
			if(scanf("%d",&m)==1 && m == 1)
			{
				CleanLogin();
				printf("����ɹ�!\n");
			}
			printf("������Լ���\n");
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
				    "1.����������\n"
				    "2.����Ա������\n"
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
					printf("������Լ���\n");
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
				printf("ɾ������������������1\n");
				int num;
				if(scanf("%d",&num)==1&&num==1)
				{
					FILE *code_fp = fopen("Message/code.txt","w+");
					fclose(code_fp);
					printf("ɾ���ɹ�\n");
				}
			}
			printf("������Լ���\n");
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
			printf("��������,����������\n");
			printf("������Լ���\n");
			getch();
		}
	}
}
void Customer(char* name)//�˿�
{
	while(1)
	{
		system("cls");
		fflush(stdin);
		printf(
		    "1.������Ӱ\n"
		    "2.�ҵĵ�ӰƱ\n"
		    "3.Ʊ��ͳ��\n"
		    "4.�ҵ��˻�\n"
		    "5.�˳���¼\n"
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
					printf("1.��׼ѡ��\n2.ģ����ѯ\n3.����\n");
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
							printf("�������Ӱ��:");
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
									printf("��Ӱ��Ϣ����\n");
									printf(
									    "��Ӱ��:%-15s\n"
									    "  ����:%-15s     ����:%-15s\n"
									    "  ��ǩ:%-15s     ����:%-15s  ����:%-10s\n"
									    "  ��ӳʱ��:%4d-%2d-%2d      �ۼ�:%.2fԪ\t ʱ��:%2d����\n"
									    "  ���:%-100s\n",movie_p->name,movie_p->dir,movie_p->star,movie_p->label,movie_p->where,movie_p->lang,(movie_p->stime)[0],(movie_p->stime)[1],(movie_p->stime)[2],movie_p->price,movie_p->mins,movie_p->intro);
									printf("��ӳ�ƻ�����\n");
									Seat *seat_head  =(Seat*)malloc(sizeof(Seat));
									seat_head->next = NULL;
									Seat_CreatLink(seat_head);
									system("cls");
									printf("��Ӱ��\t      Ӱ����\t       ��������   ��ʼʱ�� ����ʱ��   id\n");
									if(Seat_FindMovie(seat_head,movie_name))//���Ҳ�չ��
									{
										putchar('\n');
										fflush(stdin);
										printf("������id�������ӰƱ\n��������q�˳�\n");
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
												printf("��������λ����\n");
												int myline,myrow;
												if(scanf("%d%d",&myline,&myrow)!=2)
												{
													printf("������������,����������\n");
													printf("���������\n");
													getch();
													continue;
												}
												if(myline>=1&&myrow>=1&&myline<=seat_p->line&&myrow<=seat_p->row&&(seat_p->seat)[myline][myrow]==1)
												{
													Ticket *ticket_head = Ticket_Creathead();
													Ticket_CreatLink(ticket_head);
													Ticket_Add(ticket_head,name,movie_name,seat_p->screen_name,seat_p->time,seat_p->stime,seat_p->etime,myline,myrow,movie_p->price,id);
													printf("����ɹ�\n");
													printf("���������\n");
													getch();
													goto over;
													break;
												}
												else
												{
													printf("����ѡ�����λ�޷���Ԥ��,������ѡ��\n");
												}
											}
										}
										else
										{
											system("cls");
											fflush(stdin);
											printf("id�����ڻ�����,����������\n");
											printf("���������\n");
											getch();
										}
									}
									else
									{
										printf("����ط�ӳ�ƻ�\n");
										printf("���������\n");
										getch();
										break;
									}
								}
							}
							else
							{
								system("cls");
								fflush(stdin);
								printf("��������ĵ�Ӱ������\n");
								printf("���������\n");
								getch();
							}
						}
						else
						{
							printf("�������Ӱ�Ĺؼ���:");
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
								printf("û����صĵ�Ӱ,�����²��һ��л����ҷ�ʽ\n");
								printf("���������\n");
								getch();
							}

						}
					}
					else
					{
						system("cls");
						fflush(stdin);
						printf("������������,����������\n");
						printf("���������\n");
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
					printf("���ĵ�ӰƱ����\n");
					Ticket *ticket_head = Ticket_Creathead();
					Ticket_CreatLink(ticket_head);
					printf("�û���\t        ��Ӱ��\t       Ӱ����\t     ��Ӱ��ӳ���� ��ʼʱ�� ����ʱ��  ��λ����  �۸�    id\n");
					Ticket_Find(ticket_head,name);
					printf("����1ѡ��ӰƬ��Ʊ,�������뷵��\n");
					int num;
					if(scanf("%d",&num)!=1||num!=1)
					{
						break;
					}
					else
					{
						printf("������ӰƱid����Ʊ:");
						int id;
						if(scanf("%d",&id)==1)
						{
							if(Ticket_FindId(ticket_head,id))
							{
								system("cls");
								Ticket_Del(ticket_head,id);
								printf("��Ʊ�ɹ�\n");
								printf("������˳�\n");
								getch();
								break;
							}
							else
							{
								printf("�޴�idӰƱ\n");
								printf("���������\n");
								getch();
							}
						}
						else
						{
							system("cls");
							printf("id��������,����������\n");
							printf("������Լ���\n");
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
					printf("1.����鿴��ǰƱ��\n2.����鿴��ǰƱ��\n3.����\n");
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
							printf("Ʊ����������\n");
							printf("��Ӱ��\t        Ʊ��\n");
							Box *box_head = Box_Creathead();
							Box_CreatLink(box_head);
							Box_Sort(box_head->next,num-1);
							Box_Print(box_head);
							printf("���������\n");
							getch();
						}
					}
					else
					{
						printf("������������,����������\n");
						printf(" ���������\n");
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
			printf("������������,����������\n");
			printf("���������\n");
			getch();
		}
	}
}
