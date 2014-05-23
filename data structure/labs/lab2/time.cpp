//File: time.cpp
// Purpose: implementation file of the time class
#include <iostream>
#include "time.h"

using namespace std;

//Default constructor implementation
Time::Time(){
	hour=1;
	minute=1;
	second=1;
}

// Parameter constructor
Time::Time(uintptr_t aHour, uintptr_t aMinute,uintptr_t aSecond){
	hour=aHour;
	minute=aMinute;
	second=aSecond;
}
uintptr_t Time::getHour() const{
	return hour;
}
uintptr_t Time::getMinute() const{
	return minute;
}
uintptr_t Time::getSecond() const{
	return second;
}
void Time::setHour(uintptr_t h){
	hour=h;
}
void Time::setMinute(uintptr_t m){
	minute=m;
}
void Time::setSecond(uintptr_t s){
	second=s;
}
bool IsEarlierThan(const Time& t1, const Time& t2){
	uintptr_t second_count1=((t1.getHour())*(3600)+((t1.getMinute())*60)+ t1.getSecond());
	uintptr_t second_count2=((t2.getHour())*(3600)+((t2.getMinute())*60)+ t2.getSecond());
	if (second_count1<second_count2)
	{
		std::cout<<"Earlier Time";
		return true;
	}
	else if(second_count1==second_count2)
	{
		std::cout<<"Equal Time";
		return true;
	}
	return false;
}

void Time::PrintAmPm(){
	if(hour>12)
	{
		hour=hour-12;
		std::cout<<hour<<":"<<minute<<":"<<second<<"pm";
	}
	else if(hour==0)
	{
		std::cout<<(hour+12)<<":"<<minute<<":"<<second<<"am";
	}
	else if (hour==12)
		{
			std::cout<<(hour)<<":"<<minute<<":"<<second<<"pm";
		}
	else {
		std::cout<<hour<<":"<<minute<<":"<<second<<"am";
	}
	
}

