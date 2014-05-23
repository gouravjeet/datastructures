#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cassert>
#include "MersenneTwister.h"

#include "person.h"
#include "graph.h"
#include "message.h"


// ================================================================
// helper function for reading quoted messages

std::string read_quoted_string(std::istream &istr) {
  std::string answer;
  istr >> answer;
  // first character of first word must be double quote
  assert (answer[0] == '"');

  // check to see if it's just a quoted word
  if (answer[answer.size()-1] == '"') 
    return answer;

  // read each subsequent word
  while (1) {
    std::string s;
    istr >> s;
    // append with spaces between
    answer += ' ' + s;
    // stop when a word ends with another double quote
    if (answer[answer.size()-1] == '"')
      return answer;
  } 
}


// ================================================================

int main(int argc, char* argv[]) {
  
  // Open and check the input stream
  if (argc != 2) {
    std::cout << "Wrong number of arguments.\n";
    std::cout << "Usage:  " << argv[0] << " <graph-file>" << std::endl;
    return 1;
  }

  std::ifstream in_str(argv[1]);
  if (!in_str) {
    std::cout << "Bad file name: " << argv[1] << std::endl;
    return 1;
  }

  // We make two different pseudo-random number generators.
  // With a fixed seed, we will see the same sequence of numbers
  // everytime we run the program (very helpful for debugging).
  MTRand mtrand_fixed_seed(24);
  // Alternatively, we can let the seed be set from the computer
  // clock, so the number sequence will constantly change.
  MTRand mtrand_autoseed;

  // The main object
  Graph friend_graph;

  // temp variables for parsing
  std::string request, name1, name2;
  int count;
  
  // While there are more requests, determine the type of request and handle it. 
  while (in_str >> request) {

    // adding & removing people and adding & removing friendship links
    if (request == "add_person") {
      in_str >> name1;
      if (friend_graph.add_person(name1))
        std::cout << "Added person " << name1 << std::endl;
      else
        std::cout << "Error trying to add person " << name1 << std::endl;
    } else if (request == "remove_person") {
      in_str >> name1;
      if (friend_graph.remove_person(name1))
        std::cout << "Removed person " << name1 << std::endl;
      else 
        std::cout << "Error trying to remove person " << name1 << std::endl;
    } else if (request == "add_friendship") {
      in_str >> name1 >> name2;
      if (friend_graph.add_friendship(name1, name2)) 
        std::cout << "Linked friends " << name1 << " and " << name2 << std::endl;
      else
        std::cout << "Error trying to link friends " << name1 << " and " << name2 << std::endl;
    } else if (request == "remove_friendship") {
      in_str >> name1 >> name2;
      if (friend_graph.remove_friendship(name1, name2)) 
        std::cout << "Unlinked friends " << name1 << " and " << name2 << std::endl;
      else
        std::cout << "Error trying to unlink friends " << name1 << " and " << name2 << std::endl;
    } 

    // adding and passing messages
    else if (request == "add_message") {
      in_str >> name1;
      std::string msg = read_quoted_string(in_str);
      if (friend_graph.add_message(name1,msg)) 
        std::cout << "Added message " << msg << " to person " << name1 << std::endl;
      else
        std::cout << "Error trying to add message " << msg << " to person " << name1 << std::endl;
    } else if (request == "pass_messages") {
      // either use a fixed seed for repeatability for testing & debugging
      //friend_graph.pass_messages_randomly(mtrand_fixed_seed);
      // or the automatic seed for different results on subsequent runs
      friend_graph.pass_messages(mtrand_autoseed);
    } 

    // print the invitation list
    else if (request == "print_invite_list") {
      in_str >> name1 >> count;
      if (!friend_graph.print_invite_list(std::cout,name1,count))
        std::cout << "Error trying to print invitation list for person " << name1 << std::endl;
    } 

    // print a text version of the whole graph
    else if (request == "print") {
      friend_graph.print(std::cout);
    } else {
      std::cout << "Illegal input: " << request << std::endl;
    }
  }
  
  // The memory allocated for the graph is deleted when it goes out of scope.
  return 0;
}

// ================================================================
