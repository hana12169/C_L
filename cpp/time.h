/*************************************************************************
    > File Name: time.h
    > Author: zguiq
    > Created Time: Sunday, November 13, 2016 AM08:26:13 CST
************************************************************************/
#ifndef TIME
#define TIME

class mTime
{
	public:
		int hour;
		int min;
		int sec;
		mTime(int, int, int);
		mTime();
};
mTime operator+(const mTime, const mTime);
mTime operator-(const mTime, const mTime);
#endif
