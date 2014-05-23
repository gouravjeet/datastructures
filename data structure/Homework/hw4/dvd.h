#include <iostream>
#include <string>
#include <vector>
#include <list>
class DVD{
	public:
DVD();
DVD(std::string movie,int num);
//ACCESSORS
	std::string getMovieTitle() const;
	int getNumMovies() const;
	std::string get_name() const;
	bool available();
	void shipped();
//MODIFIERS
	void updateDVDcopies(int copies);
private:
//REPRESENTATION
	std::string movie_title;
	int num_copies;	
	int customer_copies;
};

