#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cassert>
std::list<int> reverse(std::list<int> & mylist);

int main(){

unsigned int i;
std::list<int> mylist;
mylist.push_back(1);
mylist.push_back(2);
/*mylist.push_back(3);
mylist.push_back(4);
mylist.push_back(5);
mylist.push_back(6);
mylist.push_back(7);*/
std::list<int> rever=reverse(mylist);
std::list<int>::iterator rit1;
for(rit1=mylist.begin();rit1!=mylist.end();++rit1){
	std::cout << ' ' << *rit1 <<" " <<std::endl;	

	}
}

std::list<int> reverse(std::list<int> & mylist){

	std::list<int>::iterator rit1;
	std::list<int>::reverse_iterator rit2;
	int a=0;
	int b=mylist.size();
 for (rit1=mylist.begin(),rit2=mylist.rbegin(); rit2!=mylist.rend() || rit1!=mylist.end(); ++rit2,++rit1)
    {

    	int temp;
    	a++;
    	b--;
    	if(a>b){
    		break;
    	}
    	temp=*rit1;
    	*rit1=*rit2;
    	*rit2=temp;
    
	}
	

return mylist;
}




