// ==================================================================
// Important Note: You are encouraged to read through this provided
//   code carefully and follow this structure.  You may modify the
//   file as needed to complete your implementation.
// ==================================================================

#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <cassert>
#include <cstdlib>
#include "dvd.h"
#include "customer.h"
// several type defs to keep things neat
// (hint, these are STL lists)
typedef std::list<DVD> inventory_type;
typedef std::list<Customer> customers_type;
typedef std::list<std::string> preference_type;


// ==================================================================

// Helper function prototypes
std::string read_customer_name(std::istream &istr);
std::string read_dvd_name(std::istream &istr);
inventory_type::iterator find_DVD(inventory_type &inventory, const std::string &dvd_name);
customers_type::iterator findCustomer(customers_type &customers, const std::string &customer_name);
 preference_type::iterator findPrefernceList(preference_type & preferences,const std::string &dvd_name);
// The main algorithm for DVD distribution
void shipping_algorithm(inventory_type &inventory, customers_type &customers, std::ostream &ostr);

// ==================================================================


void usage(const char* program_name) {
  std::cerr << "Usage: " << program_name << " <input_file> <output_file>" << std::endl;
  std::cerr << " -or-  " << program_name << " <input_file> <output_file> --analysis" << std::endl;
  std::cerr << " -or-  " << program_name << " <input_file> <output_file> --improved" << std::endl;
  std::cerr << " -or-  " << program_name << " <input_file> <output_file> --improved --analysis" << std::endl;
  exit(1);
}


