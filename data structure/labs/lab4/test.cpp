#include <iostream>
#include <list>

int main ()
{
  
  std::list<int> mylist;
  mylist.push_back(10);
  std::cout<<"*";
  for(std::list<int>::iterator it=mylist.begin();it!=mylist.end();it++)
  {
  	std::cout<< *it<<" ";


  }
  
  return 0;
}
