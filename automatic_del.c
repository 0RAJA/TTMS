/*自动化减少过期场次*/
#include "all.h"
void Automatic_Del_Seat()//自动化减少过期场次
{
	struct tm *p;
	time_t timep = time(NULL)+8*60*60;//北京时间
	p = gmtime(&timep);
	Seat *seat_head = Seat_Creathead();
	Seat_CreatLink(seat_head);
	Seat_FindOverTime(seat_head,p->tm_year+1900,p->tm_mon+1,p->tm_mday,p->tm_hour,p->tm_min);
	Seat_Save(seat_head);
}
