//File: team.cpp
//Purpose: Implementation of the team class
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "team.h"
#include "player.h"

//Read information about a team and parse through it

//Default constructor implementation
Team::Team(){
	team_name_= "";
	win_=0;
	loss_=0;
	tie_=0;
	winP_=0.0;
	goals_=0;
	penalities_=0;

}

Team::Team(std::string aTeamName,int aWin,int aLoss,int aTie,float aWinP,int aGoals,int aPenalities){
	//Parameter constructor
	team_name_= aTeamName;
	win_=aWin;
	loss_=aLoss;
	tie_=aTie;
	winP_=aWinP;
	goals_=aGoals;
	penalities_=aPenalities;
}

std::string Team::getTeamName() const{			//// getter and setter functions for Player Class

	return team_name_;
}
int Team::getWin() const{
	return win_ ;
}
int Team::getLoss() const{
	return loss_;
}
int Team::getTie() const{
	return tie_;
}
float Team::getWinP() const{
	return winP_;
}
int Team::getGoals() const{
	return goals_;
}
int Team::getPenalities() const{
	return penalities_;
}
void Team::setTeamName(std::string tN){
	team_name_=tN;
}
void Team::setWin(){
	win_=win_+ 1;
}
void Team::setLoss(){
	loss_=loss_+1;
}
void Team::setTie(){
	tie_=tie_+1;
}
void Team::setWinP(float wp){
	winP_=wp;
}
void Team::setGoals(){
	goals_=goals_+1;
}
void Team::setPenalities(){
	penalities_=penalities_+1;
}





