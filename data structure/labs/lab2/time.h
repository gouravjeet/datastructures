//File: Time.h
//Purpose: Header file with declaration of the time class including member function and private member variables

class Time{
public:
	Time();
	Time(uintptr_t aHour,uintptr_t aMinute, uintptr_t aSecond );
	//Accessors
	uintptr_t getHour() const;
	uintptr_t getMinute() const;
	uintptr_t getSecond() const;
	//MODIFIERS
	void setHour(uintptr_t aHour);
	void setMinute(uintptr_t aMinute);
	void setSecond(uintptr_t aSecond);
	void PrintAmPm();



private:
	uintptr_t hour;
	uintptr_t minute;
	uintptr_t second;

};
// prototypes for functions that operate on class objects are included in the header file
bool IsEarlierThan(const Time& t1, const Time& t2);
//void change_times(const Time& t1, const Time t2);