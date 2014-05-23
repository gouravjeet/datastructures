#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include "graph.h"
#include "person.h"
#include "message.h"
#include "MersenneTwister.h"
Graph::Graph(){

};
Graph::~Graph(){
	for(int i=0;i<m_people.size();i++){
		delete m_people[i];
	}
	for (int j = 0; j < m_messages.size(); j++)
	{
		delete m_messages[j];
	}
}

Person* Graph::find_person(const std::string &name) const{
	for (std::vector<Person*>::const_iterator p = m_people.begin(); p != m_people.end(); ++p){
		if((*p)->get_name()==name){
			
			return *p;
		}
	}
	return NULL;
}
bool Graph::add_person(const std::string& person_name){
	for (std::vector<Person*>::const_iterator p = m_people.begin(); p != m_people.end(); ++p){
		if((*p)->get_name()==person_name){
			return false;
		}
	}		
			Person* p=new Person(person_name);
			m_people.push_back(p);
			return true;	
	
	
}
bool Graph::remove_person(const std::string& person_name){
	bool remove_person=false;
	std::string name_find="";
	std::list<Person*> p_list;
	std::list<Message*> m_list;
	Person* pp;
	for (std::vector<Person*>::iterator p1 = m_people.begin(); p1 != m_people.end(); ++p1){
		if((*p1)->get_name()==person_name){
			remove_person=true;			
			p_list=((*p1)->get_friends());
			m_list=((*p1)->get_messages());
			name_find=((*p1)->get_name());
			pp=*p1;
			//m_people.erase(p1);
			// we need to first remove message and friends of that person and then delete that person
			//delete the message from graph and delete the person from other people friend list
			
		}
	}

// Iterating through the loop to find out where that person is in other's list
	if(remove_person==true){
			for (std::vector<Message*>::iterator mm = m_messages.begin(); mm != m_messages.end(); ++mm){
				if((((*mm)->get_owner())->get_name())==name_find){
					delete *mm;
					mm=m_messages.erase(mm);
					
				}
			
			}
			
			//deleting the message from the list of messages of graph
	for (std::vector<Person*>::iterator pm = m_people.begin(); pm != m_people.end(); ++pm){
				if(((*pm)->get_name())==person_name){
					
					delete *pm;
					pm=m_people.erase(pm);

				}
			}
			for(int i=0;i<m_people.size();i++){
				if(m_people[i]->get_name()!=person_name){
					m_people[i]->remove_friend(pp);
					//delete m_people[i];
				}
			}
		for (std::vector<Person*>::iterator p4 = m_people.begin(); p4 != m_people.end(); ++p4){
				std::list<Person *> person_lst=((*p4)->get_friends());
				for (std::list<Person *>::iterator itr = person_lst.begin(); itr != person_lst.end(); ++itr){
					if(((*itr)->get_name())==person_name){
						//std::cout<<"&&"<<person_name<<std::endl;
						delete *itr;
						itr=person_lst.erase(itr);
						
						
						break;
					}

				}
			}	
		
		
	//std::cout<<"**";		
	return true;
	}


	return false;
}
bool Graph::add_friendship(const std::string& person_name1, const std::string& person_name2){
	if(find_person(person_name1) && find_person(person_name2) ){
		if(person_name1==person_name2){
			return false;
		}

		Person* Person1 =find_person(person_name1);
		Person* Person2 =find_person(person_name2);	
		if(Person1->is_friend(Person2)){
			return false;
		}
		return Person1->add_friend(Person2);
			
	}
	return false;
}
bool Graph::remove_friendship(const std::string& person_name1, const std::string& person_name2){
	if(find_person(person_name1) && find_person(person_name2) ){
		Person* Person1 =find_person(person_name1);
		Person* Person2 =find_person(person_name2);	
		if(Person1->is_friend(Person2)){
			return Person1->remove_friend(Person2);	
			
		}
		return false;
	}
	return false;
}
bool Graph::add_message(const std::string& person_name, const std::string& message){
	if(person_name!="" && message!=""){
	if(find_person(person_name)){
		Person* Person1 =find_person(person_name);
		const std::list<Message*> mes_ls=((Person1)->get_messages());
		for (std::list<Message *>::const_iterator it5 = mes_ls.begin(); it5 != mes_ls.end(); ++it5){
			if((*it5)->get_message()==person_name){
				return false;
			}
		}
		Message* m=new Message(message,Person1);
		m_messages.push_back(m);
		return Person1->add_message(m);
			
	}
	else 
		return false;
	}
	else{
		return false;
	}
}
void Graph::pass_messages(MTRand &mtrand){
	

	for (std::vector<Person*>::const_iterator p2 = m_people.begin(); p2 != m_people.end(); ++p2){
		std::list<Person*> friends=((*p2)->get_friends());
		std::list<Message*> messages_lst=((*p2)->get_messages());
		
		//std::cout<<"size"<<friends.size()<<std::endl;
		if(messages_lst.size()==0)
		{
			continue;
		}
		//std::cout<<"Person"<<(*p2)->get_name()<<std::endl;
		//for (std::list<Message *>::const_iterator it1 = messages_lst.begin(); it1 != messages_lst.end(); ++it1){
			
					int random_num=mtrand.randInt(friends.size());
					//std::cout<<"random number generated"<<random_num<<std::endl;

					if(random_num==0)
					{
						continue;
					}
					
					else{
						std::list<Person*>::const_iterator it3=friends.begin();
						std::list<Message *>::const_iterator it1 = messages_lst.begin();
							for(int i=0;i<random_num-1;i++){
							it3++;
							}
					
						//Person* p1=*it3;
						std::string pers=(*it3)->get_name();
					//	std::cout<<"person"<<pers<<std::endl;

						const std::string z=((*it1)->get_message());
						//std::cout<<z;
						bool a=add_message(pers,z);
						bool b=((*p2)->remove_message(*it1));
						
					}
					
					// find the random number from the friends list and send the message to that number	
					
					
					
					// we need to add the message into the graph also and that will call message of person.
					// We need to change the owner of the function also
					
					//continue;
		//}			
	}
	
}
void Graph::print(std::ostream &ostr) const{
		std::cout<<std::endl;
		for (std::vector<Person*>::const_iterator p = m_people.begin(); p != m_people.end(); ++p){
			ostr<<((*p)->get_name())<<std::endl;
			ostr<<"  friends: ";
			std::list<Person*> m_fr=((*p)->get_friends());
			for (std::list<Person*>::const_iterator it2 = m_fr.begin(); it2 != m_fr.end(); ++it2){
				ostr<<((*it2)->get_name())<<" ";
			}
			ostr<<std::endl;
			ostr<<"  messages: ";
			std::list<Message*> msg=((*p)->get_messages());
			for (std::list<Message *>::const_iterator it1 = msg.begin(); it1 != msg.end(); ++it1){
				ostr<<((*it1)->get_message())<<" ";
			}
			ostr<<std::endl;
		}
		ostr<<std::endl;
}
void Graph::invite_friends(std::vector<std::string> & per_invite,int n,std::string name) const
{
		std::list<Person*> list_m;
		if(n==0){
			return;
		}
		for(int i=0;i<m_people.size();i++){
				if(m_people[i]->get_name()==name){
					list_m=m_people[i]->get_friends();
					break;
				}
			}
		for (std::list<Person*>::iterator it_invite = list_m.begin(); it_invite != list_m.end(); ++it_invite)
			{	
				per_invite.push_back((*it_invite)->get_name());
				name=(*it_invite)->get_name();
				invite_friends(per_invite,n-1,name);
				
			}


	}
bool Graph::print_invite_list(std::ostream &ostr, const std::string &name, int n) const{
	std::vector<std::string> per_invite;	
	
	invite_friends(per_invite,n,name);	
	std::sort(per_invite.begin(),per_invite.end());

	
	std::cout<<"Invite list of "<<name <<" "<< n<< ": ";
	std::string previous="";

	for(int h=0;h<per_invite.size();h++){
		if(previous==""){
			previous=per_invite[h];
		
		}		

		else if(per_invite[h]==previous){
			
			continue;
		}
	
		
			std::cout <<per_invite[h]<<" ";
			previous=per_invite[h];
		
		
	}
	std::cout<<std::endl;
												// need to check it is not added twice
	return true;

} 