int main(int argc, char* argv[]) {

  if (argc < 3 || argc > 5) {
    usage(argv[0]);
  }

  // open input and output file streams
  std::ifstream istr(argv[1]);
  if (!istr) {
    std::cerr << "ERROR: Could not open " << argv[1] << " for reading." << std::endl;
    usage(argv[0]); 
  }
  std::ofstream ostr(argv[2]);
  if (!ostr) {
    std::cerr << "ERROR: Could not open " << argv[2] << " for writing." << std::endl;
    usage(argv[0]); 
  }

  // optional parameters for extra credit
  bool use_improved_algorithm = false;
  bool print_analysis = false;
  for (int i = 3; i < argc; i++) {
    if (std::string(argv[i]) == "--improved") {
      use_improved_algorithm = true;
    } else if (std::string(argv[i]) == "--analysis") {
      print_analysis = true;
    } else {
      usage(argv[0]);
    }
  }


  // stores information about the DVDs
  inventory_type inventory;
  // stores information about the customers
  customers_type customers;
  // Inventory 
  inventory_type::iterator inventory_itr;
   

  // read in and handle each of the 8 keyword tokens
  std::string token;
  while (istr >> token) {
    if (token == "dvd") {
      std::string dvd_name = read_dvd_name(istr);
      inventory_itr=find_DVD(inventory,dvd_name);
      //inventory_type::iterator itr ;                                              
      int copies;
      istr >> copies;    
      DVD objDVD;
      objDVD=DVD(dvd_name,copies);                                                    
          if(inventory_itr==inventory.end()){  
            inventory.push_back(objDVD);//Adding the element to the end of list      
            if(copies>1){
                ostr<< copies <<" copies of "<< dvd_name<<" added"<<std::endl; 
             
            }
            else{
            ostr<< copies <<" copy of "<< dvd_name<<" added"<<std::endl; 
            
            }
            
          }
          else{

              (inventory_itr)->updateDVDcopies(copies);
             
          }
      
       

      /* YOU MUST FINISH THIS IMPLEMENTATION */
      
    } 
     else if (token == "customer") {
      std::string customer_name = read_customer_name(istr);
      customers_type::iterator customer_itr;
      
      std::string nameN;
      //preferences_itr=preferences.begin();
      int num_movies;
      istr >> num_movies;                  
      Customer custObj=Customer(customer_name,num_movies);
      
      
      
      //customers.push_back(custObj);
      
    
                        //std::cout<<custObj.get_name();
                     for (int i = 0; i < num_movies; i++) 
                     {                    // A list that loop through to get all the movies
                           preference_type::iterator preferences_itr;
                           preference_type preferences;
                           preference_type pref;
                          std::string dvd_name = read_dvd_name(istr);
                         inventory_itr=find_DVD(inventory,dvd_name);
                          if(inventory_itr==inventory.end()){
                       
                            ostr <<"WARNING: No movie named "<<dvd_name <<" in the inventory"<<std::endl;
                          }
                          else{
                            
                            pref=custObj.get_preferences();
                            preference_type::iterator preferences_itr=findPrefernceList(pref,dvd_name);
                            if(preferences_itr==pref.end()){
                              custObj.set_preferences(dvd_name);
                            }
                            else{
                              ostr<<"WARNING: Duplicate movie "<< dvd_name<<" on preference list!"<<std::endl;
                            }
                          }//else
                        
                        }//for            
      customer_itr=findCustomer(customers,customer_name);
      if(customer_itr==customers.end()){                   
            customers.push_back(custObj);
            ostr<<"new customer: "<< customer_name<<std::endl;
      }// if part -that it is a new customer
      else{ 
                ostr<<"WARNING: Already have a customer named "<<customer_name <<std::endl;
                istr>>num_movies;
                for (int i = 0; i < num_movies; i++) {
                std::string dvd_name = read_dvd_name(istr);
                }
    }//else for inside loop

                                                                               


} 
            else if (token == "ship") {

      shipping_algorithm(inventory,customers,ostr);
      
    } else if (token == "return_oldest") {
      std::string customer_name = read_customer_name(istr);
      customers_type::iterator customer_itr;
      customer_itr=findCustomer(customers,customer_name);
      if(customer_itr==customers.end()){
        ostr<<" WARNING: No customer named "<< customer_name<<std::endl;
      }
      else{
      std::list<std::string> ls=customer_itr->getMoviesList();
          if(ls.size()==0){
            ostr<<"Specified customer doesnot have any DVDs"<<std::endl;
          }
          else{
        
          ostr<<customer_name<< " returns " << ls.front()<<std::endl;
          ls.pop_front();   
          }
      }
      /* YOU MUST FINISH THIS IMPLEMENTATION */

    } else if (token == "return_newest") {
      std::string customer_name = read_customer_name(istr);
      customers_type::iterator customer_itr;
      customer_itr=findCustomer(customers,customer_name);
      if(customer_itr==customers.end()){
        ostr<<" WARNING: No customer named "<< customer_name<<std::endl;
      }
      else{
      std::list<std::string> ls=customer_itr->getMoviesList();
          if(ls.size()==0){
            ostr<<"Specified customer doesnot have any DVDs"<<std::endl;
          }
          else{
          ostr<<customer_name<< " returns " << ls.back()<<std::endl;   
          ls.pop_back();
          }
      }
      /* YOU MUST FINISH THIS IMPLEMENTATION */

    } else if (token == "print_customer") {
      std::string customer_name = read_customer_name(istr);
      customers_type::iterator customer_itr;
      preference_type preferences;
      preference_type movies;

      customer_itr=findCustomer(customers,customer_name);
      if(customer_itr==customers.end()){
         ostr<<" WARNING: No customer named "<< customer_name<<std::endl;
      }
      else{
      
            std::list<std::string> ls=customer_itr->getMoviesList();
            ostr<<customer_name<<" has "<< ls.size()<<" movies:"<<std::endl;
                  for(preference_type::iterator preferences_itr=movies.begin();preferences_itr!=movies.end();preferences_itr++){

                    ostr<<"   " <<(*preferences_itr)<<std::endl;
                  }
            std::list<std::string> ls2=customer_itr->get_preferences();
            if(ls2.size()==0){

            } 
            else{ 
            ostr<<"  preference list:"<<std::endl;
                  for(preference_type::iterator preferences_itr=preferences.begin();preferences_itr!=preferences.end();preferences_itr++){
                    
                    ostr<<"    " <<(*preferences_itr)<<std::endl;
                  }//for
            }//else
      }

      /* YOU MUST FINISH THIS IMPLEMENTATION */

    } else if (token == "print_dvd") {
      std::string dvd_name = read_dvd_name(istr);
      inventory_type::iterator itr2=find_DVD(inventory,dvd_name);
      if(itr2==inventory.end()){
        ostr << "WARNING: No movie named " << dvd_name << " in the inventory" << std::endl;
      }
      else{
        ostr<<(itr2)->get_name();
      }


      /* YOU MUST FINISH THIS IMPLEMENTATION */

    } else if (token == "add_preference") {
      std::list<std::string> ls;
      preference_type preferences;
      preference_type movies;
      inventory_type::iterator inventory_itr;
      std::string customer_name = read_customer_name(istr);
      std::string dvd_name = read_dvd_name(istr);
      inventory_itr=find_DVD(inventory,dvd_name);
      if(inventory_itr==inventory.end())
      {
        ostr <<"WARNING: No movie named "<<dvd_name <<" in the inventory"<<std::endl;
      }
        // movie is not in the inventory
      
      for(customers_type::iterator customer_itr=customers.begin();customer_itr!=customers.end();++customer_itr){
         if(customer_itr==customers.end()){
                   ostr<<" WARNING: No customer named "<< customer_name<<std::endl;//no customer with this name is there
                }
          else{
                    ls=customer_itr->get_preferences();
                    for(preference_type::iterator preferences_itr=ls.begin();preferences_itr!=ls.end();++preferences_itr){
                          if((*preferences_itr)==dvd_name)
                          {
                            ostr<<"Customer already has this movie in the preference order"<<std::endl;
                          }
                          else{
                              (customer_itr)->set_preferences(dvd_name);
                          }
                     }

                           
               }    
      }
      /* YOU MUST FINISH THIS IMPLEMENTATION */

    } else {
      ostr<< "ERROR: Unknown token " << token << std::endl;
      exit(1);
    }
  }
   


}


