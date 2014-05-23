// -----------------------------------------------------------------
// HOMEWORK 7 WORD FREQUENCY MAPS
//
// You may use all of, some of, or none of the provided code below.
// You may edit it as you like (provided you follow the homework
// instructions).
// -----------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <cstdlib>
#include <cassert>
#include "MersenneTwister.h"


// ASSIGNMENT: FILL IN YOUR OWN MAP STRUCTURE
typedef  std::map<std::string,std::map<std::string,int> >  MY_MAP;
typedef std::map<std::string,int> S_MAP;
typedef  std::map <std::string,std::map<std::string,std::map<std::string,int> > > T_MAP;

// Custom helper function that reads the input stream looking for
// double quotes (a special case delimiter needed below), and white
// space.  Contiguous blocks of alphabetic characters are lowercased &
// packed into the word.
bool ReadNextWord(std::istream &istr, std::string &word) {
  char c;
  word.clear();
  while (istr) {
    // just "peek" at the next character in the stream
    c = istr.peek();
    if (isspace(c)) {
      // skip whitespace before a word starts
      istr.get(c);
      if (word != "") {
	// break words at whitespace
	return true;
      }
    } else if (c == '"') {
      // double quotes are a delimiter and a special "word"
      if (word == "") {
	istr.get(c);
	word.push_back(c);
      }
      return true;
    } else if (isalpha(c)) {
      // this a an alphabetic word character
      istr.get(c);
      word.push_back(tolower(c));
    } else {
      // ignore this character (probably punctuation)
      istr.get(c);
    }
  }
  return false;
}


// Custom helper function that reads the input stream looking a
// sequence of words inside a pair of double quotes.  The words are
// separated by white space, but the double quotes might not have
// space between them and the neighboring word.  Punctuation is
// ignored and words are lowercased.
std::vector<std::string> ReadQuotedWords(std::istream &istr) {
  // returns a vector of strings of the different words
  std::vector<std::string> answer;
  std::string word;
  bool open_quote = false;
  while (ReadNextWord(istr,word)) {
    if (word == "\"") {
      if (open_quote == false) { open_quote=true; }
      else { break; }
    } else {
      // add each word to the vector
      answer.push_back(word);
    }
  }
  return answer;
}



// Loads the sample text from the file, storing it in the map data
// structure Window specifies the width of the context (>= 2) of the
// sequencing stored in the map.  parse_method is a placeholder for
// optional extra credit extensions that use punctuation.
void LoadSampleText(MY_MAP &data, const std::string &filename, int window, const std::string &parse_method,std::map<std::string,int> &count_map) {
  // open the file stream
  std::ifstream istr(filename.c_str());
  if (!istr) { 
    std::cerr << "ERROR cannot open file: " << filename << std::endl; 
    exit(1);
  } 
  // verify the window parameter is appropriate
  if (window < 2) {
    std::cerr << "ERROR window size must be >= 2:" << window << std::endl;
  }
  // verify that the parse method is appropriate
  bool ignore_punctuation = false;
  if (parse_method == "ignore_punctuation") {
    ignore_punctuation = true;
  } else {
    std::cerr << "ERROR unknown parse method: " << parse_method << std::endl;
    exit(1);
  }



  //
  // ASSIGNMENT:SETUP YOUR MAP DATA AS NEEDED
  //
  std::string word;
  MY_MAP::const_iterator it;
  std::string prev=" ";
  
  while (ReadNextWord(istr,word)) {
    // skip the quotation marks (not used for this part)
    if (word == "\"") continue;
    
    S_MAP &s_map=data[word];

    int &count=count_map[word];
    count++;
    if(prev==" "){ 
      prev=word;
      continue;
    }

    S_MAP &s_map1=data[prev];
    int &x=s_map1[word];
    x++;
    
    prev=word;

     
      


    //
    // ASSIGNMENT: PROCESS ALL THE NON PUNCTUATION WORDS
    // INSERTING THESE WORDS INTO THE DATA STRUCTURE
    //


  }

}
void LoadSampleText3(T_MAP &data1,const std::string &filename, int window, const std::string &parse_method,std::map<std::string,int> &count_map){

  // open the file stream
  std::ifstream istr(filename.c_str());
  if (!istr) { 
    std::cerr << "ERROR cannot open file: " << filename << std::endl; 
    exit(1);
  } 
  // verify the window parameter is appropriate
  if (window < 2) {
    std::cerr << "ERROR window size must be >= 2:" << window << std::endl;
  }
  // verify that the parse method is appropriate
  bool ignore_punctuation = false;
  if (parse_method == "ignore_punctuation") {
    ignore_punctuation = true;
  } else {
    std::cerr << "ERROR unknown parse method: " << parse_method << std::endl;
    exit(1);
  }
  std::string word;
  T_MAP::const_iterator it;
  std::string prev1=" "; // first
  std::string prev2=" "; //second
  
  while (ReadNextWord(istr,word)) {
    // skip the quotation marks (not used for this part)
    if (word == "\"") continue;
    
    int &count=count_map[word];  //Count the number of elements for each element
    count++;
    MY_MAP &w_map=data1[word];
    
    if(prev1==" "){
      prev1=word;
      continue;
    }
    S_MAP &s_map=w_map[word];
    
    
    if(prev2==" "){ 
      prev2=word;
      continue;
    }
    S_MAP &s_map1=w_map[prev2];
    int &x=s_map1[word];
    x++;
    
    
    prev2=prev1;
    prev1=word;

    //
    // ASSIGNMENT: PROCESS ALL THE NON PUNCTUATION WORDS
    // INSERTING THESE WORDS INTO THE DATA STRUCTURE
    //


  }


}


