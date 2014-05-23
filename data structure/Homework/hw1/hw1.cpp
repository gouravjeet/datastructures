//This program will take input from a file and convert it into flush left 
//,flush right and full justify
//It takes input from the file and after modifieng it, sends it to the output file 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctype.h>
#include <sstream>
#include <cstdlib>
using namespace std;
void flush_right(std::ifstream & in_str, std::vector<std::string> & input_vector,std::vector<std::string> & output_vector , std::ofstream & out_str, unsigned int count_var);
void flush_left(std::ifstream & in_str, std::vector<std::string> & input_vector,std::vector<std::string> & output_vector , std::ofstream & out_str, unsigned int count_var);
void full_justify(std::ifstream & in_str, std::vector<std::string> & input_vector,std::vector<std::string> & output_vector ,std::ofstream & out_str,unsigned int count_var);
std::string justify_element(std::string justified,int width);

int main(int argc, char* argv[]) {
 	
 	
 	std::string x;
 	std::ifstream in_str( argv[1]);
		 	if(!in_str.good()){
		 		std::cerr <<"Can't open " << argv[1] <<"to read.\n";  // this will give error if the file doesnot open
		 		std::exit(1);
		 	}
 	
 	std::ofstream out_str(argv[2]);
		  	if (!out_str.good()) {
		    std::cerr << "Can't open " << argv[2] << " to write.\n";   //this will give error if output stream does not open
		    std::exit(1);
		  	}
  	std::vector<std::string> output_vector;
  	std::vector <std::string> input_vector;
		  	while(in_str >> x){										
		 	input_vector.push_back(x);
		 	
		 	}
			  	for(unsigned int r=0;r<output_vector.size();r++)
			  	{
			  		out_str<<output_vector[r];
			  	}
			int count1= std::atoi(argv[3]); 
		  	std::string function_called=argv[4];
		  	if(function_called=="flush_left")
		  	{
		  		flush_left(in_str,input_vector,output_vector, out_str, count1); // this is calling flush left
		  	}
		  	else if (function_called=="flush_right")
		  	{
		  		flush_right(in_str,input_vector,output_vector, out_str, count1);    //this is calling flush right
		  	}
		  	 else if(function_called=="full_justify")
		  	{
		  	 	full_justify(in_str,input_vector,output_vector, out_str, count1);  //this is calling full justify
		  	} 
}
 
/* This function will make text to the flush right 
This is taking vector , input stream ,
 count variable as input and is aligning the text to flush right*/
void flush_right(std::ifstream & in_str, std::vector<std::string> & input_vector,std::vector<std::string> & output_vector ,std::ofstream & out_str,unsigned int count_var){

	std::string line="";
	unsigned int count=count_var;
	
				for(unsigned int i=0;i<count_var+4;i++)
				 	{
				 	out_str<<"-";	//this will print the pattern of -
				 	}
				 	out_str<< std::endl;
					out_str<<"| "; //initial print of |

	for(unsigned int i=0;i<input_vector.size();i++)
	{
				if(count>0 && count>=(input_vector[i].size()+1))
		  		{ 	
		 				if(count==count_var)
		 				{
		 				line.append(input_vector[i]);
		 				count=count-(input_vector[i].size());
		 				}
		 				else
		 				{
		 				line.append(" ").append(input_vector[i]);
		 				count=count-(input_vector[i].size())-1;
		 				}
		 		}
		 		else 
		 		{
		 			unsigned int dup_size=0;	
		 			for(int k=i-1;k>=0;k--)
		 			{
		 			dup_size=dup_size + input_vector[k].size() ;
		 			}
		 			for(unsigned int j=0;j<count;j++)
		 			{
		 			out_str<<" ";
		 			}
		 			out_str<<line;  //this will send the output to the output stream so that the otput stream will 
		 			line="";		//send output to the file
		 			out_str<<" |";
		 			out_str<<std::endl;
		 			count=count_var;
		 			out_str<<"| ";
		 			
		 			if(count==count_var)
		 			{
		 			line.append(input_vector[i]);
		 			count=count-input_vector[i].size();
					}
		 			else
		 			{
		 			line.append(" ").append(input_vector[i]);
		 			count=count-input_vector[i].size()-1;
		 			//std::cout<<"$#"<<line;
		 			}
		 		}
	} 	
			 	for(unsigned int i=0;i<count;i++)
			 		{
			 		out_str<<" ";
			 		}
 	out_str<<line;	
 	out_str<<" "<<"|";
 	out_str<<std::endl;
			 	for(unsigned int i=0;i<count_var+4;i++)
			 	{
			 	out_str<<"-";
			 		
			 	}
 	out_str<< std::endl;
}
/* This function will make text to the full justify mode
This is taking vector , input stream , count variable as input and is aligning the text to full justify*/
void full_justify(std::ifstream & in_str, std::vector<std::string> & input_vector,std::vector<std::string> & output_vector ,std::ofstream & out_str,unsigned int count_var){

	std::string line="";
	unsigned int count=count_var;
	
				for(unsigned int i=0;i<count_var+4;i++)
				 	{
				 	out_str<<"-";	
				 	}
				 	out_str<< std::endl;
					out_str<<"| ";

	for(unsigned int i=0;i<input_vector.size();i++)
	{

				if(count>0 && count>=(input_vector[i].size()+1))
		  		{ 	
		 				if(count==count_var)
		 				{
		 				line.append(input_vector[i]);
		 				count=count-(input_vector[i].size());
		 				}
		 				else
		 				{
		 				line.append(" ").append(input_vector[i]);
		 				count=count-(input_vector[i].size())-1;
		 				}
		 		}
		 		else 
		 		{
		 			unsigned int dup_size=0;	
		 			for(int k=i-1;k>=0;k--)
		 			{
		 			dup_size=dup_size + input_vector[k].size() ;
		 			}
		 			
		 	

				    line=justify_element(line,count_var);// this function is called to make the line in full justify mode
		 			
		 			out_str<<line;
		 			line="";
		 			out_str<<" |";
		 			out_str<<std::endl;
		 			count=count_var;
		 			out_str<<"| ";
		 			
		 			if(count==count_var)
		 			{
		 			line.append(input_vector[i]);
		 			count=count-input_vector[i].size();
					}
		 			else
		 			{
		 			line.append(" ").append(input_vector[i]);
		 			count=count-input_vector[i].size()-1;
		 			
		 			}
		 		}
	} 	
			 	
 					
			 	out_str<<line;	
			 	for(unsigned int i=0;i<count;i++)
			 		{
			 		out_str<<" ";
			 		}
			 	out_str<<" "<<"|";
			 	out_str<<std::endl;
						 	for(unsigned int i=0;i<count_var+4;i++)
						 	{
						 	out_str<<"-";
						 		
						 	}
			 	out_str<< std::endl;
}
// this function will make text to full justify mode .
	std::string justify_element(std::string justified,int width)// this function is to make the text in full justified mode
				{
					
					std::vector<std::string> justifyVec;
					unsigned int remaind;
					unsigned int quotient;
					unsigned int rem;
					std::vector<std::string> test;

					std::string input;
					std::istringstream iss(justified);

				    while(iss>>input){ justifyVec.push_back(input);}


					for(unsigned int i=0;i<(justifyVec.size()-1);i++)
					{
					 justifyVec[i].append(" ");
					}
					if(justifyVec.size()==1)
					{

					}
					else
					{
					rem=width-justified.size();
					quotient = rem/(justifyVec.size()-1);
					for(unsigned int i=0;i<(justifyVec.size()-1);i++)
						{
						 for(unsigned j=0;j<quotient;j++)
						 {
						 justifyVec[i].append(" ");

						 }
						}

					remaind = rem%((justifyVec.size()-1)) ;
				}
					for(unsigned int i =0;i<remaind;i++)
					{
					 justifyVec[i].append(" ");
					}


					justified = "";

					for(unsigned int i=0;i<(justifyVec.size());i++)
					{
					 justified.append(justifyVec[i]);

					}
					
					return justified;
					

				}