// ==================================================================
//Check for duplicate values in the list
bool dupliVal(){
  return true;
}

// A helper function to check movies is preference list of a customer
 preference_type::iterator findPrefernceList(preference_type & preferences,const std::string &dvd_name){
  for(preference_type::iterator preferences_itr=preferences.begin();preferences_itr!=preferences.end();++preferences_itr)
  {
    if(dvd_name==(*preferences_itr)){
      return preferences_itr;
    }  
   
  }
  return preferences.end();
  
 }

//A helper function to find customer will check whether the customer is in the customer list
customers_type::iterator findCustomer(customers_type & customers, const std::string &customer_name){
  for(customers_type::iterator customer_itr=customers.begin();customer_itr!=customers.end();customer_itr++){
    if(customer_itr->get_name() == customer_name){
      return customer_itr;
    }
  }
  return customers.end();
}

// A customer name is simply two strings, first & last name
std::string read_customer_name(std::istream &istr) {
  std::string first, last;
  istr >> first >> last;
  return first + " " + last;
}


// A movie name is one or more strings inside of double quotes
std::string read_dvd_name(std::istream &istr) {
  std::string token;
  istr >> token;
  assert (token[0] == '"');
  std::string answer = token;
  while (answer[answer.size()-1] != '"') {
    istr >> token;
    answer += " " + token;
  }
  return answer;
}


// A helper function to find a DVD from the inventory
inventory_type::iterator find_DVD(inventory_type &inventory, const std::string &dvd_name) {
  for (inventory_type::iterator inventory_itr = inventory.begin(); 
       inventory_itr != inventory.end(); inventory_itr++) {
    if (inventory_itr->get_name() == dvd_name) {
      return inventory_itr;
    }
  }
  // if the DVD is not found, return the .end() iterator
  return inventory.end();
}


// ==================================================================

//
// A basic algorithm for determining which movies to ship to each customer
//
void shipping_algorithm(inventory_type &inventory, customers_type &customers, std::ostream &ostr) {

     //********************************************************
     //UNCOMMENT THIS WHEN YOU ARE READY TO WORK ON INTEGRATION
     //********************************************************

  ostr << "Ship DVDs" << std::endl;

  // Loop over the customers in priority order
  //
  // Note that we edit the customers list as we go, to add customers
  // to the back of the list if they receive a DVD.  This allows a
  // customer to receive multiple DVDs in one shipment cycle, but only
  // after all other customers have had a chance to receive DVDs.
  //
  customers_type::iterator customer_itr = customers.begin();
  while (customer_itr != customers.end()) {

    // skip this customer if they already have 3 movies or if their
    // preference list is empty (no outstanding requests)
    
    if (customer_itr->has_max_num_movies() || customer_itr->preference_list_empty()) {
      // move on to the next customer
      customer_itr++;
     
      continue;
    }

    // a helper flag variable
    bool sent_dvd = false;
 
    // loop over the customer's preferences
    const preference_type &preferences = customer_itr->get_preferences();
    for (preference_type::const_iterator preferences_itr = preferences.begin(); 
         preferences_itr != preferences.end(); preferences_itr++) {

      // locate this DVD in the inventory
      inventory_type::iterator inventory_itr = find_DVD(inventory,*preferences_itr);

      if (inventory_itr != inventory.end() && inventory_itr->available()) { 

        // if the DVD is available, ship it to the customer!
        ostr << "  " << customer_itr->get_name() << " receives " << *preferences_itr << std::endl;
        inventory_itr->shipped();
        customer_itr->receives(*preferences_itr);
        
        // move this customer to the back of the priority queue
        // they will get a chance to receive another DVD, but only
        // after everyone else gets a chance
        customers.push_back(*customer_itr);
        customer_itr = customers.erase(customer_itr);

        // after setting the flag to true, leave the iteration over preferences
        sent_dvd = true;        
        break;
      }
    }

    // if no DVD was sent to this customer, then we move on to the next customer 
    // (do not change this customer's priority for tomorrow's shipment)
    if (!sent_dvd) {
      customer_itr++;
    }
  }

  

}

// ==================================================================
