//File: hw2.cpp
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
void updateTeamGoal(Team & teamObj1,std::vector<Team> & teamV,std::ifstream & in_str,std::ofstream & out_str);
void updateTeamPenalty(Team & teamObj1,std::vector<Team> & teamV,std::ifstream & in_str,std::ofstream & out_str);
void updatePlayerGoal(Player & playerObj1,std::vector<Player> & playerV,std::ifstream & in_str,std::ofstream & out_str);
void updatePlayerPenalty(Player & playerObj1,std::vector<Player> & playerV,std::ifstream & in_str,std::ofstream & out_str);
void updatePlayerAssists(Player & playerObj1,std::vector<Player> & playerV,std::ifstream & in_str,std::ofstream & out_str);
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
	std::string word1;
	std::string word2;
	std::string word3;
	std::string word4;
	std::string word5;
	std::string word6;
	std::string wordx;
	std::string wordy;
	std::string wordcheck;
	std::string wordm;

	
	
	std::vector<Team> teamV;
	std::vector<Player> playerV;
	std::vector<Team> tempTeam;
	std::vector<Player> tempPlayer;
	Team teamObj1;
	Team teamObj2;
	Player playerObj1;
	Player playerObj2;
	Player playerObj3;
	//std::cout<<"*";
	while(in_str >> word){//Friday,
		std::cout<<word<<std::endl;
		in_str>>word;//Nov
		std::cout<<word<<std::endl;
		in_str>>word;//9,
		std::cout<<word<<std::endl;
		in_str>>word;//2012
		std::cout<<word<<std::endl;
		in_str>>wordx;//Team1
		std::cout<<wordx<<std::endl;
		teamObj1.setTeamName(wordx);
		in_str>>word;//at
		std::cout<<word<<std::endl;
		in_str>>wordy;//Team2
		std::cout<<wordy<<std::endl;
		teamObj2.setTeamName(wordy);
		in_str>>word;//PERIOD
		std::cout<<word<<std::endl;
		in_str>>word5;//1
		std::cout<<word5<<std::endl;
		
		//in_str>>word;//Team1
		//Period 1
		//------------------------------------------------
		//												 |
		//												 |
		//												 |
		//------------------------------------------------
		in_str>>wordcheck;//13:14
		std::cout<<wordcheck<<std::endl;
		while(wordcheck !="FINAL")
		{

		
		in_str>>wordx;//Team1
		std::cout<<wordx<<std::endl;
		in_str>>word1;//Penalty or Goal
		std::cout<<word1<<std::endl;
		in_str>>word2;//Player Name who score goal or penalty
		std::cout<<word2<<std::endl;
		//std::cout << " wowowowo" << std::endl;
		
		if(wordx==teamObj1.getTeamName())
		{
			if(word1=="goal")
			{
				in_str>>word3;//  (
				std::cout<<word3<<std::endl;	
				in_str>>word4;//   Player who assists the goal
				std::cout<<word4<<std::endl;
				in_str>>word5; //  ) or 2nd player who assists the goal
				std::cout<<word5<<std::endl;
				teamObj1.setGoals();//Setting goals for the team
				if(word5==")"){
					
					playerObj1.setPlayerName(word2);
					playerObj1.setTeam(wordx);
					playerObj1.setGoals();
					playerObj2.setPlayerName(word4);
					playerObj2.setTeam(wordx);
					playerObj2.setAssists();
					updatePlayerGoal(playerObj1,playerV,in_str,out_str);
					updatePlayerAssists(playerObj1,playerV,in_str,out_str);
					

				}
				else{

					playerObj1.setPlayerName(word2);
					playerObj1.setTeam(wordx);
					playerObj2.setPlayerName(word4);
					playerObj2.setTeam(wordx);
					playerObj3.setPlayerName(word5);
					playerObj3.setTeam(wordx);
					playerObj1.setGoals();
					playerObj2.setAssists();
					playerObj3.setAssists();
					updatePlayerGoal(playerObj1,playerV,in_str, out_str);
					updatePlayerAssists(playerObj2,playerV,in_str, out_str);
					updatePlayerAssists(playerObj3,playerV,in_str, out_str);
					//updateTeamGoal(teamObj1,teamV,in_str,out_str);
					in_str>>word6;
				}
				
				

			}

			else if(word1=="penalty"){
				in_str>>word3; //time for which player will be out
				std::cout<<word3<<std::endl;	
				in_str>>word4;	//Reason for penalty
				std::cout<<word4<<std::endl;
				playerObj1.setPlayerName(word2);
				playerObj1.setTeam(wordx);
				updatePlayerPenalty(playerObj1,playerV,in_str, out_str);
				updateTeamPenalty(teamObj1,teamV,in_str,out_str);
				

			}
		
			
		}
		
		else if(wordx==teamObj2.getTeamName())
		{
				in_str>>word3;//  (
				std::cout<<word3<<std::endl;	
				in_str>>word4;//   Player who assists the goal
				std::cout<<word4<<std::endl;
				in_str>>word5; //  ) or 2nd player who assists the goal
				std::cout<<word5<<std::endl;
				teamObj1.setGoals();//Setting goals for the team
				if(word5==")"){
					
					playerObj1.setPlayerName(word2);
					playerObj1.setTeam(wordx);
					playerObj1.setGoals();
					playerObj2.setPlayerName(word4);
					playerObj2.setTeam(wordx);
					playerObj2.setAssists();
					updatePlayerGoal(playerObj1, playerV,in_str, out_str);
					updatePlayerAssists(playerObj1, playerV,in_str, out_str);
					teamObj2.setGoals();

				}
				else{

					playerObj1.setPlayerName(word2);
					playerObj1.setTeam(wordx);
					playerObj2.setPlayerName(word4);
					playerObj2.setTeam(wordx);
					playerObj3.setPlayerName(word5);
					playerObj3.setTeam(wordx);
					playerObj1.setGoals();
					playerObj2.setAssists();
					playerObj3.setAssists();
					updatePlayerGoal(playerObj1,playerV,in_str, out_str);
					updatePlayerAssists(playerObj2,playerV,in_str, out_str);
					updatePlayerAssists(playerObj3,playerV,in_str, out_str);
					updateTeamGoal(teamObj2,teamV,in_str,out_str);
					in_str>>word6;
				}
		}
		// Team Name--------------------------------------------
		in_str>>wordcheck;	
	}
		





















/*

		//Period 2 
		//------------------------------------------------
		//	While loop will check and will stop when it  |
		//	get Period word								 |
		//												 |
		//------------------------------------------------
		in_str>>wordm;//which period
		in_str>>word4;//time
		in_str>>wordx;//Team
		while(wordcheck !="PERIOD" && wordm!="3")
		{
		
		in_str>>word1;	//penalty/goal
		in_str>>word2;//player name
		
		
		if(wordx==teamObj1.getTeamName())
		{
			if(word1=="goal")
			{
				in_str>>word3;
				in_str>>word4;
				in_str>>word5;
				if(word5==")"){
					playerObj2.setAssists();
					playerObj2.setPlayerName(word4);
				}
				else{
					playerObj2.setPlayerName(word4);
					playerObj3.setPlayerName(word5);
					playerObj2.setAssists();
					playerObj3.setAssists();
				}
				teamObj1.setGoals();
				playerObj1.setTeam(word);
				playerObj1.setPlayerName(word2);
				playerObj1.setGoals();

			}
			else if(word1=="penalty"){
				in_str>>word3;
				in_str>>word4;
				teamObj1.setPenalities();
				playerObj1.setTeam(word);
				playerObj1.setPenalities();

			}
		}
		
		else if(wordx==teamObj2.getTeamName())
		{
			if(word1=="goal")
			{
				in_str>>word3;
				in_str>>word4;
				in_str>>word5;
				if(word5==")"){
					playerObj2.setAssists();
					playerObj2.setPlayerName(word4);
				}
				else{
					playerObj2.setPlayerName(word4);
					playerObj3.setPlayerName(word5);
					playerObj2.setAssists();
					playerObj3.setAssists();
				}

				teamObj2.setGoals();
				playerObj1.setTeam(word);
				playerObj1.setPlayerName(word2);
				playerObj1.setGoals();
			}
			else if(word1=="penalty"){
				in_str>>word3;
				in_str>>word4;

				teamObj2.setPenalities();
				playerObj1.setTeam(word);
				playerObj1.setPenalities();

			}
		}
		teamV.push_back(teamObj1);
		teamV.push_back(teamObj2);
		playerV.push_back(playerObj1);	
		
		in_str>>wordcheck;	
		in_str>>wordm;//which period
		}
		//Period 3--------------------------------------
		in_str>>wordcheck;//time
		while(wordcheck !="FINAL")
		{
		in_str>>wordx;//Team
		in_str>>word1;//penalty/Goal
		in_str>>word2;//player name
		
		
		if(wordx==teamObj1.getTeamName())
		{
			if(word1=="goal")
			{
				in_str>>word3;
				in_str>>word4;
				in_str>>word5;
				if(word5==")"){
					playerObj2.setAssists();
					playerObj2.setPlayerName(word4);
				}
				else{
					playerObj2.setPlayerName(word4);
					playerObj3.setPlayerName(word5);
					playerObj2.setAssists();
					playerObj3.setAssists();

				}
				teamObj1.setGoals();
				playerObj1.setTeam(word);
				playerObj1.setPlayerName(word2);
				playerObj1.setGoals();

			}
			else if(word1=="penalty"){
				in_str>>word3;
				in_str>>word4;
				teamObj1.setPenalities();
				playerObj1.setTeam(word);
				playerObj1.setPenalities();

			}
		}
		
		else if(wordx==teamObj2.getTeamName())
		{
			if(word1=="goal")
			{
				in_str>>word3;
				in_str>>word4;
				in_str>>word5;
				if(word5==")"){
					playerObj2.setAssists();
					playerObj2.setPlayerName(word4);
				}
				else{
					playerObj2.setPlayerName(word4);
					playerObj3.setPlayerName(word5);
					playerObj2.setAssists();
					playerObj3.setAssists();
				}

				teamObj2.setGoals();
				playerObj1.setTeam(word);
				playerObj1.setPlayerName(word2);
				playerObj1.setGoals();
			}
			else if(word1=="penalty"){
				in_str>>word3;
				in_str>>word4;

				teamObj2.setPenalities();
				playerObj1.setTeam(word);
				playerObj1.setPenalities();

			}
		}
		teamV.push_back(teamObj1);
		teamV.push_back(teamObj2);
		playerV.push_back(playerObj1);	
		
		in_str>>wordcheck;	

		}
	*/	
		//------------------------------------------------
		//Overtime can be used in condition of a tie	 |
		//------------------------------------------------
	
	if(wordcheck=="FINAL")
		{
			in_str>>word;
			
			in_str>>word;
			unsigned int value = atoi(word.c_str()); 	
			teamObj1.setGoals();
			in_str>>word;
		
			in_str>>word;	
			value = atoi(word.c_str()); 	
			teamObj1.setGoals();
		}
		
		
	}
	printPlayerStats(playerV,in_str,out_str);
	printTeamStats(teamV,in_str,out_str);
