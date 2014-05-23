#include <fstream>
#include <iostream>
#include <list>
#include <vector>
using namespace std;
std::vector<int> perfectNumber(int n,std::vector<int> &v);
int main(){
	
	int n=10000;
	std::vector<int> v;
	std::vector<int> vec=perfectNumber(n,v);
	for(int j=0;j<vec.size();j++){
		std::cout<<vec[j]<<std::endl;
	}	
}
std::vector<int> perfectNumber(int n,std::vector<int> &v){
	
	if(n==0){
		return v;
	}
	else{
		int sum=0;
		for(int i=1;i<n;i++){
			if(n%i==0){
				sum=(sum+i);
			}

		}
		
		if(sum==n){
			v.push_back(n);
		}
		return perfectNumber(n-1,v);
	}

}
