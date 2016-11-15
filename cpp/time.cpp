/*************************************************************************
    > File Name: time.cpp
    > Author: zguiq
    > Created Time: Sunday, November 13, 2016 AM08:29:43 CST
************************************************************************/
#include "time.h"

mTime::mTime()
{
	hour =0;
	min  =0;
	sec  =0;
}
mTime::mTime(int a, int b, int c)
{
	hour = a %= 12;
	min  = b %= 60;
	sec  = c %= 60;
}
mTime operator+(const mTime time1, const mTime time2)
{
	mTime time;
	time.sec = time1.sec + time2.sec;
	if(time.sec > 60)
	{
		time.min = 1;
		time.sec %= 60;
	}
	time.min +=(time1.min + time2.min);
	if(time.min > 60)
	{
		time.hour = 1;
		time.min %=60;
	}
	time.hour += (time1.hour + time2.hour);
	time.hour %=12;
	return time;

	//return (mTime(time1.hour+time2.hour, time1.min+time2.min, time1.sec+time2.sec));	
}
mTime operator-(const mTime time1, const mTime time2)
{
	mTime time;
	time.sec = time1.sec - time2.sec;
	if(time.sec < 0)
	{
		time.min = -1;
		time.sec += 60;
	}
	time.min +=(time1.min - time2.min);
	if(time.min < 0)
	{
		time.hour = -1;
		time.min +=60;
	}
	time.hour += (time1.hour - time2.hour);
	return time;
	//return (mTime(time1.hour-time2.hour, time1.min-time2.min, time1.sec-time2.sec));
}