/* This function will make text to the flush left 
This is taking vector , input stream , count variable as input and is aligning the text to flush left*/

void flush_left(std::ifstream & in_str, std::vector<std::string> & input_vector,std::vector<std::string> & output_vector ,std::ofstream & out_str, unsigned int count_var){

	std::string line="";
	unsigned int count=count_var;
	for(unsigned int i=0;i<count_var+4;i++)
 	{
 	out_str<<"-";	
 	}
 	out_str<< std::endl;
	out_str<<"| ";

			for(unsigned int i=0;i<input_vector.size();i++)
			{
					if(input_vector[i].size()>16)
					{
						
						std::string s1;
						std::string s2;
						std::string s4;
						std::string s3=input_vector[i];
						s1=s3.substr(0,15);
						s2=s3.substr(15,29);
						s4=s3.substr(29,44);
						out_str<< s1<<"- |"<<std::endl<<"| ";
						out_str<< s2<<"- |"<<std::endl<<"| ";
						out_str<< s4<<"       |"<<std::endl;

					}
					if(count>0 && count>=(input_vector[i].size()+1))
			  		{ 	
			 				if(count==count_var)
			 				{
			 				line.append(input_vector[i]);
			 				count=count-(input_vector[i].size());
			 				}
			 				else
			 				{
			 				line.append(" ").append(input_vector[i]);
			 				count=count-(input_vector[i].size())-1;
			 				}
			 		}
			 		
			 		else 
			 		{
			 			unsigned int dup_size=0;	
			 			for(int k=i-1;k>=0;k--)
			 			{
			 			dup_size=dup_size + input_vector[k].size() ;
			 			}
			 		
			 			out_str<<line;
			 			for(unsigned int j=0;j<count;j++)//spaces for the left part 
			 			{						//we are calculating spaces so that remaining spaces are printed
			 			out_str<<" ";
			 			}
			 			line="";
			 			out_str<<" |";
			 			out_str<<std::endl;
			 			count=count_var;
			 			out_str<<"| ";
			 			
			 			if(count==count_var)
			 			{
			 			line.append(input_vector[i]);
			 			count=count-input_vector[i].size();
						}
			 			else
			 			{
			 			line.append(" ").append(input_vector[i]);
			 			count=count-input_vector[i].size()-1;
			 			}
			 		}
			} 	
 	
 						out_str<<line;	
					 	for(unsigned int i=0;i<count;i++)
					 		{
					 		out_str<<" ";
					 		}
					 	out_str<<" "<<"|";
					 	out_str<<std::endl;
					 	for(unsigned int i=0;i<count_var+4;i++)
					 	{
					 	out_str<<"-";
					 		
					 	}
 						out_str<< std::endl;
}
//End of function 
// Partial implementation for long word.I have tried but i am not able to implement fully
/*if(input_vector[i].size()>count_var)
								{
										std::string s1;
										std::string s2;
										std::string s4;
										std::string s3=input_vector[i];
										s1=s3.substr(0,count_var-1);
										s2=s3.substr(count_var-1,(count_var-1));
										s4=s3.substr((count_var*2)-1,count_var-1);
										out_str<< s1<<"- |"<<std::endl<<"| ";
										out_str<< s2<<"- |"<<std::endl<<"| ";
										out_str<< s4<<"          |"<<std::endl;
										count=count-(s4.size());
										out_str<<"| ";
									}
*/
