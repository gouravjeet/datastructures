#include <fstream>
#include <iostream>
#include <list>
#include <vector>
using namespace std;


int main(){
	float f;
	std::vector<float> v;
	v.push_back(40);
	v.push_back(70);	
	v.push_back(30);
	v.push_back(440);
	v.push_back(33);
	v.push_back(23);
	v.push_back(23);
	v.push_back(330);
	float min=0.0;
	float max=0.0;
	float diff=0.0;
	for(int i=0;i<v.size();i++){
		for(int j=1;j<v.size();j++){
			if(v[i]<v[j]){
				float diff1=v[j]-v[i];
				if(diff1>diff){
					diff=diff1;
				min=v[i];
				max=v[j];
				}
			}
			else if(v[i]>v[j]){
				float diff1=v[i]-v[j];
				if(diff1>diff){
					diff=diff1;
				min=v[j];
				max=v[i];
				}
			}

		}
	}
	std::cout<<max<<std::endl;
	std::cout<<min<<std::endl;
}