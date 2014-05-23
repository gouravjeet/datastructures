#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "dvd.h"

//Paramterized constructor of DVD class
DVD::DVD(){
	movie_title="";
	num_copies=0;
};
DVD::DVD(std::string movie,int num){
	movie_title=movie;
	num_copies=num;
}
int DVD::getNumMovies() const{
	return num_copies;
}
std::string DVD::getMovieTitle() const{
	return movie_title;
}

void DVD::updateDVDcopies(int copies){
	num_copies=num_copies + copies;
}
std::string DVD::get_name() const{
	return movie_title;
}
bool DVD::available(){
	
	if(num_copies>0)
	return true;
	else
	return false;	
}
void DVD::shipped(){
	customer_copies=customer_copies+1;
	num_copies=num_copies-1;
}