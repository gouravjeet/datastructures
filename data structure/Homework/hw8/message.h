#ifndef _message_h_
#define _message_h_

#include <string>
#include "person.h"

// ================================================================
// Messages are passed between people.  A person can only pass a
// message to someone they consider to be their friend.  A message
// thus has a current owner.

class Message {

public:

  // CONSTRUCTOR
  Message(const std::string &msg, Person *person);
  
  // ACCESSORS
  const std::string& get_message() const { return m_message; }
  Person* get_owner() const { return m_owner; }

  // MODIFIER 
  // The message is tranferred to the specified new owner.  The
  // function returns false if the operation was not successfully
  // completed.
  bool pass_message(Person *person);

private:

  // REPRESENTATION
  Person* m_owner;
  std::string m_message;

};

// ================================================================

#endif
