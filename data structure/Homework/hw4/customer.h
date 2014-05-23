#include <iostream>
#include <string>
#include <vector>
#include <list>
class Customer{
public:
Customer();	
Customer(std::string n,int num_m);
//ACCESSORS
	std::string get_name() const;
	
	int getNumMovies() const;
	std::list<std::string> getMoviesList() const;
	std::list<std::string> get_preferences() const;
//MODIFIERS
	void set_name();
	
	void setNumMovies();
	void setMoviesList();
	bool has_max_num_movies();
	bool preference_list_empty();
	void set_preferences(std::string mov);
	void receives(std::string movie_receiv);
	
	
private:
//REPRESENTATION
	std::string name;
	int num_movies;
	std::list<std::string> movies_list;
	std::list<std::string> preference_list;
	
};

