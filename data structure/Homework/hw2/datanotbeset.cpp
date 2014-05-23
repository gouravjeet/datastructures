//File: hw2update.cpp
//Compute player and team statistics
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "team.h"
#include "player.h"


void printTeamStats(std::vector<Team> & teamV,std::ifstream & in_str,std::ofstream & out_str);
void printPlayerStats(std::vector<Player> & playerV,std::ifstream & in_str,std::ofstream & out_str);


int main(int argc, char* argv[]){
	if(argc != 3){
		std::cerr << "Usage:\n "<<argv[0]<<"";
	}
	std::ifstream in_str(argv[1]);
	if(!in_str){
		std::cerr<<"Could not open"<<argv[1]<<"to read\n";// this will give error if the file doesnot open

	}

	std::cout << argv[1];
	std::ofstream out_str(argv[2]);
	if(!out_str){
		std::cerr<<"Could not open"<<argv[2]<<"to write\n";//this will give error if output stream does not open

	}

	std::string word;
	std::string teamx;
	std::string teamy;
	std::string playerx;
	std::string playery;
	std::string playerz;
	std::string wordgoal;

	
	
	std::string goalpenalty;
	std::vector<Team> teamV;
	std::vector<Player> playerV;
	Team teamObj1;
	Team teamObj2;

	Player playerObj1;
	Player playerObj2;
	Player playerObj3;

		while(in_str >> word)//Going into the string
		{

//============================================
			for(unsigned int a=0;a<word.length();a++)
			{
				if(word[a]==':')	//  the data of penalty and goal
				{
					in_str>>teamx;
				in_str>>goalpenalty;
				if(goalpenalty=="goal"){
					in_str>>playerx;
					in_str>>word;
					if(word=="(")
					{
						in_str>>playery;
						in_str>>word;
						if(word==")")
						{
							//only one player assited in goal
						}
						else{
							playerz=word;// two player assited in goal
							in_str>>word;
						}
					}
					else
					{
						//No player assisted in goal
					}
					

				}
				else if(goalpenalty=="penalty"){
					
					in_str>>playerx;
					in_str>>word;
					in_str>>word;



				}	
					
			std::cout<<teamx<<std::endl;
			std::cout<<teamy<<std::endl;
			std::cout<<playerx<<std::endl;
			std::cout<<playery<<std::endl;
			std::cout<<playerz<<std::endl;	
				}
				else
				{

				}
			}

//=====================================

			if(word=="Monday," || word=="Tuesday," || word=="Wednesday," || word=="Thursday," || word=="Friday," || word=="Saturday," || word=="Sunday,")	
			{
				in_str>>word;
				in_str>>word;
				in_str>>word;
				in_str>>teamx;//team 1
				
				in_str>>word;//at
				in_str>>teamy; //team2


			}
//==========================================			
			if(word=="PERIOD" )
			{
				in_str>>word;
				in_str>>word;
				in_str>>teamx;
				in_str>>goalpenalty;
				if(goalpenalty=="goal"){
					in_str>>playerx;
					in_str>>word;
					if(word=="(")
					{
						in_str>>playery;
						in_str>>word;
						if(word==")")
						{
							//only one player assited in goal
						}
						else{
							playerz=word;// two player assited in goal
							in_str>>word;
						}
					}
					else
					{
						//No player assisted in goal
					}
					

				}
				else if(goalpenalty=="penalty"){
					
					in_str>>playerx;
					in_str>>word;
					in_str>>word;



				}	
					
			std::cout<<teamx<<std::endl;
			std::cout<<teamy<<std::endl;
			std::cout<<playerx<<std::endl;
			std::cout<<playery<<std::endl;
			std::cout<<playerz<<std::endl;	

			}
//===========================================			
			if(word=="Overtime") {

			}

//============================================			
			if(word=="FINAL"){
				in_str>>teamx;
				in_str>>wordgoal;
				unsigned int valuex = atoi(wordgoal.c_str()); 
				in_str>>teamy;
				in_str>>wordgoal;	
				unsigned int valuey = atoi(wordgoal.c_str());
				std::cout<<teamx<<" "<<valuex<<std::endl;
				std::cout<<teamy<<" "<<valuey<<std::endl;


			}
//============================================			
		}	

}

//  ----------------------Declaration of print functions starts here
void printTeamStats(std::vector<Team> & teamV,std::ifstream & in_str,std::ofstream & out_str){
	
	out_str<<std::setw(20)<<std::left<<"Team Name"<<std::setw(10)<<std::right<<"W"<<std::setw(10)<<"L"
		   <<std::setw(10)<<"T"<<std::setw(10)<<"Win%"<<std::setw(10)<<"Goals"
		   <<std::setw(10)<<"Penalties"<<std::endl;
		for(unsigned int d=0;d<teamV.size();d++){
			
			//teamV[d].setWinP(float(100*((teamV[d].getWin())/(teamV[d].getWin()+teamV[d].getLoss()+teamV[d].getTie()))));
			teamV[d].setWinP(2.0);
			out_str<<std::setw(20)<<std::left<<teamV[d].getTeamName()
			<<std::right
			<<std::setw(10)<<teamV[d].getWin()
			<<std::setw(10)<<teamV[d].getLoss()
			<<std::setw(10)<<teamV[d].getTie()
			<<std::setw(10)<<teamV[d].getWinP()
			<<std::setw(10)<<teamV[d].getGoals()
			<<std::setw(10)<<teamV[d].getPenalities();
			out_str<<std::endl;

		}
	}


	void printPlayerStats(std::vector<Player> & playerV,std::ifstream & in_str,std::ofstream & out_str){
			
	 out_str<<std::setw(20)<<std::left<<"Player Name"<<std::setw(20)<<"Team"
			<<std::right
			<<std::setw(10)<<"Goals"
			<<std::setw(10)<<"Assists"
			<<std::setw(10)<<"Penalties"<<std::endl;
			
		for(unsigned int e=0;e<playerV.size();e++){
			out_str<<std::setw(20)<<std::left<<playerV[e].getPlayerName()
			<<std::setw(20)<<playerV[e].getTeam()
			<<std::right
			<<std::setw(10)<<playerV[e].getGoals()
			<<std::setw(10)<<playerV[e].getAssists()
			<<std::setw(10)<<playerV[e].getPenalities()
			<<std::endl;
		}

}


