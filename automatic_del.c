/*�Զ������ٹ��ڳ���*/
#include "all.h"
void Automatic_Del_Seat()//�Զ������ٹ��ڳ���
{
	struct tm *p;
	time_t timep = time(NULL)+8*60*60;//����ʱ��
	p = gmtime(&timep);
	Seat *seat_head = Seat_Creathead();
	Seat_CreatLink(seat_head);
	Seat_FindOverTime(seat_head,p->tm_year+1900,p->tm_mon+1,p->tm_mday,p->tm_hour,p->tm_min);
	Seat_Save(seat_head);
}