int main () {

  // ASSIGNMENT: THE MAIN DATA STRUCTURE
  
  std::map<std::string,int> count_map;
  // Parse each command
  std::string command;  
  int window;  
  MY_MAP data;
              T_MAP data1; 
  while (std::cin >> command) {

    // load the sample text file
            if (command == "load") {
              std::string filename;
              
              std::string parse_method;
              std::cin >> filename >> window >> parse_method;  
              
              if(window==2){  
              LoadSampleText(data,filename,window,parse_method,count_map);

              }
              else if(window==3){
               
              LoadSampleText3(data1,filename,window,parse_method,count_map);  
              }
              std::cout<<"Loaded "<< filename << " with window = "<< window<<" and parse method = "<<parse_method<<std::endl<<std::endl;
            } 

            // print the portion of the map structure with the choices for the
            // next word given a particular sequence.
    else if (command == "print") {
          std::vector<std::string> sentence = ReadQuotedWords(std::cin);
          int size=sentence.size();

          int a=0;
          if(window==2){
                            S_MAP s_map = data[sentence[size-1]];
                            a=count_map[sentence[size-1]];
                            std::cout<<sentence[size-1]<< " (" 
                                        << a << ")" <<std::endl;;
                            
                            for (S_MAP::iterator ii = s_map.begin(); ii != s_map.end(); ++ii) 
                            {
                              std::cout << "" 
                                        << sentence[size-1]
                                        << " " 
                                        << ii->first
                                        << " (" 
                                        << ii->second << ")" <<std::endl;
                                      
                            }
                            std::cout<<std::endl;


                      }
          if(window==3){

                           
                            MY_MAP print_map=data1[sentence[0]];
                            int a=count_map[sentence[0]];
                            if(sentence.size()==1){
                              std::cout<<sentence[0]<< " (" 
                                        << a << ")" <<std::endl;
                            

                              for (MY_MAP::iterator ii = print_map.begin(); ii != print_map.end(); ++ii) 
                              {
                              std::string m=ii->first;
                              S_MAP c=ii->second;
                              int d=0;
                              for (S_MAP::iterator ii = c.begin(); ii != c.end(); ++ii) {
                                d=d+ii->second;
                              }

                              std::cout<<sentence[0]<< " "<<m<<" ("<<d<< ") "<<std::endl;
                            }
                            }
                            else if(sentence.size()==2){
                              std::cout<<sentence[0]<<" "<<sentence[1];
                              S_MAP s_map=print_map[sentence[1]];
                              for (S_MAP::iterator ii = s_map.begin(); ii != s_map.end(); ++ii) {
                                
                                std::string b=ii->first;
                                std::cout<<b<<std::endl;
                                }
                            }
                            S_MAP s_map = data[sentence[size-1]];
                            
                            std::cout<<sentence[size-1]<< " (" 
                                        << a << ")" <<std::endl;;
                            
                            for (S_MAP::iterator ii = s_map.begin(); ii != s_map.end(); ++ii) 
                            {
                              std::cout << "" 
                                        << sentence[size-1]
                                        << " " 
                                        << ii->first
                                        << " (" 
                                        << ii->second << ")" <<std::endl;
                                      
                            }
                            std::cout<<std::endl;
          }
          
      
    }

    // generate the specified number of words 
    else if (command == "generate") {
      std::vector<std::string> sentence = ReadQuotedWords(std::cin);
      // how many additional words to generate
      int length;
      std::cin >> length;
      std::string selection_method;
      std::cin >> selection_method;
      bool random_flag;
      if(window==2){
                         if (selection_method == "random") {
                       random_flag = true;
                      } 
                      else {
                         assert (selection_method == "most_common");
                  
                       while(length>0){
                        int size=sentence.size();
                        S_MAP d=data[sentence[size-1]];
                        int largest=0;
                        std::string a="";
                        for (S_MAP::iterator ii = d.begin(); ii != d.end(); ++ii) {
                          if(ii->second >=largest){
                            largest=ii->second;

                          }
                        }
                        for (S_MAP::iterator ii = d.begin(); ii != d.end(); ++ii) {
                          if(ii->second==largest)
                          {
                             
                             a=ii->first;
                             break;
                          }
                        }
                    length=length-1;   
                    sentence.push_back(a);

                  }
                      for(int i=0; i<sentence.size();i++){
                        std::cout<<sentence[i]<<" ";
                      }
                      std::cout<<""<<std::endl<<std::endl;
                        random_flag = false;
                          
                            }



      }
      else if(window==3){

      }
     

    } else if (command == "quit") {
      break;
    } else {
      std::cout << "WARNING: Unknown command: " << command << std::endl;
    }
  }
}
