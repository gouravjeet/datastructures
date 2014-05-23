
#include <iostream>
#include <string>
#include <vector>

class Team{
public:
	Team();
	Team(std::string aTeamName,int aWin,int aLoss,int aTie,float aWinP,int aGoals,int aPenalities);
	
	//ACCESSORS
	std::string getTeamName() const;
	int getWin() const;
	int getLoss() const;
	int getTie() const;
	float getWinP() const;
	int getGoals() const;
	int getPenalities() const;
	//MODIFIERS
	void setTeamName(std::string aTeamName);
	void setWin();
	void setLoss();
	void setTie();
	void setWinP(float aWinP);
	void setGoals();
	void setPenalities(); 
private:
	//REPRESENTATION		(member variables)
	std::string team_name_;
	int win_;
	int loss_;
	int tie_;
	float winP_;
	int goals_;
	int penalities_;
};