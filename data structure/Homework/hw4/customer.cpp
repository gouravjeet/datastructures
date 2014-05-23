#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "customer.h"
Customer::Customer(){
	name="";
	num_movies=0;

}
Customer::Customer(std::string n,int num_m){
	name=n;
	num_movies=num_m;
	
	
}
	std::string Customer::get_name() const{
		return name;
	}
	int Customer::getNumMovies() const{
		return num_movies;
	}
	std::list<std::string> Customer::getMoviesList() const{
		return movies_list;
	}


bool Customer::has_max_num_movies(){
	if(movies_list.size()>=3){
		return true;
	}
	else{
		return false;
		}			
}	
// skip this customer if they already have 3 movies or if their
    // preference list is empty (no outstanding requests)
bool Customer::preference_list_empty(){
	//std::cout<<preference_list.begin();
	if(preference_list.empty())
		return true;
	else 
		return false;
}

std::list<std::string> Customer::get_preferences() const{
	return preference_list;
}
void Customer::set_preferences(std::string mov){
	preference_list.push_back(mov);
}
void Customer::receives(std::string movie_receiv){
	
	movies_list.push_back(movie_receiv);
	preference_list.remove(movie_receiv);
}