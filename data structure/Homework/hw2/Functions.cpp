//File: Functions.cpp
//Various functions such as print function
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "team.h"
#include "player.h"

void printTeamStats(std::vector<Team> teamV,std::ifstream & in_str,std::ofstream & out_str){
	out_str<<"Team Name"<<std::setw(5)<<"W"<<std::setw(5)<<"L"<<std::setw(5);
	out_str<<"T"<<std::setw(5)<<"Win%"<<std::setw(5)<<"Goals"<<std::setw(5);
	out_str<<"Penalties"<<std::endl;
	for(unsigned int d=0;d<teamV.size();d++){
		
		out_str<<teamV[d].getTeamName();
		out_str<<std::setw(5);
		out_str<<teamV[d].getWin();
		out_str<<std::setw(5);
		out_str<<teamV[d].getLoss();
		out_str<<std::setw(5);
		out_str<<teamV[d].getTie();
		out_str<<std::setw(5);
		teamV[d].setWinP(100*((teamV[d].getWin())/(teamV[d].getWin()+teamV[d].getLoss()+teamV[d].getTie())));
		out_str<<teamV[d].getWinP();
		out_str<<std::setw(5);
		out_str<<teamV[d].getGoals();
		out_str<<std::setw(5);
		out_str<<teamV[d].getPenalities();
		out_str<<std::endl;


	}

}
void printPlayerStats(std::vector<Player> playerV,std::ifstream & in_str,std::ofstream & out_str){
	out_str<<"Player Name"<<std::setw(5)<<"Team"<<std::setw(5)<<"Goals"<<std::setw(5);
	out_str<<"Assists"<<std::setw(5)<<"Penalties"<<std::endl;	
	for(unsigned int e=0;e<playerV.size();e++){
		out_str<<playerV[e].getPlayerName();
		out_str<<std::setw(5);
		out_str<<playerV[e].getTeam();
		out_str<<std::setw(5);
		out_str<<playerV[e].getGoals();
		out_str<<std::setw(5);
		out_str<<playerV[e].getAssists();
		out_str<<std::setw(5);
		out_str<<playerV[e].getPenalities();
		out_str<<std::endl;
	}

}