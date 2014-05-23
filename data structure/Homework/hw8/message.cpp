#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "message.h"

Message::Message(const std::string &msg, Person *person){
	m_owner=person;
	m_message=msg;
};


bool Message::pass_message(Person *person){
	
	return true;
}