//Test
	/*
	Team teamObj3;
	Team teamObj4;
	Player playerObj10;
	Player playerObj11;

	teamObj3.setGoals();
	teamObj3.setTeamName("Dara University");
	teamObj3.setPenalities();
	teamObj3.setWin();
	teamObj3.setLoss();
	teamObj3.setTie();

	teamObj4.setGoals();
	teamObj4.setTeamName("Yuvi University");
	teamObj4.setPenalities();
	teamObj4.setWin();
	teamObj4.setLoss();
	teamObj4.setTie();

	playerObj10.setPlayerName("Chetan");
	playerObj10.setTeam("Dara University");
	playerObj10.setGoals();
	playerObj10.setPenalities();
	playerObj10.setAssists();

	playerObj11.setPlayerName("Krishna");
	playerObj11.setTeam("Yuvi University");
	playerObj11.setGoals();
	playerObj11.setPenalities();
	playerObj11.setAssists();

	playerV.push_back(playerObj10);
	playerV.push_back(playerObj11);
	printPlayerStats(playerV,in_str,out_str);

	teamV.push_back(teamObj3);
	teamV.push_back(teamObj4);
	printTeamStats(teamV,in_str,out_str);
	Player playerObj5;*/

}

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

	//void setGoalVector
//-------------------------Updating goal-----------------------------------
	//Team Update when adding goal
			void updateTeamGoal(Team & teamObj1,std::vector<Team> & teamV,std::ifstream & in_str,std::ofstream & out_str){	
				for(unsigned int h=0;h<teamV.size();h++)
				{
					if(teamObj1.getTeamName()==teamV[h].getTeamName()){
						//tempTeam=teamV[h];
						teamV[h].setGoals();
						//teamV.push_back(teamV[h]);


					}
					else{

						teamV.push_back(teamObj1);

						}

				}
			}	
	//Team update when adding penalty
				void updateTeamPenalty(Team & teamObj1,std::vector<Team> & teamV,std::ifstream & in_str,std::ofstream & out_str){
					for(unsigned int h=0;h<teamV.size();h++)
					{
						if(teamObj1.getTeamName()==teamV[h].getTeamName()){
							//tempTeam=teamV[h];
							teamV[h].setPenalities();
							//teamV.push_back(teamV[h]);

						}
						else{

							teamV.push_back(teamObj1);
							}

					}
				}	
	//Player update when adding goal 		
				void updatePlayerGoal(Player & playerObj1,std::vector<Player> & playerV,std::ifstream & in_str,std::ofstream & out_str){
					
					for(unsigned int j=0;j<playerV.size();j++)
					{

						if(playerObj1.getPlayerName()==playerV[j].getPlayerName()){
							//tempTeam=teamV[h];
							playerV[j].setGoals();
							//playerV.push_back(playerV[j]);

						}
						else{

							playerV.push_back(playerObj1);
							}

					}
				}	
	//Player update when adding penalty
	//			
				void updatePlayerPenalty(Player & playerObj1,std::vector<Player> & playerV,std::ifstream & in_str,std::ofstream & out_str){
					for(unsigned int j=0;j<playerV.size();j++)
					{
						if(playerObj1.getPlayerName()==playerV[j].getPlayerName()){
							//tempTeam=teamV[h];
							playerV[j].setPenalities();
						//	playerV.push_back(playerV[j]);

						}
						else{

							playerV.push_back(playerObj1);
							}
					}
				}
	//Player update when adding assists
				void updatePlayerAssists(Player & playerObj1,std::vector<Player> & playerV,std::ifstream & in_str,std::ofstream & out_str){
					for(unsigned int j=0;j<playerV.size();j++)
					{
						if(playerObj1.getPlayerName()==playerV[j].getPlayerName()){
							//tempTeam=teamV[h];
							playerV[j].setAssists();
						//	playerV.push_back(playerV[j]);

						}
						else{

							playerV.push_back(playerObj1);
							}
					}
				}
		//---------------------------------------------
