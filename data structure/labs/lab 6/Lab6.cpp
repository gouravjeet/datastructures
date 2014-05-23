#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cassert>
std::vector<int> reverse(std::vector<int> & vec);
void printV(std::vector<int> & vec);
int main(){

unsigned int i;
std::vector<int> first;
first.push_back(1);
first.push_back(2);
/*first.push_back(3);
first.push_back(4);
first.push_back(5);
first.push_back(6);
first.push_back(7);*/
printV(first);
std::vector<int> reverseV=reverse(first);
printV(reverseV);
reverseV=reverse(first);

std::vector<int> reverseVO=reverse(first);
printV(reverseVO);
}


std::vector<int> reverse(std::vector<int> & vec){

	int temp;
	if((vec.size()%2)==0){
	
		for(unsigned int i=0;i<(vec.size()/2);i++){	
			temp=vec[i];
			vec[i]=vec[vec.size()-1-i];
			vec[vec.size()-1-i]=temp;
		}
	
		return vec;
	}
	else {
	
		for(unsigned int i=0;i<(vec.size()/2);i++){	
			temp=vec[i];
			vec[i]=vec[vec.size()-1-i];
			vec[vec.size()-1-i]=temp;
		}	
		return vec;
	}

}
void printV(std::vector<int> & vec){

	std::cout<<"Size of Vector is "<<vec.size()<<std::endl;
	std::cout<<"Printing the Vector"<<std::endl;
	
	for(unsigned int i=0;i<vec.size();i++){
		std::cout<<vec[i]<<std::endl;	
	}
}



