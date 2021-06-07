/*判断年月日是否合规的函数定义*/
#include<stdio.h>
int IsLeadYear(int year)//判断是否是闰年
{
	if(year%400 == 0||(year%4==0&&year%100!=0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int MaxDay(int year,int month)//返回月份的天数
{
	if(month == 2)
	{
		if(IsLeadYear(year))
		{
			return 29;
		}
		else
		{
			return 30;
		}
	}
	else
	{
		if(month == 1||month == 3||month ==5||month == 7||month == 8||month == 10||month == 12)
		{
			return 31;
		}
		else
		{
			return 30;
		}
	}
}
int IsTimeLegal(int year,int month,int day,int nowyear,int nowmon,int nowday)//判断年月日是否合法
{
	if(year>=nowyear)
	{
		if(((year>nowyear&&month>=1)||month>=nowmon)&&month<=12)
		{
			if(((month>nowmon&&day>=1)||day>=nowday)&&day<=MaxDay(year,month))
			{
				return 1;
			}
		}
	}
	return 0;
}
