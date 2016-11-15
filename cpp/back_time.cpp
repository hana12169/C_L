#ifndef _TIME_
#define _TIME_
/*************************************************************************
    > File Name: date.cpp
    > Author: zguiq
    > Created Time: Thu 10 Nov 2016 09:17:53 PM CST
************************************************************************/


class mTime{
	public:
		int hour;
		int min;
		int sec;
		mTime(int thour, int tmin, int tsec)
		{
			hour =thour%12;
			min  =tmin%60;
			sec  =tsec%60;
		}
		mTime()
		{
			hour = 0;
			min  = 0;
			sec  = 0;
		}
		mTime(const mTime& mtime)
		{
			hour= mtime.hour;
			min = mtime.min;
			sec = mtime.sec;
		}
};

mTime operator+(const mTime &time1, const mTime &time2)
{
	return mTime(time1.hour+time2.hour,time1.min+time2.min,time1.sec+time2.sec);
}
#endif
