//Singleton Design Pattern Example
//Matthew Michael Sherlin
//March 24, 2021

#include "logger.hpp"

int main(){
  Logger* log = Logger::instance();
	std::string entry;
  
  std::cout << "Enter Log Entry: ";
  std::getline(std::cin, entry);
  log->report(entry);
  log->report("\nLogging out.\n");
 
  return 0;
}