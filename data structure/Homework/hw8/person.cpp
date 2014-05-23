#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "person.h"


bool Person::is_friend(Person* person) const{
	for (std::list<Person *>::const_iterator it = m_friends.begin(); it != m_friends.end(); ++it){
		if((*it)->get_name()==person->get_name()){
			return true;
		}
		return false;
	}
	return false;
}
bool Person::add_friend(Person *person){
	m_friends.push_back(person);
	return true;
}
bool Person::remove_friend(Person* person){
	m_friends.remove(person);
	return true;
}
bool Person::add_message(Message *message){
	m_messages.push_back(message);
	return true;
}
bool Person::remove_message(Message *message){
	m_messages.remove(message);
	return false;
}
