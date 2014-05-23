#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <cstdlib>
#include <string>
#include <cassert>
#include <vector>
using namespace std;
int main(){
	int i;
	map<string,std::vector<int> > m;
	map<string, std::vector<int> >::iterator p;
	m[string("hello")].push_back(5);
	p=m.find(string("hello"));
	p->second.size();
	(p->second)[i]=15;
	cout<<(p->second)[i];
	string line;
	int line_number=0;
	while(getline(cin,line)){
		line_number++;
		//Break the string up into words
		vector<string> words=
	}
}
