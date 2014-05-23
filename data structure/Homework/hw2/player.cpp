//File: player.cpp
//Purpose: Implementation of the Player class
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "team.h"
#include "player.h"


//Read information about a Player and parse through it
//Default constructor implementation

Player::Player(){
	player_name_= "";
	team_="";
	goals_=0;
	assists_=0;
	penalities_=0.0;
	
}
Player::Player(std::string aPlayerName,int aTeam,int aGoals,int aAssists,int aPenalities){
	//Parameter constructor
	player_name_= aPlayerName;
	team_=aTeam;
	goals_=aGoals;
	assists_=aAssists;
	penalities_=aPenalities;
	
}

std::string Player::getPlayerName() const{				// getter and setter functions for Player Class
	return player_name_;
}
std::string Player::getTeam() const{
	return team_;
}
int Player::getGoals() const{
	return goals_;
}
int Player::getAssists() const{
	return assists_;
}
int Player::getPenalities() const{
	return penalities_;
}
void Player::setPlayerName(std::string pn){
	player_name_=pn;
}
void Player::setTeam(std::string t){
	team_=t;
}
void Player::setGoals(){
	goals_=goals_+1;
}
void Player::setAssists(){
	assists_ = assists_ + 1;
}
void Player::setPenalities(){
	penalities_=penalities_ + 1;
}
