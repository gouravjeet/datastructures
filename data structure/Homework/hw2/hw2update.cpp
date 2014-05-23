//File: hw2update.cpp
//Compute player and team statistics
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "team.h"
#include "player.h"// we need to include the h file of player and team so that it can be used.

// Prototype for functions 
void printTeamStats(std::vector<Team> & teamV,std::ifstream & in_str,std::ofstream & out_str);
void printPlayerStats(std::vector<Player> & playerV,std::ifstream & in_str,std::ofstream & out_str);
void updateTeamGoal(Team & teamObj1,std::vector<Team> & teamV,std::ifstream & in_str,std::ofstream & out_str);
void updateTeam(Team & teamObj1,std::vector<Team> & teamV,std::ifstream & in_str,std::ofstream & out_str);
void updateTeamPenalty(Team & teamObj1,std::vector<Team> & teamV,std::ifstream & in_str,std::ofstream & out_str);
void updatePlayerGoal(Player & playerObj1,std::vector<Player> & playerV,std::ifstream & in_str,std::ofstream & out_str);
void updatePlayerPenalty(Player & playerObj1,std::vector<Player> & playerV,std::ifstream & in_str,std::ofstream & out_str);
void updatePlayerAssists(Player & playerObj1,std::vector<Player> & playerV,std::ifstream & in_str,std::ofstream & out_str);

