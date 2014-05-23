//Program: main.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include "time.h"

int main(){
	//std::cout<<"please enter the time";
	Time t1(1,1,1);
	//Time t2();
	Time t2;
	std::vector<Time> input_vector;

	t1.setHour(4);
	t1.setMinute(1);
	t1.setSecond(1);
	Time t3(02,04,56);
	Time t4(12,34, 50);
	
	input_vector.push_back(t1);
	input_vector.push_back(t2);
	input_vector.push_back(t3);
	input_vector.push_back(t4);

	sort(input_vector.begin(),input_vector.end(),IsEarlierThan);
	for(int i=0;i<input_vector.size();i++)
		{
		std:: cout << std::endl;
		input_vector[i].PrintAmPm();	
		
		}
	
	std:: cout << std::endl;
	
/*	std::cout<<t1.getHour();
	std::cout<<t1.getMinute();
	std::cout<<t1.getSecond()<<std::endl;
	//t1.PrintAmPm();
	std::cout<<t2.getHour();
	std::cout<<t2.getMinute();
	std::cout<<t2.getSecond()<<std::endl;*/
	std::cout<<IsEarlierThan(t1,t2);


	


	return 0;
}