//Matthew Michael Sherlin
//CS3 Lab 2
//2/5/2021

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "WordList.hpp"

using std::string; 

int main(int argc, char *argv[]) {
  
  if (argc != 2) {
    std::cout << "Please include a single text file!" << std::endl;
    return 0;
  }
  
  string input = argv[1];
  std::ifstream stream(input);
  
  WordList list;
  string word;
  
  while (stream >> word) { 		                    //reads until empty
    string edit;
    for (int i = 0; i < word.size(); ++i) {       
      char tmp = word[i];
	      if (isalnum(tmp)) {                       //check if char is alphanumeric
	      edit.append(sizeof(tmp), tmp);            //if so, add to temp, otherwise leave
	      }
    }
    list.addWord(edit);                           //add word created from chars
  }
  list.print();
  stream.close();
}