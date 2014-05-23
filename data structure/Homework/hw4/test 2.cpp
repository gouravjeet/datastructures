#include <iostream>
#include <list>

int main ()
{
  
  std::list<int> mylist;
  std::list<int> mylist1;
  std::list<int>::iterator it1,it2;
  mylist.push_back(10);
  mylist.push_back(11);
  mylist.push_back(12);
  mylist.push_back(13);
  mylist.push_back(14);
  mylist.push_back(15);
  mylist.pop_back();
  mylist.pop_front();
  it1=mylist.begin();
  it2=mylist.erase(it1);
  std::cout<<*it2;
  std::cout<<mylist.size();
  int x=mylist.front();
  std::cout<<x<<std::endl;
  it1=mylist.begin();
  //mylist.insert(it1,20,3);
  
  std::cout<<"-------------------------";
  mylist1.push_back(1);
  mylist1.push_back(2);
  mylist.merge(mylist1);
  for(std::list<int>::iterator it=mylist.begin();it!=mylist.end();it++)
  {
    std::cout<< *it<<" "<<std::endl;

  }
  std::cout<<"-------------------------";
  
  for(std::list<int>::iterator it=mylist.begin();it!=mylist.end();it++)
  {
  	std::cout<< *it<<" "<<std::endl;

  }

  return 0;
}
