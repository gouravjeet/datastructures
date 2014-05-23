#include <iostream>
#include <string>
#include <vector>

class Player{
public:
	Player();
	Player(std::string aPlayerName,int aTeam,int aGoals,int aAssists,int aPenalities);
		//ACCESSORS
	std::string getPlayerName() const;
	std::string getTeam() const;
	int getGoals() const;
	int getAssists() const;
	int getPenalities() const;
	//MODIFIERS
	void setPlayerName(std::string aPlayerName);
	void setTeam(std::string aTeam);
	void setGoals();
	void setAssists();
	void setPenalities();
private:
	//REPRESENTATION
	std::string player_name_;
	std::string team_;
	int goals_;
	int assists_;
	int penalities_;
};