int main(int argc, char* argv[]){		//Main function 
	if(argc != 3){
		std::cerr << "Usage:\n "<<argv[0]<<"\n";
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

	std::string wordcheck;
	std::string teamx;
	std::string team1;
	std::string team2;				//declarations of variables used in the program
	std::string word;
	std::string playerx;
	std::string playery;
	std::string playerz;
	std::string wordgoal;

	
	
	std::string goalpenalty;
	std::vector<Team> teamV;
	std::vector<Player> playerV;
	Team teamObj1;
	Team teamObj2;
	Team teamObj3;

	Player playerObj1;
	Player playerObj2;
	Player playerObj3;
	Player playerObj4;
		while(in_str >> wordcheck)//Going into the string
		{

			

			//std::cout<<"*"<<wordcheck<<"*"<<std::endl;
			if(wordcheck=="Monday," || wordcheck=="Tuesday," || wordcheck=="Wednesday," || wordcheck=="Thursday," || wordcheck=="Friday," || wordcheck=="Saturday," || wordcheck=="Sunday,")	
			{																// it will check if it is monday or tuesday or any day of week
				in_str>>word;
				in_str>>word;
				in_str>>word;
				in_str>>team1;//team 1
				teamObj1.setTeamName(team1);	
				updateTeam(teamObj1,teamV,in_str,out_str);
				
				in_str>>word;//at
				in_str>>team2; //team2
				teamObj2.setTeamName(team2);
				updateTeam(teamObj2,teamV,in_str,out_str);
				

			}
//============================================
//==========================================			
			if(wordcheck=="PERIOD")				// it si check for PERIOD keyword
			{
				in_str>>word;

			}
			
//===========================================			
			for(unsigned int a=0;a<wordcheck.length();a++)		// It will look for : so that as we know that : means time
			{
				if(wordcheck[a]==':')	//  the data of penalty and goal
					{
						
							in_str>>teamx;
							
							in_str>>goalpenalty;
							//--------Check of whether it is a goal or penalty
							if(teamx==team1)
							{
									if(goalpenalty=="goal"){			// Team 1 has scored a goal 
										
										teamObj1.setTeamName(teamx);
										teamObj1.setGoals();
										updateTeamGoal(teamObj1,teamV,in_str,out_str);
										in_str>>playerx;
										playerObj1.setPlayerName(playerx);
										playerObj1.setGoals();
										updatePlayerGoal(playerObj1,playerV,in_str, out_str);
										in_str>>word;
										if(word=="(")   						 // To check whether somebody has assisted in the goal or not.
										{
											in_str>>playery;
											playerObj2.setPlayerName(playery);
											playerObj2.setAssists();
											updatePlayerAssists(playerObj2,playerV,in_str, out_str);								
											in_str>>word;
											if(word==")")
											{
																							//only one player assited in goal
											}
											else{

												playerz=word;								// two player assited in goal
												playerObj3.setPlayerName(playerz);
												playerObj3.setAssists();
												updatePlayerAssists(playerObj3,playerV,in_str, out_str);		
												in_str>>word;
											}
										}
										else
										{
																								//No player assisted in goal
										}
										

									}
									else if(goalpenalty=="penalty"){							// they made a penalty so 
																								// it should count towards both 
																								// team and player
										in_str>>playerx;

										teamObj1.setTeamName(teamx);
										playerObj4.setPlayerName(playerx);
										playerObj4.setPenalities();
										updatePlayerPenalty(playerObj4,playerV,in_str, out_str);
										teamObj1.setPenalities();
										updateTeamPenalty(teamObj1,teamV,in_str,out_str);
										in_str>>word;
										in_str>>word;
									}	
							}	//team object check loop
					
							if(teamx==team2)			// Team 2
							{
									if(goalpenalty=="goal"){								// team 2 scored a goal
										
										teamObj2.setTeamName(teamx);
										teamObj2.setGoals();
										updateTeamGoal(teamObj2,teamV,in_str,out_str);
										in_str>>playerx;
										playerObj1.setPlayerName(playerx);
										playerObj1.setGoals();
										updatePlayerGoal(playerObj1,playerV,in_str, out_str);
										in_str>>word;
										if(word=="(")										// this will check whether somebody has assited ina  goal or not
										{
											in_str>>playery;
											playerObj2.setPlayerName(playery);
											playerObj2.setAssists();
											updatePlayerAssists(playerObj2,playerV,in_str, out_str);								
											in_str>>word;
											if(word==")")
											{
												//only one player assited in goal
											}
											else{

												playerz=word;// two player assited in goal
												playerObj3.setPlayerName(playerz);
												playerObj3.setAssists();
												updatePlayerAssists(playerObj3,playerV,in_str, out_str);		
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
										teamObj2.setTeamName(teamx);
										playerObj4.setPlayerName(playerx);
										playerObj4.setPenalities();
										updatePlayerPenalty(playerObj4,playerV,in_str, out_str);
										teamObj2.setPenalities();
										updateTeamPenalty(teamObj1,teamV,in_str,out_str);
										in_str>>word;
										in_str>>word;
									}	
							}	//team object check loop


				

				//--------End of whether it is a goal or penlty
					

					}
				else
					{

					}
				

	}

//=====================================

			

//===========================================			
			if(wordcheck=="Overtime") {

			}

//============================================			
			if(wordcheck=="FINAL"){								// if the keyword is final, then it must go into this loop
				in_str>>team1;
				in_str>>wordgoal;
				unsigned int valuex = atoi(wordgoal.c_str()); 

				in_str>>team2;
				in_str>>wordgoal;	
				unsigned int valuey = atoi(wordgoal.c_str());
				if(valuex>valuey){
					teamObj1.setWin();
				}
				else{
					teamObj2.setWin();
				}
				std::cout<<team1<<" "<<valuex<<std::endl;
				std::cout<<team2<<" "<<valuey<<std::endl;


			}
//============================================			
		}	
std::cout<<teamObj1.getTeamName()<<std::endl;
std::cout<<teamObj1.getGoals()<<std::endl;
std::cout<<teamObj1.getPenalities()<<std::endl;
std::cout<<teamObj1.getWin()<<std::endl;
std::cout<<teamObj1.getLoss()<<std::endl;
std::cout<<teamObj1.getTie()<<std::endl;

std::cout<<playerObj1.getTeam()<<std::endl;
std::cout<<playerObj1.getGoals()<<std::endl;
std::cout<<playerObj1.getPenalities()<<std::endl;
std::cout<<playerObj1.getPlayerName()<<std::endl;
std::cout<<playerObj1.getAssists()<<std::endl;



printTeamStats(teamV,in_str,out_str);
printPlayerStats(playerV,in_str,out_str);

}


//  ----------------------Declaration of print functions starts here

void printTeamStats(std::vector<Team> & teamV,std::ifstream & in_str,std::ofstream & out_str){	//Printing Team Stats using setw and setleft and set right function
																								//we need to write a loop for the whole vector and print it
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
			<<std::setw(10)<<teamV[d].getPenalities()
			<<std::endl;


		}
		out_str<<teamV.size();
	}


	void printPlayerStats(std::vector<Player> & playerV,std::ifstream & in_str,std::ofstream & out_str){
			
	 out_str<<std::setw(20)<<std::left<<"Player Name"<<std::setw(20)<<"Team"
			<<std::right														//------------------------------------------------------
			<<std::setw(10)<<"Goals"											//
			<<std::setw(10)<<"Assists"											////  Printing Player Stats using setw and setleft and set right function
																				//    we need to write a loop for the whole vector and print it
			<<std::setw(10)<<"Penalties"<<std::endl;							//	  First it writes the player name,goals, assists, Penalties
																				//	
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
			void updateTeam(Team & teamObj1,std::vector<Team> & teamV,std::ifstream & in_str,std::ofstream & out_str){	
				for(unsigned int h=0;h<teamV.size();h++)
				{
					if(teamObj1.getTeamName()==teamV[h].getTeamName()){			//------------------------------------------------------------------------
																				// This function will update the team name if it is not there .
																				// And will update it onto the vector the updated version
					}															//
																				//-----------------------------------------------------------------
					else{

						teamV.push_back(teamObj1);

						}

				}
			}	

//Team Update when adding goal
			void updateTeamGoal(Team & teamObj1,std::vector<Team> & teamV,std::ifstream & in_str,std::ofstream & out_str){	
				for(unsigned int h=0;h<teamV.size();h++)
				{
					if(teamObj1.getTeamName()==teamV[h].getTeamName()){			//-----------------------------------------------------------------------
						//tempTeam=teamV[h];									//	This function will update the team goal and will check whether that 
						teamV[h].setGoals();									//	the entry of team is there or not. If it is not there, 
																				//
						//teamV.push_back(teamV[h]);							//
																				//---------------------------------------------------------------------------

					}
					else{

						teamV.push_back(teamObj1);

						}

				}
			}	
	//Team update when adding penalty
				void updateTeamPenalty(Team & teamObj1,std::vector<Team> & teamV,std::ifstream & in_str,std::ofstream & out_str){
					for(unsigned int h=0;h<teamV.size();h++)
					{																//------------------------------------------------------------------------
						if(teamObj1.getTeamName()==teamV[h].getTeamName()){			//	This function will update team penalty
																					// and will see if the team exists or not 
							teamV[h].setPenalities();								//
																					//
																					//-----------------------------------------------------------------------
						}
						else{

							teamV.push_back(teamObj1);
							}

					}
				}	
	//Player update when adding goal 		
				void updatePlayerGoal(Player & playerObj1,std::vector<Player> & playerV,std::ifstream & in_str,std::ofstream & out_str){
					
					for(unsigned int j=0;j<playerV.size();j++)
					{																	//----------------------------------------------------------
																						// This function works on player vector and will update the playr 
						if(playerObj1.getPlayerName()==playerV[j].getPlayerName()){		//vector if the player object is not ib the database
							//tempTeam=teamV[h];										//
							playerV[j].setGoals();										//
							//playerV.push_back(playerV[j]);							//---------------------------------------------------------------

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
						if(playerObj1.getPlayerName()==playerV[j].getPlayerName()){		//------------------------------------------------------------------
							//tempTeam=teamV[h];										//	This function will update player penlty and will 
							playerV[j].setPenalities();									//  check if the player is available or not.
						//	playerV.push_back(playerV[j]);								//
																						//---------------------------------------------------------------------
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
							playerV[j].setAssists();									//---------------------------------------------------------------------
																						//This function will update player assists and will check if the player
																						// is there or not. If the player is not there , it adds the new player.
						}																//
																						//-----------------------------------------------------------------------
						else{

							playerV.push_back(playerObj1);
							}
					}
				}
		//---------------------------------------------


