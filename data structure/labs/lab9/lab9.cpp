#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <cstdlib>
#include <string>
#include <cassert>
int main(int argc, char* argv[]){		//Main function 
	std::map<int,int> roots;
  	int input;

	if(argc != 2){
		std::cerr << "Usage:\n "<<argv[0]<<"\n";
	}
	std::ifstream in_str(argv[1]);
	if(!in_str){
		std::cerr<<"Could not open"<<argv[1]<<"to read\n";// this will give error if the file doesnot open

	}
  	while(in_str>>input){//Calculate the count of variables
	++roots[input];
  	}
  	std::map<int,int>::const_iterator it;
  	int largest=0;
	for(it=roots.begin();it!=roots.end();++it){
		std::cout<<"count of "<<it->first<<" is "<<it->second<<std::endl;
	}
	for(it=roots.begin();it!=roots.end();++it){
		if(it->second>largest){
			largest=it->second;
		}
	}
	std::cout<<"Modes are as follows ";
	for(it=roots.begin();it!=roots.end();++it){
		
		if(it->second==largest){
			std::cout<<it->first<<" ";
		}
	}
	return 0;
}
